// class Solution {
// private:
//     int getMax(const vector<int>& nums) {
//         return *max_element(nums.begin(), nums.end());
//     }

//     int getSecondLargest(const vector<int>& nums, int maxVal) {
//         int second = -1;
//         for (int num : nums) {
//             if (num != maxVal) {
//                 second = max(second, num);
//             }
//         }
//         return second;
//     }

// public:
//     int minOperations(vector<int>& nums, int k) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);

//         int cnt = 0;

//         while (true) {
//             int maxVal = getMax(nums);

//             if (maxVal == k) return cnt;

//             if (maxVal < k) return -1;

//             int second = getSecondLargest(nums, maxVal);

//             if (second == -1) return -1;

//             // Replace all max values with second largest
//             for (int& num : nums) {
//                 if (num == maxVal) num = second;
//             }

//             cnt++;
//         }

//         return -1;
//     }
// }; TC & SC : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        for(auto num : nums)
            if(num<k) return -1;

        sort(nums.rbegin(), nums.rend()); // Sort descending
        int cnt = 0;
        int last = -1;

        for (int num : nums) {
            if (num < k) return -1;
            if (num == k) break;
            if (num != last) {
                cnt++;
                last = num;
            }
        }

        return cnt;
    }
};//TC:O(n) SC:O(1)

