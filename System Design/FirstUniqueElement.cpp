class FirstUnique {
public:
    unordered_map<int,int> m;
    queue<int> q;
    FirstUnique(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            q.push(nums[i]);
        }
    }
    
    int showFirstUnique() {
        while(!q.empty() && m[q.front()]>1){
            q.pop();
        }
        return (q.empty())?-1:q.front();
    }
    
    void add(int value) {
        q.push(value);
        m[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */