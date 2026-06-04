class Solution {
public:
    int characterReplacement(string s, int k) {
    int left=0;
    int right=0;
    unordered_map<char,int>m;
    int maxlen=0;
    int valid_len=0;
    while(right<s.size()){
    m[s[right]]++;
    maxlen=max(maxlen,m[s[right]]);
    while(left<=right && ((right-left+1-maxlen)>k)){
    m[s[left]]--;
    maxlen=0;
    for(auto it : m) maxlen=max(maxlen,it.second);
    left++;    
    }
    if((right-left+1-maxlen)<=k) valid_len=max(valid_len,right-left+1);
    right++;
    }
    return valid_len;    
    }
};