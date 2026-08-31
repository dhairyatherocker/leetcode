class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    unordered_map<int,int>m;
    m[5]=0;
    m[10]=0;
    for(int i=0;i<bills.size();i++){
    if(bills[i]==5) m[bills[i]]++;
    else if(bills[i]==10){
    if(m[5]<1) return false;
    m[5]--;
    m[bills[i]]++;     
    }
    else if(bills[i]==20){
    if(m[5]>=1 && m[10]>=1){
    m[5]--;
    m[10]--;
    }
    else if(m[5]>=3) m[5]-=3;
    else return false;
    m[bills[i]]++;    
    }    
    }
    return true;    
    }
};