class Solution {
public:
    int countHillValley(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> arr;
        for (int n : nums) {
            if (arr.empty() || arr.back() != n) arr.push_back(n);
        }

        int cnt = 0;
        for (int i = 1; i < arr.size() - 1; i++) {
            if ((arr[i] > arr[i-1] && arr[i] > arr[i+1]) ||
                (arr[i] < arr[i-1] && arr[i] < arr[i+1])) {
                cnt++;
            }
        }
        return cnt;
    }
};
