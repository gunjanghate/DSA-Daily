class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int, int> mp;
        while(n>0){
            mp[n%10]++;
            n /= 10;
        }
        int sc = 0;
        for(auto i : mp){
            sc += (i.first * i.second);
        }

        return sc;
    }
};