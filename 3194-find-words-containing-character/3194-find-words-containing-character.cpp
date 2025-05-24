class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> ans;
        int l = words.size();
        // for(int w = 0; w < l; w++){
        //     for(int c = 0; c < words[w].size(); c++){
        //         if(words[w][c]==x){
        //             ans.push_back(w);
        //             break;
        //         }
        //     }
        // }
         for(int i=0; i<l; i++){
            if (words[i].find(x)!=-1)
                ans.push_back(i);
        }

        return ans;
    }
};