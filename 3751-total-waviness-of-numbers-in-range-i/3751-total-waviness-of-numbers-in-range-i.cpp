class Solution {
public:
    int findWavi(string s){
        int c = 0;
        for(int i = 1; i<s.length()-1; i++){
            if(s[i-1]>s[i] && s[i]<s[i+1]) c++;
            else if(s[i-1]<s[i] && s[i]>s[i+1]) c++;
        }   

        return c;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        
        for(int i = num1 ; i<= num2; i++){
            ans += findWavi(to_string(i)); 
        }

        return ans;
    }
};