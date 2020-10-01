class Solution {
public:
    int myAtoi(string str) {
        str.append("xd"); // This prevents the case when str is empty (str.size() == 0)   
        stringstream ss(str);
        //ss<<str;
        int x;
        ss>>x;
        return x;
    }
};
