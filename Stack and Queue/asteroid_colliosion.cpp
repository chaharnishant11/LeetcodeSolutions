class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> p;
        int n=asteroids.size();
        vector<int> v;
        if(n==0) return v;
        bool val=true;
        for(int i=0;i<n;i++){
            if(p.empty() || (p.top()<0) || (p.top()>0 && asteroids[i]>0)){
                p.push(asteroids[i]);
            }else{
                while(!p.empty()){
                    if(p.top()<0){
                        p.push(asteroids[i]);
                        break;
                    }
                    if(abs(asteroids[i])>p.top()){
                        p.pop();
                    }else{
                        if(abs(asteroids[i])==p.top()){
                            p.pop();
                            val=false;
                            break;
                        }else{
                            break;
                        }
                    }
                }
                if(p.empty() && val){
                    p.push(asteroids[i]);
                }
                val=true;
            }
        }
        vector<int>::iterator it;
        while(!p.empty())
        {
            it=v.begin();
            v.insert(it,p.top());
            p.pop();
        }
        return v;
    }
};


vector<int> asteroidCollision(vector<int>& a) {
        vector<int> s; // use vector to simulate stack.
        for (int i : a) {
            while (!s.empty() && s.back() > 0 && s.back() < -i)
                s.pop_back();
            if (s.empty() || i > 0 || s.back() < 0)
                s.push_back(i);
            else if (i < 0 && s.back() == -i)
                s.pop_back();
        }
        return s;
    }