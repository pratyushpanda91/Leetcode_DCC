class MyCalendarTwo {
private:
    map<int, int> pointFreq;

public:
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        pointFreq[start]++;
        pointFreq[end]--;
        if (causingTripleBooking(start, end)) return false;
        return true;
    }

private:
    bool causingTripleBooking(int start, int end) {
        int overlapCnt = 0;
        for (auto& entry : pointFreq) {
            overlapCnt += entry.second;
            if (overlapCnt > 2) {
                pointFreq[start]--;
                pointFreq[end]++;
                return true;
            }
        }
        return false;
    }
};
