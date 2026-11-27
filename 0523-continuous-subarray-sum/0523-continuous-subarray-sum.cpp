class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = -1;
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            // if there exists rem already in map it means we have got sum that is divisible by k
            // for eg. 23 % 6 = 5
            // and 23 + 2 + 4 % 6 = 5
            // so we can see 2, 4 is the the subarray with sum 6 gives % 6 as 0 and beacuse adding it to 23 + 2 + 4 gave mod which we find at 23 % 6 maintaing that in map helped us to return true that there exist a good subarray 
            int rem = sum % k;
            cout<<"rem "<<rem<<"at i ="<<i<<endl;


            if(mp.find(rem)!=mp.end()){
                if(i - mp[rem] >= 2){
                    return true;
                }
            }else mp[rem] = i;

        }

        return false;
    }
};