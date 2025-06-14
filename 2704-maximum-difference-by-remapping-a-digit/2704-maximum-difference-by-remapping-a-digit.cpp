class Solution {
public:
    int minMaxDifference(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int firstNonNine = 9;
        int firstNonZero = 0;
        vector<int> digitsForMin;
        vector<int> digitsForMax;
        int temp = n;
        while (temp > 0) {
            int digit = temp % 10;
            digitsForMin.push_back(digit);
            digitsForMax.push_back(digit);
            temp /= 10;
        }
        reverse(digitsForMin.begin(), digitsForMin.end());
        reverse(digitsForMax.begin(), digitsForMax.end());
        int f1 = 0, f2 = 0;
        int minNum = 0, maxNum = 0;

        for (int i = 0; i < digitsForMin.size(); i++) {
            if (!f1 && digitsForMin[i] != 0) {
                firstNonZero = digitsForMin[i];
                f1 = 1;
            }
            if (f1) {
                if (firstNonZero == digitsForMin[i]) {
                    digitsForMin[i] = 0;
                }
            }
            minNum = minNum * 10 + digitsForMin[i];
        }
        for (int i = 0; i < digitsForMax.size(); i++) {
            if (!f2 && digitsForMax[i] != 9) {
                firstNonNine = digitsForMax[i];
                f2 = 1;
            }
            if (f2) {
                if (firstNonNine == digitsForMax[i]) {
                    digitsForMax[i] = 9;
                }
            }
            maxNum = maxNum * 10 + digitsForMax[i];
        }

        return abs(maxNum - minNum);
    }
};