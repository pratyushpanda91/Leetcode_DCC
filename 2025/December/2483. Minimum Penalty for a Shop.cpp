class Solution {
public:
    int bestClosingTime(string c) {
        int LN = 0;
        int totaly = 0;

        for(int i = 0;i<c.size();i++) {
            totaly += (c[i] == 'Y');
        }

        int Y = 0;
        int mpen = INT_MAX;
        int ans = 0;
        for(int i = 0;i<c.size();i++) {
            int RY = totaly-Y;
            int penalty = RY + LN;
            if (penalty < mpen) {
                ans = i;
                mpen = penalty;
            }
            Y += (c[i] == 'Y');
            LN += (c[i] == 'N');
        }
        int RY = totaly-Y;
        int penalty = RY + LN;
        if (penalty < mpen) {
            ans = c.size();
            mpen = penalty;
        }
        return ans;
    }
};
