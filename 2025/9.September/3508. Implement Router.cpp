using namespace std;

class Destination {
private:
    static const long long MULTIPLIER = 1000000LL;
    int start, end;
    vector<pair<int, int>> packets;
    unordered_set<long long> packetSet;

public:
    Destination() {
        start = -1;
        end = -1;
    }

    void addPacket(int timestamp, int source) {
        if (start == -1) {
            start = 0;
        }

        if ((int)packets.size() > end + 1) {
            packets[end + 1] = {timestamp, source};
            end++;
        } else {
            packets.push_back({timestamp, source});
            end++;
        }

        long long x = 1LL * timestamp * MULTIPLIER + source;
        packetSet.insert(x);
    }

    void removePacket() {
        long long x =
            1LL * packets[start].first * MULTIPLIER + packets[start].second;
        packetSet.erase(x);

        if (start == end) {
            start = -1;
            end = -1;
        } else {
            start++;
        }
    }

    int getCount(int startTime, int endTime) {
        if (start == -1)
            return 0;

        int lb = end + 1;
        int ub = -1;
        int tempStart = start, tempEnd = end;

        while (tempStart <= tempEnd) {
            int mid = tempStart + (tempEnd - tempStart) / 2;
            int x = packets[mid].first;
            if (x >= startTime) {
                lb = mid;
                tempEnd = mid - 1;
            } else {
                tempStart = mid + 1;
            }
        }

        tempStart = start;
        tempEnd = end;
        while (tempStart <= tempEnd) {
            int mid = tempStart + (tempEnd - tempStart) / 2;
            int x = packets[mid].first;
            if (x <= endTime) {
                ub = mid;
                tempStart = mid + 1;
            } else {
                tempEnd = mid - 1;
            }
        }

        if (lb <= ub) {
            return ub - lb + 1;
        }
        return 0;
    }

    bool contains(int timestamp, int source) {
        if (start == -1)
            return false;
        long long key = 1LL * timestamp * MULTIPLIER + source;
        return packetSet.count(key);
    }
};

class Router {
private:
    queue<vector<int>> q;
    int maxMemory;
    unordered_map<int, Destination*> destinations;

public:
    Router(int memoryLimit) { maxMemory = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        Destination* dest;
        if (destinations.find(destination) != destinations.end()) {
            dest = destinations[destination];
            if (dest->contains(timestamp, source)) {
                return false;
            }
        } else {
            dest = new Destination();
            destinations[destination] = dest;
        }

        if ((int)q.size() == maxMemory) {
            vector<int> firstPacket = q.front();
            q.pop();
            Destination* dest1 = destinations[firstPacket[1]];
            dest1->removePacket();
        }

        dest->addPacket(timestamp, source);
        q.push({source, destination, timestamp});
        return true;
    }

    vector<int> forwardPacket() {
        if (q.empty())
            return {};
        vector<int> firstPacket = q.front();
        q.pop();
        Destination* dest1 = destinations[firstPacket[1]];
        dest1->removePacket();
        return firstPacket;
    }

    int getCount(int destination, int startTime, int endTime) {
        if (destinations.find(destination) == destinations.end())
            return 0;
        return destinations[destination]->getCount(startTime, endTime);
    }
};

struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
    }
} fastio;
