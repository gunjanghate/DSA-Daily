class Solution {
    static String[] key = {"", "", "abc", "def","ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(String d, List<String> ans,String s){
         if(d.length()==0){
            ans.add(s);
            return;
         }

         String ques = key[(int)(d.charAt(0))-48];
         for(int i=0; i<ques.length(); i++){
            solve(d.substring(1), ans, s+ques.charAt(i));
         }
    }
    public List<String> letterCombinations(String digits) {
        
        List<String> ans = new ArrayList<String>();
        if(digits.length()==0){
            return ans;
        }
        solve(digits, ans, "");
        return ans;

    }

}