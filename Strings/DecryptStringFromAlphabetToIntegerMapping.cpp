class Solution {
public:
    string freqAlphabets(string s) {
        unordered_map<string,char> m;
		for(int i=1;i<10;i++){
			string temp=to_string(i);
			m[temp]='a'+i-1;
		}
		for(int i=10;i<=26;i++){
			string temp=to_string(i)+'#';
			m[temp]='j'+i-10;
		}
		string ans;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='#'){
				string cur=s.substr(i-2,3);
				ans=m[cur]+ans;
				i-=2;
			}
			else{
				string ss="a";
				ss[0]=s[i];
				ans=m[ss]+ans;
			}
		}
		return ans;
    }
};