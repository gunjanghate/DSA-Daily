class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        unordered_map<int, int> m1;
        for(int i : nums1) m1[i]++;

        for(int i : nums2){
            if(m1[i]>0){
                s.insert(i);
            }
        }

        for(int i : s){
            ans.push_back(i);
        }

        return ans;
    }
};