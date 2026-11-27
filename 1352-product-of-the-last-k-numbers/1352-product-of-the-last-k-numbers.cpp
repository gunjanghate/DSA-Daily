class ProductOfNumbers {
public:
    vector<int> streams;
    ProductOfNumbers() {
        this->streams = vector<int>();
    }
    
    void add(int num) {
        streams.push_back(num);
    }
    
    int getProduct(int k) {
        int n = streams.size();

        // 3 0 2 5 4 
        //
        int i = n  - k;
        int pd = 1;
        for(int j = i; j<n; j++){
            pd *= streams[j];
        }
        return pd;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */