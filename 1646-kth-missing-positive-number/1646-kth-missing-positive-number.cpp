class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        // after loop high will reach at somewhere before the ans i.e if ans is
        // 9 then high might be pointing to someone lesser than 9 missing at
        // high = arr[high] - (high+1) thus ans = arr[high]+more more =
        // k-missing ans = arr[high] +k - missing ans = arr[high] + k -
        // arr[high] + high + 1 ans =  k + high + 1 also low = high + 1; //as it
        // is the situation when loop breaks i.e low>high ans = low + k; or
        // high+1+k;

        return high + 1 + k;
    }
};