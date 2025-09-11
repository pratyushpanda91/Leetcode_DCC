class Solution
{
public:
    bool checkvowels(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
    string sortVowels(string s)
    {
        string temp="";
        for (auto x : s)
        {
            if (checkvowels(x)){
                temp += x;
            }
        }
        int j = 0;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < s.size(); i++)
        {
            if (checkvowels(s[i]))
            {
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};
