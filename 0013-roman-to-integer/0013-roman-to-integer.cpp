// class Solution {
// public:
//     int romanToInt(string s) {
//         int ans = 0;
//         int n = s.length();
        
//         for (int i = 0; i < n; i++) {
//             if (s[i] == 'I') {
//                 if (i + 1 < n && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
//                     ans -= 1;
//                 } else {
//                     ans += 1;
//                 }
//             } else if (s[i] == 'V') {
//                 ans += 5;
//             } else if (s[i] == 'X') {
//                 if (i + 1 < n && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
//                     ans -= 10;
//                 } else {
//                     ans += 10;
//                 }
//             } else if (s[i] == 'L') {
//                 ans += 50;
//             } else if (s[i] == 'C') {
//                 if (i + 1 < n && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
//                     ans -= 100;
//                 } else {
//                     ans += 100;
//                 }
//             } else if (s[i] == 'D') {
//                 ans += 500;
//             } else if (s[i] == 'M') {
//                 ans += 1000;
//             }
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int romanToInt(string s) {
        int ans=0;
        unordered_map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0 ; i<s.size() ; i++){
        if(mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};