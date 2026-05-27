class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(int x : arr){
            pq.push(x);
        }

        int first = pq.top();
        pq.pop();

        while(!pq.empty() && pq.top() == first){
            pq.pop();
        }

        if(pq.empty()){
            return {-1};
        }

        int second = pq.top();

        return {first, second};
    }
};