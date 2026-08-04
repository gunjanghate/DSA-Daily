class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());

        int n = h - l + 1;
        vector<bool> exists(n, false);

        for(int& i : nums) exists[i-l] = true;

        vector<int> ans;

        for(int i = 0; i<n; i++){
            if(!exists[i]){
                ans.push_back(i+l);
            }
        }

        return ans;
    }
};