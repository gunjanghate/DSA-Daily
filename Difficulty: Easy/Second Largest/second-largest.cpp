//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int>& arr) {
        if (arr.size() < 2) return -1;

        int large = INT_MIN, secondLarge = -1;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > large) {
                secondLarge = large;  
                large = arr[i];      
            } else if (arr[i] > secondLarge && arr[i] != large) {
                secondLarge = arr[i]; 
            }
        }

        return (secondLarge == INT_MIN) ? -1 : secondLarge;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends