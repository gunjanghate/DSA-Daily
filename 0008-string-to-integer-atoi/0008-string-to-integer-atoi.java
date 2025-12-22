class Solution {
    public int myAtoi(String str) {
        str = str.trim();
        if (str.length() == 0) {
            return 0;
        }

        str.charAt(0);
        int sign = 1;
        int index = 0;
        if (str.charAt(0) == '-') {
            sign = -1;
            index++;
        } else if (str.charAt(0) == '+') {
            index++;
        }

        long result = 0;
        while (index < str.length()) {
            char ch = str.charAt(index);
            if(ch < '0' || ch > '9') {
                break;
            }
            result = result * 10 + (ch - '0');
            if (sign * result < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            } else if (sign * result > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;
            }
            index++;
        }

        return sign* (int)result;
}

};