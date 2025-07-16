class Solution {
public:
    int maximumLength(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        if(n==2) return 2;
        int c1 = 0, c2 = 0, eve = 0, odd = 0;
        for(auto i: nums){
            if(i%2==0){
                c1++;
                eve = max(eve, odd+1);
            }else{
                c2++;
                odd = max(odd, eve+1);
            }
        }

        return max({c1, c2, eve, odd});

    }
};