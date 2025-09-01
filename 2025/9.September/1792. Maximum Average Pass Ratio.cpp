class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Define a max-heap to store gains and class info
        priority_queue<pair<double, pair<int, int>>> pq;
        
        // Initialize the heap with all classes
        for (const auto& cls : classes) {
            int pass = cls[0], total = cls[1];
            double gain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({gain, {pass, total}});
        }
        
        // Distribute extra students
        while (extraStudents--) {
            auto [gain, cls] = pq.top(); pq.pop();
            int pass = cls.first, total = cls.second;
            
            // Add one extra student
            ++pass;
            ++total;
            
            // Recompute the gain and push back into the heap
            double newGain = (double)(pass + 1) / (total + 1) - (double)pass / total;
            pq.push({newGain, {pass, total}});
        }
        
        // Compute the final average pass ratio
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto [gain, cls] = pq.top(); pq.pop();
            int pass = cls.first, total = cls.second;
            totalRatio += (double)pass / total;
        }
        
        return totalRatio / classes.size();
    }
};
