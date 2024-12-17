class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0); // Frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string result = "";
        int largest = 25; // Start with 'z'
        int secondLargest = 24; // Track the next largest character
        
        while (true) {
            // Find the largest character we can use
            while (largest >= 0 && freq[largest] == 0) {
                largest--;
            }
            if (largest < 0) break; // No characters left to use
            
            // Add up to 'repeatLimit' instances of the largest character
            int use = min(repeatLimit, freq[largest]);
            result.append(use, 'a' + largest);
            freq[largest] -= use;
            
            // If we still have remaining characters of 'largest' but hit the limit
            if (freq[largest] > 0) {
                // Find the next largest character
                while (secondLargest >= 0 && (freq[secondLargest] == 0 || secondLargest == largest)) {
                    secondLargest--;
                }
                if (secondLargest < 0) break; // No valid character to break the chain
                
                // Add one occurrence of the second largest character to break the chain
                result.push_back('a' + secondLargest);
                freq[secondLargest]--;
            } else {
                // Reset secondLargest for the next iteration
                secondLargest = largest - 1;
            }
        }
        
        return result;
    }
};
