class Solution {
public:

    bool comp(string a, string b){
        if(a.length() > b.length()) return true;
        if(a.length() < b.length()) return false;
        return a > b;
    }

    string kthLargestNumber(vector<string>& nums, int k) {
        k = nums.size() - k + 1;

        priority_queue<pair<int,string>> pq;

        for(auto &i : nums){

            if(pq.size() == k && comp(pq.top().second, i)){
                pq.pop();
            }

            if(pq.size() < k){
                pq.push({i.length(), i});
            }
        }

        return pq.top().second;
    }
};