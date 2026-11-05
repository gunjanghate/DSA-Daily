class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int ans = 0;


        for(int i = 0; i<n; i++){
            int a = arr1[i];
            bool f = false;
            for(int j = 0; j<m; j++){
                int b = arr2[j];
                int diff = abs(a-b);

                if(diff <= d){
                    f = true;
                    break;
                }
            }
            if(!f) ans++;
        }

        return ans;
    }
};