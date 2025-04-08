#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
private:
    bool isDistinct(vector<int>& nums, int start) {
        unordered_set<int> seen;
        for (int i = start; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                return false; 
            }
            seen.insert(nums[i]);
        }
        return true; 
    }

public:
    int minimumOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int operations = 0;
        int l = nums.size();

        for (int i = 0; i < nums.size();) {
            if (isDistinct(nums, i)) {
                break;
            }
            int removeCount = min(3, (l - i));
            i += removeCount;
            operations++;
        }

        return operations;
    }
};