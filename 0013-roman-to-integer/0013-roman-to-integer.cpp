class Solution {
public:
    int romanToInt(string s) {
   unordered_map<char,int> m = {
    {'I',1}, {'V',5}, {'X',10}, {'L',50},
    {'C',100}, {'D',500}, {'M',1000}
};
     int prev=INT_MAX;
     int num=0;
     for(int i=0;i<s.size();i++){
     if(m[s[i]]>prev) num+=(m[s[i]]-2*prev);
     else num+=m[s[i]];
     prev=m[s[i]];   
     }
     return num;  
    }
};