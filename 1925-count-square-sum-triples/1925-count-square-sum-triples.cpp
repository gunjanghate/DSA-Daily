class Solution {
public:
    int countTriples(int n) {
        vector<long long> v(n + 1, 0); 

        for(int i = 1; i <= n; i++) {
            v[i] = 1LL * i * i; 
        }

        int cnt = 0;

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                
                long long sum = v[i] + v[j];

                long long root = sqrt(sum);

                if(root <= n && root * root == sum) {
                    cnt++;
                }
            }
        }
        return cnt * 2;  // if 6, 8 , 10 exists then 8, 6, 10 also
    }
};
