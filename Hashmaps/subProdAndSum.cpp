class Solution {
public:
    int subtractProductAndSum(int n) {
        unordered_map<int,int> map;
        int num=n;
        while(num>0){
            int r=num%10;
            num=num/10;
            if(map.find(r)==map.end()){
                map[r]=1;
            }else{
                map[r]++;
            }
        }
        int sum=0,prod=1;
        for(auto i:map){
            sum+=i.first*i.second;
            prod*=pow(i.first,i.second);
        }
        return prod-sum;
    }
};
