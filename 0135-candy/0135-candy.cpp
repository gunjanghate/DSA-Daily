class Solution {
public:
    int candy(vector<int>& ratings) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = ratings.size();
        int sum = 1;
       
        int i = 1;

        while (i < n) {

            if (ratings[i] == ratings[i - 1]) {
                sum+=1;
                i++;
                continue;
            }

            int peak = 1;

            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            int valley = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += valley;
                i++;
                valley++;
            }
            if(valley>peak){
                sum += valley - peak;
            }
        }

        return sum;
    }
};