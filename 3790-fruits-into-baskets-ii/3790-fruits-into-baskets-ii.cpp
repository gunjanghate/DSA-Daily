class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int ans = 0;
        int f = 0;
        for(int i = 0; i<fruits.size(); i++){
            f = 0;
            for(int j = 0; j<baskets.size(); j++){
                if(baskets[j]==-1) continue;
                if(fruits[i]<=baskets[j]){
                    f = 1;
                    baskets[j] = -1;
                    break;
                }
            }
            if(!f) ans++;
        }

        return ans;
    }
};