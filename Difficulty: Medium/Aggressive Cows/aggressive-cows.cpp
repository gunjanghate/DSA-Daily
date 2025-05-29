// User function Template for C++

class Solution {
  public:

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size(); 
    int cntCows = 1; 
    int last = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++; 
            last = stalls[i]; 
        }

    }
    return cntCows >= cows;
}
int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
   
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
   
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canWePlace(stalls, mid, k)) {
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return high;
}
};