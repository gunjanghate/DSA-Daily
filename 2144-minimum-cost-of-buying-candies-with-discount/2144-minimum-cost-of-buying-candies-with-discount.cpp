class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), [](int a, int b){
            return a > b;
        });
        int ans  = 0;
        int k = 2;
        for(int i = 0; i<cost.size(); i++){
            if(k!=0){
                k--;
                ans+=cost[i];
            }else{
                k = 2;
            }
        }   
        return ans;
    }
};