class Solution {
public:
    typedef pair<int, int> P;
    typedef tuple<long, int, int> T;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> res (m, 0);


        priority_queue<P, vector<P>, greater<P>> free;
        priority_queue<T, vector<T>, greater<T>> busy;


        for(int i = 0; i<n; i++){
            free.push({servers[i], i});
        }

        for(int i = 0; i<m; i++){
            while(!busy.empty() && get<0>(busy.top()) <= i){
                auto [f, wt, idx] = busy.top();
                busy.pop();

                free.push({wt, idx});
            }

            if(free.empty()){
                auto [f, wt, idx] = busy.top();
                busy.pop();
                res[i] = idx;
                busy.push({f + tasks[i], wt, idx});

            }else{
                auto [wt, idx] = free.top();
                free.pop();

                res[i] = idx;

                busy.push({i + tasks[i], wt, idx});
            }
        }
    return res;

    }
};