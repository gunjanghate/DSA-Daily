class Solution {
public:
    int minimumRecolors(string& blocks, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n=blocks.size();
        int W=count(blocks.begin(), blocks.begin()+k, 'W');
        int cnt=W;
        for(int l=0, r=k; r<n; r++, l++){
            W+=(blocks[r]=='W')-(blocks[l]=='W');
            cnt=min(cnt, W);
        }
        return cnt;
    }
};