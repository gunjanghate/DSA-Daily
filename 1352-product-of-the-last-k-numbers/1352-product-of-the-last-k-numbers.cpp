class ProductOfNumbers {
public:
    // vector<int> streams;
    vector<int> pds; // prefix products
    ProductOfNumbers() {
    }

    
    void add(int num) {
        if(num==0) pds.clear();
        // streams.push_back(num);
        // streams - 3 0 2 5 4 

        // pds     - 3 0 2 10 4
        //           0 1 2  3  4
        //           5 4 3  2  1

        else if(pds.empty()) pds.push_back(num);
        else{
            pds.push_back(pds.back()*num); 
        }
    }
    
    int getProduct(int k) {
        int n = pds.size();

        // int i = n  - k;
        // int pd = 1;
        // for(int j = i; j<n; j++){
        //     pd *= streams[j];
        // }
        // return pd;

        if(k>n) return 0;
        if(k==n) return pds.back();
        if(pds.empty()) return 0;


        return pds.back() / pds[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */