class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        if(a.size()==1) return mass >= a[0]; 
        sort(a.begin(), a.end());
        long long m = mass;

        for(int i = 0; i<a.size(); i++){
            if(m >= a[i]){
                m += a[i];
            }else{
                return false;
            }
        }
        return true;
    }
};