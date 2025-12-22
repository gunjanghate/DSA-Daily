class Solution {
    public boolean isSubsequence(String sub, String str) {
        int strIdx = 0, subIdx = 0;
        while (strIdx < str.length() && subIdx < sub.length()) {
            if (str.charAt(strIdx) == sub.charAt(subIdx)) {
                subIdx++;
            }
            strIdx++;
        }
        return subIdx == sub.length();
    }
}