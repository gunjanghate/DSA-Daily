class Solution {
public:
    int maxDistance(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dists;
        int x = 0, y = 0;
            for (char i : s) {
            if (i == 'N') y++;
            else if (i == 'S') y--;
            else if (i == 'E') x++;
            else if (i == 'W') x--;
            dists.push_back(abs(x) + abs(y));
        }
        if(k==0) return *max_element(dists.begin(), dists.end());

        int mxDist = dists[1];
        int prev = dists[0];
        int add = 0;
        //1 2 1 0
        for(int i = 1; i<dists.size(); i++){
            if(dists[i]<prev && k>0){
               add+=2;
               k--;
            }
            prev= dists[i];
            dists[i] += add;
            mxDist = max(mxDist, dists[i]);
        }

        return mxDist;

    }
};