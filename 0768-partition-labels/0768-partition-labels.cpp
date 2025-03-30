// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         map<char, int> mp;
//         for (auto i : s) {
//             mp[i]++;
//         }
//         string ans = "";
//         int n = s.length();
//         vector<int> lengths;
//         vector<char> store;
//         for (int i = 0; i < n; i++) {
//             if (store.empty() && mp[s[i]] > 0) {
//                 store.push_back(s[i]);
//                 ans += s[i];
//                 mp[s[i]]--;
//             } else {
//                 if (mp[s[i]] > 0) {
//                     int cnt = count(store.begin(), store.end(), s[i]);
//                     if (cnt) {
//                         ans += s[i];
//                         mp[s[i]]--;
//                     } else {
//                         store.push_back(s[i]);
//                         ans += s[i];
//                         mp[s[i]]--;
//                     }
//                 }

//             }
//                 if (mp[s[i]] < 1) {
//                         store.erase(find(store.begin(), store.end(), s[i]));
//                         if(store.empty()){
//                         lengths.push_back(ans.length());
//                         ans = "";
//                         }
//                     }

//         }

//         return lengths;
//     }
// };// O(N) -> 3ms
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(26, 0);
        vector<int> result;
        
        // Step 1: Store last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            last_index[s[i] - 'a'] = i;
        }

        // Step 2: Traverse string and partition
        int max_last_index = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            max_last_index = max(max_last_index, last_index[s[i] - 'a']);
            
            // If current index matches max_last_index, we found a partition
            if (i == max_last_index) {
                result.push_back(i - start + 1); 
                start = i + 1; 
            }
        }

        return result;
    }
};
