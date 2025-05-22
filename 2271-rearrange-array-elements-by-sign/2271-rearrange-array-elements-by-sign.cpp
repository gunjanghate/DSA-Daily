// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         vector<int> negs;
//         vector<int> pos;
//         vector<int> ans;
//         for (auto i : nums) {
//             if (i < 0)
//                 negs.push_back(i);
//             else
//                 pos.push_back(i);
//         }
//         int i = 0;
//         int j = 0;
//         int turn = 0;
//         while (i < pos.size() && j < negs.size()) {
//             if (turn % 2 == 0) {
//                 ans.push_back(pos[i]);
//                 i++;
//             } else {
//                 ans.push_back(negs[j]);
//                 j++;
//             }
//             turn++;
//         }
//         while(i<pos.size()){
//                 ans.push_back(pos[i]);
//                 i++;
//         }
//         while(j<negs.size()){
//                 ans.push_back(negs[j]);
//                 j++;
//         }

//         return ans;

//     }
// };
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> ans(nums.size());
        int i =0;
        int j =0;
        int k = 0;
        while(k < nums.size()){
            if(nums[k]>=0){
                ans[2*j]=nums[k];
                j++;
            }
            else{
                ans[2*i+1]=nums[k];
                i++;
            }
                k++;
        }
        return ans;
    }
};