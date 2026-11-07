class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {
        int m = logs.size();

        vector<pair<int, int>> sortedq;

        auto lambda = [](vector<int>& p, vector<int>& q){
            return p[1] < q[1];
        };

        sort(logs.begin(), logs.end(), lambda);

        for(int i = 0; i<q.size(); i++){
            sortedq.push_back({q[i], i});
        }

        sort(sortedq.begin(), sortedq.end());

        vector<int> ans(q.size(), 0);

        unordered_map<int, int> idToTime;

        int i = 0, j = 0;


        for(auto [time, idx] : sortedq){
            int s = time - x;
            int e = time;

            while( j<m && logs[j][1]<=e){
                idToTime[logs[j][0]]++;
                j++;
            }

            while(i<m && logs[i][1] < s){
                idToTime[logs[i][0]]--;
                if(idToTime[logs[i][0]]==0) idToTime.erase(logs[i][0]);
                i++;
            }

            ans[idx] = (n - idToTime.size());
        }

        return ans;
    }
};