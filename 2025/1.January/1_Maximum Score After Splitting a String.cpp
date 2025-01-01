class Solution
{
public:
  int maxScore(string s)
  {
    int total_ones = 0;
    for (char c : s)
    {
      if (c == '1')
        total_ones++;
    }

    int left_zeros = 0, right_ones = total_ones;
    int max_score = 0;

    // Iterate through the string, excluding the last character
    for (int i = 0; i < s.size() - 1; ++i)
    {
      if (s[i] == '0')
      {
        left_zeros++;
      }
      else
      {
        right_ones--;
      }

      // Calculate the current score
      max_score = max(max_score, left_zeros + right_ones);
    }

    return max_score;
  }
};