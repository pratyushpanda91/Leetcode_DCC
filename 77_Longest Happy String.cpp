class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int,char>>pq;
        if (a > 0)   pq.push({a,'a'});
        if (b > 0)   pq.push({b,'b'});
        if (c > 0)   pq.push({c,'c'});
        
        string ans = "";
        while(pq.size() > 1)
        {
            int topFreq1 =  pq.top().first;
            char topChar1 = pq.top().second;
            pq.pop();
            if (topFreq1 > 1)
            {
                ans += topChar1;
                ans += topChar1;
                topFreq1 -= 2;
            }
            else
            {
                ans += topChar1;
                topFreq1 -= 1;
            }
            int topFreq2 =  pq.top().first;
            char topChar2 = pq.top().second;
            pq.pop();
			
            if (topFreq2 > 1 and topFreq2 >= topFreq1)
            {
                ans += topChar2;
                ans += topChar2;
                topFreq2 -= 2;
            }
            else
            {
                ans += topChar2;
                topFreq2 -= 1;
            }
            if (topFreq1 > 0)   pq.push({topFreq1,topChar1});
            if (topFreq2 > 0)   pq.push({topFreq2,topChar2});
        }
        
        while(!pq.empty())
        {
            int leftFreq = pq.top().first;
            char leftChar = pq.top().second;
            pq.pop();
            
            if (leftFreq > 1)
            {
                ans += leftChar;
                ans += leftChar;
                leftFreq -= 2;
            }
            else
            {
                ans += leftChar;
                leftFreq -= 1;
            }
        }
        return ans;
    }
};
