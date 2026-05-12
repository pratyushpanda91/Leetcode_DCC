class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {

        auto lamda = [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        };

        sort(tasks.begin(), tasks.end(), lamda);

        long long ans = 0;
        long long energy = 0;

        for (int i = 0; i < tasks.size(); i++) {

            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if (energy < minimum) {
                ans += (minimum - energy);
                energy = minimum;
            }

            energy -= actual;
        }

        return (int)ans;
    }
};
