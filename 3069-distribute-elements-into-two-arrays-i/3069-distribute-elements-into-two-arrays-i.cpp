class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        int n = nums.size();

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i<n; i++){
            if(arr1.back() > arr2.back()){
                arr1.push_back(nums[i]);
            }else
                arr2.push_back(nums[i]);
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        vector<int> res = arr1;

        return res;
    }
};