class Solution {
public:
    void computeLPS(vector<int> &pattern, vector<int>& lps){
        int M = pattern.size();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while(i<M){
            if(pattern[i] == pattern[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }
    bool KMP(vector<int>& pat, vector<int>& txt ){
        int M = pat.size();
        int N = txt.size();

        vector<int> lps(M, 0);
        // 5 6 5 6
        // 6 5
        // i
        // j
        computeLPS(pat, lps);

        int i = 0, j = 0;
        while(i<N){
            if(pat[j] == txt[i]){
                i++, j++;
            }

            if(j==M){
                return true;
            }else if(i < N && pat[j] != txt[i]){
                if(j!=0){
                    j = lps[j - 1];
                } else i++;
            }
        }

        return false;
    }

    bool isPossible(vector<int>& v1, vector<int>& v2 ){
        vector<int> txt = v2;
        txt.insert(txt.end(), v2.begin(), v2.end()); // search space for KMP


        return KMP(v1, txt);

    }
    int sortableIntegers(vector<int>& nums) {
        vector<int> ks;
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end());
        int ans = 0;

        int n = nums.size();

        for(int i = 1; i<=n ; i++){
            if(n%i==0) ks.push_back(i);
        }

        for(int i = 0; i<ks.size(); i++){
            int K = ks[i];

            bool isValid = true;

            for(int j = 0; j<n; j+=K){
                vector<int> vec1(begin(nums)+j, begin(nums) + j + K);
                vector<int> vec2(begin(sorted)+j, begin(sorted) + j + K);

                if(!isPossible(vec1, vec2)){
                    isValid = false;
                    break;
                }


            }

            if(isValid) ans += K;

        }

        return ans;
        
    }
};