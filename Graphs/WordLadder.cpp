class Solution {
public:
   int ladderLength(string b, string e, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(b);
        int count=0;
        s.erase(b);
        while(!q.empty()){
            int n=q.size();
            count++;
            for(int i=0;i<n;i++){
                string word=q.front();
                q.pop();
                if(word==e)return count;
                for(int j=0;j<(int)word.size();j++){
                    char ch=word[j];
                    for(int k=0;k<26;k++){
                        word[j]='a'+k;
                        if(s.find(word)!=s.end()){
                            q.push(word);
                            s.erase(word);
                        }
                    }
                    word[j]=ch;
                }
            }
        }
        return 0;
    }
};