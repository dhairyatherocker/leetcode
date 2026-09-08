class Solution {
public:
    string largestOddNumber(string num) {
    int ans=-1;
    long long number=0;
    for(int i=0;i<num.size();i++){
    
    if(int(num[i])%2!=0) ans=i;
    }
    return num.substr(0,ans+1);

    }
};