class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int,map<string,int>> m;
        map<string,bool> food;
        for(int i=0;i<orders.size();i++){
            int tn=stoi(orders[i][1]);
            string f=orders[i][2];
            m[tn][f]++;
            food[f]=true;
        }
        vector<vector<string>> ans;
        vector<string> temp;
        temp.push_back("Table");
        for(auto i:food){
            temp.push_back(i.first);
        }
        ans.push_back(temp);
        for(auto i:m){
            vector<string> te;
            te.push_back(to_string(i.first));
            for(auto j:food){
                if(m[i.first][j.first]>0){
                    te.push_back(to_string(m[i.first][j.first]));
                }else{
                    te.push_back("0");
                }
            }
            ans.push_back(te);
        }
        return ans;
    }
};