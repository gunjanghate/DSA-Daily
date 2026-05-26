class Solution {
  public:
    int maxConsecBits(vector<int> &arr) {

        int ans = 1;
        int cnt = 1;

        for(int i = 1; i < arr.size(); i++) {

            if(arr[i] == arr[i - 1]) {
                cnt++;
            }
            else {
                cnt = 1;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};