class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int> ans;
        vector<int> indices;
        for (int i = 0; i < n; i++)
            if (nums[i] == key)
                indices.push_back(i);
        int n1 = indices.size();
        if (n1 == n){
            vector<int> ans1(n);
            iota(ans1.begin(), ans1.end(), 0);
            return ans1;
        }
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<n1 ; j++){
                if(abs(i-indices[j])<=k && nums[indices[j]]==key){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;    
    }
};