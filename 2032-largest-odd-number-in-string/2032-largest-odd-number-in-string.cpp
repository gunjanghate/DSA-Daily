class Solution {
public:
    string largestOddNumber(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        // int l = num.length();
        // int n = stoi(num);
        // if(n%2==1) return to_string(n);
        // while(n>0){
        //     int f = n % 10;
        //     int d = n/10;
        //     if(f%2==1) return to_string(f);
        //     if(d%2==1) return to_string(d);
        //     n = n/10;
        // }

        // return ""; runtime error if input is very large
                if (num.back() % 2 == 1)
                    return num;
                int i = num.length() - 1;
                while (i >= 0) {
                    int n = num[i];
                    if (n % 2 == 1)
                        return num.substr(0, i + 1);
                    i--;
                }
                return "";
    }
};