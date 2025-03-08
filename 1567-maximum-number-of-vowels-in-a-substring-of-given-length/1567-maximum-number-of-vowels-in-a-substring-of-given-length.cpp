class Solution {
public:
    int isVowel(char s){
        if(s!='a'&& s!='e'&& s!='i'&& s!='o' && s!='u') return 0;
        return 1;
    }
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n =s.length();
        int cnt= 0;
        if(n==1) return isVowel(s[0]);
        for(int i = 0;i<k;i++){
            if(isVowel(s[i])) cnt++;
        }
        int mx = cnt;
        for(int l = 0 ,r= k; r<n; l++, r++){
            cnt +=isVowel(s[r])-isVowel(s[l]);
            mx = max(mx, cnt);
        }

        return mx;
    }
};