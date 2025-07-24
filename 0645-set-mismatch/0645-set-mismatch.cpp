class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int a = 0, b = 0;
        map<int,int> mp;
        for(auto i : nums) mp[i]++;
        // finding missing in array
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(i+1)==mp.end()){
                b = i+1;
                break;
            }
        }
        // finding element with duplicate
        for(auto [i,k] : mp){
            if(k>1){
                a = i;
                break;
            }
        }

        return {a,b};        
    }
};