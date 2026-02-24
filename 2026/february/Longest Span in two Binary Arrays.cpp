
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> freq;  // To store frequencies of prefix XORs
        long count = 0;               // To store the count of subarrays
        int prefixXOR = 0;            // To track the running prefix XOR

        for (int num : arr) {
            prefixXOR ^= num;         // Update prefix XOR with the current element

            // If prefix XOR itself equals k, increment the count
            if (prefixXOR == k) {
                count++;
            }

            // Check if prefixXOR ^ k exists in the frequency map
            int target = prefixXOR ^ k;
            if (freq.find(target) != freq.end()) {
                count += freq[target];  // Add the number of occurrences of the target
            }

            // Update the frequency map with the current prefix XOR
            freq[prefixXOR]++;
        }

        return count;
    }
};
