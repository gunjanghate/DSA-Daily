class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> v1;
        
        for(int num : nums) {
            if(num < pivot) v1.push_back(num);
        }
        for(int num : nums) {
            if(num == pivot) v1.push_back(num);
        }
        for(int num : nums) {
            if(num > pivot) v1.push_back(num);
        }

        
        return v1;
    }
};