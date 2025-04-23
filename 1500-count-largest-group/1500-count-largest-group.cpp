class Solution {
public:
    int countLargestGroup(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int , int> mp;
        for (int i = 1; i <= n; i++) {
            int sum = 0, num = i;
            while (num != 0) {
                sum += num % 10;
                num = num / 10;
            }
            mp[sum]++;
        }
        int mx = INT_MIN;
        int cnt = 0;
        for (auto k : mp) {
            if (k.second > mx) {
                mx = k.second;
                cnt = 1;
            } else if (k.second == mx) {
                cnt++;
            }
        }
        return cnt;
    }
};
