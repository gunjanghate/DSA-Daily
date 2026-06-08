class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> v1, v2, v3;
        
        for(int num : nums) {
            if(num < pivot) v1.push_back(num);
            else if(num == pivot) v2.push_back(num);
            else v3.push_back(num);
        }

        v1.insert(v1.end(), v2.begin(), v2.end());
        v1.insert(v1.end(), v3.begin(), v3.end());
        
        return v1;
    }
};