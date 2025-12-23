class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        vector<int> v1;
        vector<int> v2;
        int n = q.size();
        int k = n / 2;
        
        for(int i = 0; i<k; i++){
            v1.push_back(q.front());
            q.pop();
        }
        for(int i = k; i < n; i++){
            v2.push_back(q.front());
            q.pop();
        }
        
        for(int i = 0; i<k; i++){
            q.push(v1[i]);
            q.push(v2[i]);
        
        }
        

    }
};