class Solution {
public:
    int countDays(int days, std::vector<std::vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());

        int meetingDaysCount = 0;
        int currentStart = -1, currentEnd = -1;

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            if (start > currentEnd) {
                if (currentEnd != -1) {
                    meetingDaysCount += currentEnd - currentStart + 1;
                }
                currentStart = start;
                currentEnd = end;
            } else {
                currentEnd = std::max(currentEnd, end);
            }
        }

        if (currentEnd != -1) {
            meetingDaysCount += currentEnd - currentStart + 1;
        }

        return days - meetingDaysCount;
    }
};
