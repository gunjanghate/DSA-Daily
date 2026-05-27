class Solution {
  public:
    int thirdLargest(vector<int> &arr) {

        int first = -1;
        int second = -1;
        int third = -1;

        for(int x : arr){

            if(x > first){
                third = second;
                second = first;
                first = x;
            }

            else if(x > second){
                third = second;
                second = x;
            }

            else if(x > third){
                third = x;
            }
        }

        return (arr.size() < 3) ? -1 : third;
    }
};