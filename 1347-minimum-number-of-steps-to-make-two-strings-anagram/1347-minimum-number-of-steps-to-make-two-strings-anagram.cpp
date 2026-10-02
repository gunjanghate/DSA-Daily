class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : t) {
            freq[c - 'a']--;
        }

        int ans = 0;

        for (int x : freq) {
            if (x > 0) {
                ans += x;
            }
        }

        return ans;
    } // a - 1    a - 2
      // b - 2    b - 1

    // l - 1   p - 1   l - 0
    // e - 3   r - 1   e - 1
    // t - 1   a - 1   t - 1
    // c - 1   c - 2   c - 2
    // o - 1   t - 1   o - 0
    // d - 1   i - 1   d - 0
}; //         e - 1