// class Solution {
// public:
//     int thirdMax(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);

//         int fstmx = *max_element(nums.begin(), nums.end());
//         int secmx = INT_MIN;
//         for(auto i :nums){
//             if(fstmx !=i && i>=secmx){
//                 secmx = i;
//             }
//         }
//         int thrdmx = INT_MIN;
//         int f = 0;
//         for(auto i :nums){
//             if(secmx !=i && fstmx!=i && i>=thrdmx){
//                 thrdmx = i;
//                 f = 1;
//             }
//         }
//         if(!f)
//             thrdmx = fstmx;

//         return thrdmx;

//     }
// };
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long fst = LLONG_MIN, sec = LLONG_MIN, thrd = LLONG_MIN;

        for (int num : nums) {
            if (num == fst || num == sec || num == thrd) continue;

            if (num > fst) {
                thrd = sec;
                sec = fst;
                fst = num;
            } else if (num > sec) {
                thrd = sec;
                sec = num;
            } else if (num > thrd) {
                thrd = num;
            }
        }

        return thrd == LLONG_MIN ? fst : thrd;
    }
};
