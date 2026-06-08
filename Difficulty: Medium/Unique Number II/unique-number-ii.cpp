class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        long long x = 0;
        for(int i = 0; i<arr.size(); i++){
            x ^= arr[i];
        }
        long long y = 0,z = 0;
        long long a = x & -x;
        for(int i : arr){
            if(i & a){
                y ^= i;
            }else{
                z ^= i;
                
            }
        }
        
        if(y > z) swap(y, z);

        return {y,z};
    }
};