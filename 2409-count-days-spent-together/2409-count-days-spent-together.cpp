
class Solution {
public:
    int toDayOfYear(string date) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));

    int totalDays = day;
    for (int i = 0; i < month - 1; i++) {
        totalDays += daysInMonth[i];
    }
    
    return totalDays;
}
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = toDayOfYear(arriveAlice);
        int endA   = toDayOfYear(leaveAlice);
        int startB = toDayOfYear(arriveBob);
        int endB   = toDayOfYear(leaveBob);

        int startTogether = max(startA, startB);
        int endTogether   = min(endA, endB);

        int overlap = endTogether - startTogether + 1;

        if (overlap < 0) {
            return 0;
        }
        return overlap;
    }
};