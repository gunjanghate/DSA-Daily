class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size() - k + 1;
        // 3 4 7 10 15 20
        for(int num : arr){
            if(n == pq.size() && pq.top()<num){
                pq.pop();
                pq.push(num);
            }
            if(n > pq.size()){
                pq.push(num);
            }
        }
        
        
        return pq.top();
        
    }
};