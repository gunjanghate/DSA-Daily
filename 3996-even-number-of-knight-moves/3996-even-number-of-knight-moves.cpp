class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int st = start[0] + start[1];
        int ed = target[0] + target[1];

        if((st%2==0 && ed%2==0) || (st%2!=0 && ed%2!=0)) return true;
        return false;
    }
};