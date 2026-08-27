class Solution {
public:
    int findchar(string s,int goal){
    int left=0;
    int right=0;
    int count=0;
    unordered_map<char,int>st;
    while(right<s.size()){
    st[s[right]]++;
    while(left<=right && st.size()>goal){
    st[s[left]]--;
    if(st[s[left]]==0) st.erase(s[left]);
    left++;   
    }
    if(st.size()<=goal) count=count+(right-left)+1;
    right++;
    }
    return count;
    } 
    int numberOfSubstrings(string s) {
    int count1=findchar(s,3);
    int count2=findchar(s,2);
    return count1-count2;    
    }
};