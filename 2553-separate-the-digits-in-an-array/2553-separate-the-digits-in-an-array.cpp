class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i =0;i<nums.size(); i++){
            int a = nums[i];
            if(a>9){
                vector<int> temp;
                while(a>0){
                    int d = a % 10;
                    a /= 10;
                    temp.push_back(d);
                }
                reverse(temp.begin(), temp.end());
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            else{
                ans.push_back(a);
            }
        }
        return ans;
    }
};