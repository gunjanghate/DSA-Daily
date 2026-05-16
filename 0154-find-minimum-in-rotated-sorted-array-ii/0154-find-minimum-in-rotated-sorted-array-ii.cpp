class Solution {
public:
    int findMin(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return *min_element(arr.begin(), arr.end());
    }
};