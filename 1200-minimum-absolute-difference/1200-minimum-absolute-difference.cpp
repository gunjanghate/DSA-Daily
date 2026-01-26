class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        vector<int> ans;
        int mn = INT_MAX;
        for(int i = 0; i<arr.size()-1; i++){
            int diff = abs(arr[i]-arr[i+1]);
            if(mn > diff){
                mn = diff;
                res.clear();
                res.push_back({arr[i], arr[i+1]});
            }
            else if(diff == mn){
                res.push_back({arr[i], arr[i+1]});

            }
        }


        return res;
    }
};