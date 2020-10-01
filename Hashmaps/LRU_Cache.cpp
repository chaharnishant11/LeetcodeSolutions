class LRUCache {
public:
    int sz, maxSz;
    list<pair<int,int>> li;//<key, value>
    unordered_map<int,list<pair<int,int>>::iterator> v;//key -> node*
    
    LRUCache(int capacity) {
        maxSz=capacity;
        sz=0;
    }
    
    int get(int key) {
        if (v.find(key)==v.end())
            return -1;
        li.push_front(make_pair(key,v[key]->second)); // new element jo get kiya usey front mein add kardiya
        li.erase(v[key]); //existing list mein jo pada hai usey removeh
        v[key]=li.begin(); // naya node hashmap mein add
        return v[key]->second; // return kardi value, key k hisab se
    }
    
    void put(int key, int value) {
        if (v.find(key)==v.end()){ // doesn't exist already
            li.push_front(make_pair(key,value));
            v[key]=li.begin();
            sz++;
            if (sz<=maxSz)
                return;
            v.erase(li.back().first); // if size more than capacity then remove last element from hash map
            li.pop_back(); // remove last element from list
            sz--;
        } else { //already exits
            li.push_front(make_pair(key,value));
            li.erase(v[key]);
            v[key]=li.begin();
        }
    }
};
