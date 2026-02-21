class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int,int> mp;

        int ans = 0;
        int i = 0, j = 0;

        while( j<fruits.size()){
             mp[fruits[j]]++;
             if(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
             }
            
            ans = max(ans, j - i + 1);
            j++;

        }

        return ans;


    }
};
