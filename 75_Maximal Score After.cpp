// class Solution {
// public:
//     long long maxKelements(vector<int>& nums, int k) {
//         long long int ans = 0;
//         priority_queue<int> pq;
//         for(auto &i: nums)pq.push(i);
//         int x;
//         while(k--){
//             x = pq.top();
//             ans += x;
//             pq.pop();
//             pq.push(ceil(x/3.0));
//         }
//         return ans;
//     }
// };
