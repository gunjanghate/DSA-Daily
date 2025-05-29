class Solution {
public:
    int helper(vector<int> &arr, int pages){
        int students = 1;
        long long pagesStu = 0;
        for(int i = 0; i < arr.size(); i++){
            if(pagesStu + arr[i] <= pages){
                pagesStu += arr[i];
            } else {
                students++;
                pagesStu = arr[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int l = *max_element(arr.begin(), arr.end());
        int h = accumulate(arr.begin(), arr.end(), 0);
        int m, ans = h;

        while(l <= h){
            m = l + (h - l) / 2;
            int stu = helper(arr, m);

            if(stu <= k){
                ans = m;
                h = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};
