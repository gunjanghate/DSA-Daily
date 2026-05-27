class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {

        priority_queue<int> pq;

        for(int x : arr){

            pq.push(x);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();
    }
};