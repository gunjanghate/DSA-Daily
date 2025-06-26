class Solution {
public:
    int thirdMax(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int fstmx = *max_element(nums.begin(), nums.end());
        int secmx = INT_MIN;
        for(auto i :nums){
            if(fstmx !=i && i>=secmx){
                secmx = i;
            }
        }
        int thrdmx = INT_MIN;
        int f = 0;
        for(auto i :nums){
            if(secmx !=i && fstmx!=i && i>=thrdmx){
                thrdmx = i;
                f = 1;
            }
        }
        if(!f)
            thrdmx = fstmx;

        return thrdmx;

    }
};