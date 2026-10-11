class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    vector<int>left(26,0);
    vector<int>right(26,0);
    for(int i=0;i<s1.size();i++){
    left[s1[i]-'a']++;    
    }
    int i=0;
    int j=0;
    int n=s1.size();
    right[s2[j]-'a']++;
    while(i<s2.size() && j<s2.size()){
    while(j<s2.size()-1 && j-i+1<n){
    j++;
    right[s2[j]-'a']++;    
    }
    if(j-i+1==n && left==right) return true;
    if(i<s2.size()){
    right[s2[i]-'a']--;    
    i++;
    }
    }
    return false; 
    }
};