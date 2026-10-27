class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
    vector<int>first(26,0);
    vector<int>second(26,0);
    for(int i=0;i<ransomNote.size();i++) first[ransomNote[i]-'a']++;
    for(int i=0;i<magazine.size();i++) second[magazine[i]-'a']++;
    for(int i=0;i<26;i++){
    if(first[i]>second[i]) return false;    
    }
    return true;    
    }
};