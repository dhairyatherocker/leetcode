class Solution {
public:
    int minAddToMakeValid(string s) {
    int sum=0;
    int total=0;
    for(int i=0;i<s.size();i++){
    if(s[i]=='(') sum++;
    else sum--;
    if(sum<0){
    total+=abs(sum);
    sum=0;    
    }
    }
    if(sum!=0) total+=sum;
    return total;    
    }
};