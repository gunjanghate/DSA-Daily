class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //    int pro = 0;
        // int Maxpro = 0;
        // int a = *min_element(p.begin(), p.end());
        // auto it = find(p.begin(), p.end(), a);
        // int index = distance(p.begin(), it); 
        // int b = *max_element(p.begin()+index, p.end());
        if (prices.empty()) return 0;
        
        int minPrice = prices[0]; 
        int maxProfit = 0;  
            for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
           
            else {
                maxProfit = max(maxProfit, prices[i] - minPrice);
            }
        }

        return maxProfit;     
    }
};