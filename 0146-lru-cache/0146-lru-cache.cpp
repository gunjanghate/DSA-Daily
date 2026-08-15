class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
                // <key, (address, value)>
    int n;

    LRUCache(int capacity) {
        n = capacity;
    }

    void makeRecent(int k){
        dll.erase(mp[k].first);

        dll.push_front(k);

        mp[k].first = dll.begin();

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        makeRecent(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second = value;
            makeRecent(key); 
        }else{
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if(n<0){
            int extra = dll.back();
            mp.erase(extra);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */