class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> m;
        vector<int> tem(arr.begin(), arr.end());
        sort(tem.begin(), tem.end());
        tem.erase(unique(tem.begin(), tem.end()), tem.end());
        for (int i = 0; i < tem.size(); i++) {
            m[tem[i]] = i + 1;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = m[arr[i]];
        }

        return arr;
    }
};