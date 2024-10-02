class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        std::unordered_map<int, int> valueToRank;  
        std::vector<int> sortedUniqueNumbers = arr; 
        
        std::sort(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end());
        sortedUniqueNumbers.erase(std::unique(sortedUniqueNumbers.begin(), sortedUniqueNumbers.end()), sortedUniqueNumbers.end());
        
        for (int i = 0; i < sortedUniqueNumbers.size(); i++) {
            valueToRank[sortedUniqueNumbers[i]] = i + 1;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = valueToRank[arr[i]];
        }

        return arr;  
    }
};
