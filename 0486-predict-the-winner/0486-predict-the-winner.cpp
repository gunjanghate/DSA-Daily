class Solution {
public:
    bool dfs(int left, int right, int p1, int p2, bool turn, vector<int>& nums){
        if(left > right) return p1>=p2;

        if(turn){
            return dfs(left + 1, right, p1+nums[left], p2, false, nums) || dfs(left, right-1, p1+nums[right], p2, false, nums);
        }else{
            return dfs(left + 1, right, p1, p2+nums[left], true, nums) && dfs(left, right-1, p1, p2+nums[right], true, nums);

        }
    }
    bool predictTheWinner(vector<int>& nums) {
        return dfs(0, nums.size()-1, 0, 0, true, nums);
    }
};