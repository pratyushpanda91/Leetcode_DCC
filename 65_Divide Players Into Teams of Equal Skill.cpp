class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if(skill.size() == 2) return skill[0]*skill[1];
        sort(skill.begin(), skill.end());
        long long i = 0, j = skill.size()-1;
        long long sum = skill[i]+skill[j];
        long long product = 0;

        while(i<j){
            long long teamSum = skill[i]+skill[j];
            if(teamSum == sum){
                product += skill[i]*skill[j];
                i++;
                j--;
            }
            else{
                return -1;
            }
        }
        return product;
    }
};
