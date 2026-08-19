class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        // each row have possibility of three ways to have group 
        // 2 3 4 5, 4 5 6 7, 6 7 8 9
        // each row can have max 2 groups 

        unordered_map<int, unordered_set<int>> row;
        for (auto& p : rs) {
            row[p[0]].insert(p[1]);
        }

        int ans = 2 * (n - (int)row.size());   // empty rows give 2 each

        for (auto& [r, seats] : row) {
            bool g1 = true;   // 2-5
            bool g2 = true;   // 4-7
            bool g3 = true;   // 6-9

            for (int seat : seats) {
                if (seat >= 2 && seat <= 5) g1 = false;
                if (seat >= 4 && seat <= 7) g2 = false;
                if (seat >= 6 && seat <= 9) g3 = false;
            }

            if (g1 && g3) ans += 2;
            else if (g1 || g2 || g3) ans += 1;
          
        }
        return ans;
    }
};