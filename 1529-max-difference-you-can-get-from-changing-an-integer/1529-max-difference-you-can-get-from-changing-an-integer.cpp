class Solution {
public:
    int maxDiff(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> digitsForMin, digitsForMax;
        int temp = n;

        while (temp > 0) {
            int digit = temp % 10;
            digitsForMin.push_back(digit);
            digitsForMax.push_back(digit);
            temp /= 10;
        }

        reverse(digitsForMin.begin(), digitsForMin.end());
        reverse(digitsForMax.begin(), digitsForMax.end());

        int firstNonNine = -1;
        for (int i = 0; i < digitsForMax.size(); i++) {
            if (digitsForMax[i] != 9) {
                firstNonNine = digitsForMax[i];
                break;
            }
        }
        if (firstNonNine != -1) {
            for (int i = 0; i < digitsForMax.size(); i++) {
                if (digitsForMax[i] == firstNonNine)
                    digitsForMax[i] = 9;
            }
        }

        int firstDigit = digitsForMin[0];
        if (firstDigit != 1) {

            for (int i = 0; i < digitsForMin.size(); i++) {
                if (digitsForMin[i] == firstDigit)
                    digitsForMin[i] = 1;
            }
        } else {
            int target = -1;
            for (int i = 1; i < digitsForMin.size(); i++) {
                if (digitsForMin[i] != 0 && digitsForMin[i] != 1) {
                     target = digitsForMin[i];
                    
                    break;
                }
            }
            if(target!=-1){
                for (int j = 0; j < digitsForMin.size(); j++) {
                        if (digitsForMin[j] == target)
                            digitsForMin[j] = 0;
                    }
            }
        }

        int minNum = 0, maxNum = 0;
        for (int digit : digitsForMin)
            minNum = minNum * 10 + digit;

        for (int digit : digitsForMax)
            maxNum = maxNum * 10 + digit;

        return abs(maxNum - minNum);
    }
};