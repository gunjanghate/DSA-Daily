class ThroneInheritance {
public:

    map<string, vector<string>> children;
    map<string, bool> dead;
    string king;

    ThroneInheritance(string kingName) {
        king = kingName;
        dead[kingName] = false;
    }

    void birth(string parentName, string childName) {
        children[parentName].push_back(childName);
        dead[childName] = false;
    }

    void death(string name) {
        dead[name] = true;
    }

    vector<string> getInheritanceOrder() {

        vector<string> ans;


        stack<string> st;

        st.push(king);

        while (!st.empty()) {

            string curr = st.top();
            st.pop();

            if (!dead[curr]) {
                ans.push_back(curr);
            }


            for (int i = children[curr].size() - 1; i >= 0; i--) {
                st.push(children[curr][i]);
            }
        }

        return ans;
    }
};


/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */