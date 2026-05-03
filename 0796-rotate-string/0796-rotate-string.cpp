#include<bits/stdc++.h>
class Solution {
public:
    bool rotateString(string s, string goal) {
    int len=s.size();
    if(s==goal) return true;
    for(int i=1;i<=len;i++){
    reverse(s.begin()+1,s.end());
    reverse(s.begin(),s.end());
    if(s==goal) return true;
    }
    return false;    
    }
};