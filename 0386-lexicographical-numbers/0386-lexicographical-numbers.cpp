class Solution {
public:

    void solve(int i, int n,vector<int> &v){

        if(i>n) return;
        v.push_back(i);
        for(int j=0;j<=9;j++){
            solve(i*10+j,n,v);
        }
    }
    vector<int> lexicalOrder(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> ans;
        for(int i=1;i<10;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};