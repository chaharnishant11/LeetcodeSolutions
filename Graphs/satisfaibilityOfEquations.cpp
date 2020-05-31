class Solution {
public:
    int Find(int x,int * parent){
        if(x==parent[x]){
            return x;
        }
        int px=Find(parent[x],parent);
        parent[x]=px;
        return px;
    }
    
    void Union(int x,int y,int* parent){
        int px=Find(x,parent);
        int py=Find(y,parent);
        if(px!=py) parent[px]=py;
    }
    
    bool equationsPossible(vector<string>& equations) {
        int parent[26];
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='='){
                int a=equations[i][0]-'a';
                int b=equations[i][3]-'a';
                Union(a,b,parent);
            }
        }
        //for(int i=0;i<26;i++) cout << parent[i] << " " ;
        for(int i=0;i<equations.size();i++){
            if(equations[i][1]=='!'){
                int a=equations[i][0]-'a';
                int b=equations[i][3]-'a';
                int pa=Find(a,parent);
                int pb=Find(b,parent);
                if(pa==pb) return false;
            }
        }
        return true;
    }
};