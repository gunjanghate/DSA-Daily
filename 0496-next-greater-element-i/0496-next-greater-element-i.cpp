class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        priority_queue<int> pq;
        for (int i = 0; i < nums1.size(); i++) {

            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int j = it - nums2.begin();
            int f = -1;
        
            while (j < nums2.size()) {
                if(!pq.empty() && pq.top()<nums2[j]){
                    f = nums2[j];
                    break;
                }
                pq.push(nums2[j]);
                j++;
            }

          
                ans.push_back(f);
            

            while (!pq.empty()) {
                pq.pop();
            }
        }
        return ans;
    }
};