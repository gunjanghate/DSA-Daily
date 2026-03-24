class Solution {
public:
    const int mod = 1e9 + 7;

    // ---------- MIN PART ----------
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

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);
        int n = arr.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;

            total += (left * right * arr[i]);
        }

        return total;
    }

    // ---------- MAX PART ----------
    vector<int> findNGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> nge(n);

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPGE(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> pge(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i])
                st.pop();

            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> pge = findPGE(arr);
        vector<int> nge = findNGE(arr);
        int n = arr.size();

        long long total = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - pge[i];
            long long right = nge[i] - i;

            total += (left * right * arr[i]);
        }

        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        long long minSum = sumSubarrayMins(nums);
        long long maxSum = sumSubarrayMax(nums);

        return maxSum - minSum; // sum of min - sum of max
    }
};