class Solution {
private:
    void countSort(vector<int>& arr) {
        if (arr.empty())
            return;
        int maxVal = *max_element(arr.begin(), arr.end());
        vector<int> count(maxVal + 1, 0);
        for (int num : arr) {
            count[num]++;
        }
        int index = 0;
        for (int i = 0; i <= maxVal; i++) {
            while (count[i]-- > 0) {
                arr[index++] = i;
            }
        }
    }

public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // sort(nums.begin(), nums.end()); //NLogN
        countSort(nums);
        // 1 1 3 3 4 5 7 8 9
        // 2 2 2 2 4 5
        // 2 2 2 4 5 5 5 5 7 7 8 8 9 9 10 11 12 12
        vector<vector<int>> ans;
        vector<int> arrs;
        for (int i = 0; i < nums.size() - 2; i += 3) {

            if (abs(nums[i] - nums[i + 1]) <= k &&
                abs(nums[i] - nums[i + 2]) <= k &&
                abs(nums[i + 1] - nums[i + 2]) <= k) {
                arrs.push_back(nums[i]);
                arrs.push_back(nums[i + 1]);
                arrs.push_back(nums[i + 2]);
                ans.push_back(arrs);
                arrs.clear();
            } else {
                ans.clear();
                break;
            }
        }

        return ans;
    }
};