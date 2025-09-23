class Solution {
public:
    int compareVersion(string version1, string version2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();

        while (i < n1 || j < n2) {
            long long num1 = 0, num2 = 0;

            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            if (i < n1 && version1[i] == '.') i++;

            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if (j < n2 && version2[j] == '.') j++;

            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
        }

        return 0;
    }
};
