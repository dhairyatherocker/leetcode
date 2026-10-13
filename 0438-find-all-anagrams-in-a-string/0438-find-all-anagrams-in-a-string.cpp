class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    int n=p.size();
    vector<int>target(26,0);
    vector<int>dummy(26,0);
    vector<int>result;
    int i=0;
    int j=0;
    for(int k=0;k<n;k++){
    target[p[k]-'a']++;    
    }
    while(j<s.size()){
    while(j<s.size() && j-i+1<=n){    
    dummy[s[j]-'a']++;
    j++;    
    }
    if(j-i==n && dummy==target){result.push_back(i);
    }
    dummy[s[i]-'a']--;
    i++;
    }
    return result;

    }
};