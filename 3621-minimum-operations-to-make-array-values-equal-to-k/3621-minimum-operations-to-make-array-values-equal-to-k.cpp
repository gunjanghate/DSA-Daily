class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<int> uniqueGreater;

        for (int num : nums) {
            if (num < k) return -1;
            if (num > k) uniqueGreater.insert(num);
        }

        return uniqueGreater.size(); 
    }
};
