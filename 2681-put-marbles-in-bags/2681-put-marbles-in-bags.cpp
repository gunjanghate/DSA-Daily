class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(k==1) return 0;
        if(weights.size()==k) return 0;
        vector<long long> pairs;
        for(int i = 0; i<weights.size()-1; i++){
            pairs.push_back(weights[i]+weights[i+1]);
        }
        sort(pairs.begin(), pairs.end());
        long long mx = accumulate(pairs.begin(),pairs.begin()+(k-1),0LL);
        long long mn = accumulate(pairs.end()-(k-1),pairs.end(),0LL);
        

        return abs(mx-mn);
    }
};