class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // keeping track of all the mod value encountered
        vector<int> mod_freq(k, 0);
        
        for (int num : arr) {
            int rem = num%k;
            // if num is not negative then correction is not necessary
            int corrected_rem = (num % k + k) % k;

            // updating the mod frequency
            mod_freq[corrected_rem]++;
        }
        
        // check if proper divisors are perfectly forming pair
        if (mod_freq[0]&1) {return false;}
        
        for (int i = 1; i <= k / 2; i++) {
            // fullfilling the pair of remaining remainders
            int x = mod_freq[i];
            int y = mod_freq[k - i];

            // if pair count is odd, then it is not possible to form
            // n/2 unique pair from the given array
            if (x != y) {
                return false;
            }
        }

        // we good to go if no condition fails        
        return true;
    }
};
