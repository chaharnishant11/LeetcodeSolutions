void word(string A, vector<string> &B, string prev, vector<string> &out){
    if(A==""){
        out.push_back(prev);
        return;
    }
    for(int i=0;i<A.size();i++){
        string sub = A.substr(0,i+1);
        if(find(B.begin(), B.end(), sub)!=B.end()){
            string next = A.substr(i+1);
            string prev_new;
            if(prev=="")
                prev_new = sub;
            else
                prev_new = prev + " " + sub;
            word(next,B,prev_new,out);
        }
    }
}

vector<string> Solution::wordBreak(string a, vector<string> &b) {
    vector<string> output;
    word(a,b,"",output);
    return output;
}