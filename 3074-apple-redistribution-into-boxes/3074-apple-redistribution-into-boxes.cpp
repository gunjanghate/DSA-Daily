class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
        int boxes = 0;
        sort(capacity.begin(), capacity.end());

        for(int i = capacity.size()-1; i>=0; i--){
            if(totalApples>0){
                boxes++;
                totalApples -= capacity[i];
            }else{
                break;
            }
        }

        return boxes;

    }
};