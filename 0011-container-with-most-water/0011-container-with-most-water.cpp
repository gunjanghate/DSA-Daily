class Solution {
public:
    int maxArea(vector<int>& h) {

        int ans = 0;
        int l = 0;
        int r = h.size()-1;

        while(l < r){
            int mn = min(h[l], h[r]) * (r-l);
            ans = max(mn , ans);

            if(h[l]>h[r]){
                r = r-1;

            }else{
                l = l+1;
            }


        }

        return ans;


        

        
    }
};