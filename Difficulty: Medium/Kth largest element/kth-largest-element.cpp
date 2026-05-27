class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {


        priority_queue<int,vector<int>,  greater<int>> pq;

        for(int x : arr){

            pq.push(x);

            if(pq.size() > k){
                pq.pop();
            }
        }

        return pq.top();

    }
};