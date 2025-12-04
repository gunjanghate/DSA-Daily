// class Solution {
// public:
//     int countCollisions(string d) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
//         stack<char> s;
//         int collisions = 0;

//         for (char c : d) {
//             // Case 1: car is L → may cause multiple collisions
//             if (c == 'L') {
//                 if (!s.empty() && s.top() == 'R') {
//                     collisions += 2;
//                     s.pop();
//                     while (!s.empty() && s.top() == 'R') {
//                         collisions++;
//                         s.pop();
//                     }

//                     s.push('S');
//                 }
//                 else if (!s.empty() && s.top() == 'S') {
//                     collisions++;
//                     s.push('S');
//                 }
//                 else {
//                     s.push('L');
//                 }
//             }

//             // Case 2: car is R → just push it
//             else if (c == 'R') {
//                 s.push('R');
//             }

//             // Case 3: car is S → may absorb R's
//             else if (c == 'S') {
//                 while (!s.empty() && s.top() == 'R') {
//                     collisions++;
//                     s.pop();
//                 }

//                 s.push('S');
//             }
//         }

//         return collisions;
//     }
// };

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0;
        int r = n - 1;
        while(l < n  && directions[l] == 'L') l += 1;
        while(r >= 0 && directions[r] == 'R') r -= 1;
        int ans = 0;
        for(int i = l; i <= r; i ++){
            ans += directions[i] != 'S';
        }
        return ans;
    }
};