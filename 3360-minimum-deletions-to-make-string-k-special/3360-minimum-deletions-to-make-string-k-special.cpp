class Solution {
public:
    int minimumDeletions(string word, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> freq(26, 0);
        for (char ch : word)
            freq[ch - 'a']++;

        vector<int> freqVec;
        for (int x : freq) {
            if (x > 0)
                freqVec.push_back(x);
        }

        sort(freqVec.begin(), freqVec.end()); 

        int minDelete = INT_MAX;
        int n = freqVec.size();

        for (int i = 0; i < n; i++) {
            int x = freqVec[i];
            int dlt = 0;
            for (int j = 0; j < i; j++) {
                dlt += freqVec[j]; 
            }
            for (int j = i + 1; j < n; j++) {
                int y = freqVec[j];
                if (y > x + k)
                    dlt += (y - x - k);
            }

            minDelete = min(minDelete, dlt);
        }

        return minDelete;
    }
};
