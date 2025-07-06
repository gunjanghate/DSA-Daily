class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq; 

    FindSumPairs(vector<int>& n1, vector<int>& n2) {
        nums1 = n1;
        nums2 = n2;
        for (int x : nums2) {
            freq[x]++;
        }
    }

    void add(int index, int val) {
        freq[nums2[index]]--;
        if (freq[nums2[index]] == 0) freq.erase(nums2[index]);

        nums2[index] += val;

        freq[nums2[index]]++;
    }

    int count(int tot) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int cnt = 0;
        for (int x : nums1) {
            int target = tot - x;
            if (freq.count(target)) {
                cnt += freq[target];
            }
        }
        return cnt;
    }
};
