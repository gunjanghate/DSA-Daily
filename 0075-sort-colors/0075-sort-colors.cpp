class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Dutch National Flag Algorithm
        int n = nums.size();
        int i=0, k=0, j = n-1;
        while(j>=k && j>=i){
          if(nums[k]==2){
            swap(nums[k], nums[j]);
            j--;

          }
          else if(nums[k]==1){
            k++;

          }
          else if(nums[k]==0){
            swap(nums[k], nums[i]);
            i++;
            k++;
          }
        }
    }

};