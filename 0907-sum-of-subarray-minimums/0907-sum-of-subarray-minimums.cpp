class Solution {
public:
    const int mod = (int) 1e9 + 7;
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
        return nse;
    }
    vector<int> findPSE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);
        int n = arr.size();
        int total = 0;
        for(int i = 0; i<n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;

            total = (total +(left * 1LL* right * arr[i])%mod)%mod;
        }

        return total;
    }
};