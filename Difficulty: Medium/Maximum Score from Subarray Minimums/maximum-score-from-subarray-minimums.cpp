//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find pair with maximum sum
        int pairWithMaxSum(vector<int> &arr) {
        int i=0;
        int j=1;
        int sum=0;
        int maxii=INT_MIN;
        while(j<arr.size()){
           sum=arr[i] + arr[j];
           maxii=max(sum,maxii);
           i++;
           j++;
        }
        return maxii;
        }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends