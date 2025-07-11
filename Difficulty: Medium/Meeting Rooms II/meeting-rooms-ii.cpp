class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int cnt = 0;
        int e = 0;
        for(int i = 0; i<start.size(); i++){
            if(start[i]<end[e]) cnt++;
            else e++;
        }
        
        
        return cnt;
        
    }
};
