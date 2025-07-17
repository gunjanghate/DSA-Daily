class MinStack {
private:
    vector<vector<int>> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int min_val = getMin();
        if (st.empty() || min_val > val) {
            min_val = val;
        }
        st.push_back({val, min_val});        
    }
    
    void pop() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        st.pop_back();
    }
    
    int top() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return st.empty() ? -1 : st.back()[0];
    }
    
    int getMin() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return st.empty() ? -1 : st.back()[1]; 
    }
};