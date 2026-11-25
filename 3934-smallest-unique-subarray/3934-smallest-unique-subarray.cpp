class Solution {
public:
    // Binary expo
    long long findPower(long long a, long long base){
        if(base==0) return 1;

        long long half = findPower(a, base/2);
        long long res = (half * half) % M;
        if(base%2==1) res = (res * a) % M;
        return res;
    }
    int M = 1e9+7;
    bool check(vector<int> &nums, int s, int base){
        int n = nums.size();

        long long hash = 0;
        unordered_map<long long, int> mp;

        long long p = findPower(base, s-1);

        int i = 0, j = 0;

        while(j<n){
            hash = (hash*base + nums[j]) % M;

            if(j-i+1 < s){
                j++;
            }else{
                mp[hash]++;

                hash = (hash - (p * nums[i])%M + M) % M;
                i++;
                j++;
            }
        }

        for(auto [it, k] : mp){
            if(k==1) return true;
        }

        return false;

    }
    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();
        int base = *max_element(nums.begin(), nums.end()) + 1;

        int l = 1;
        int r = n;

        int ans = n;

        while(l<=r){
            int mid = l + (r-l)/2;

            if(check(nums, mid, base)){
                ans = mid;
                r = mid - 1;
            }
            else l = mid+1;
        }

        return ans;
        
    }
};