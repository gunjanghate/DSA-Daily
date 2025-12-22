class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());

        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i = l; i<=h; i++){
            if(!(binary_search(nums.begin(), nums.end(),i))){
                ans.push_back(i);
            }
        }

        return ans;
    }
};