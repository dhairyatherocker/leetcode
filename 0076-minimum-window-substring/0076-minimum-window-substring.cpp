class Solution {
public:
    string minWindow(string s, string t) {
    // int min_len=INT_MAX;
    // string ans="";
    // int i=0;
    // int j=0;
    // int formed=0;
    // unordered_map<char,int>m_s;
    // unordered_map<char,int>m_t;
    // for(auto it : t) m_t[it]++;
    // int required=m_t.size();
    // while(j<s.size()){
    // if(m_t.find(s[j])!=m_t.end()){
    // m_s[s[j]]++;
    // if(m_s[s[j]]==m_t[s[j]]) formed++;    
    // }
    // while(formed==required && i<=j){
    // if((j-i+1)<min_len){
    //  min_len=j-i+1;
    //  ans=s.substr(i,j-i+1);    
    // }
    // if(m_t.find(s[i])!=m_t.end()){
    // if(m_s[s[i]]==m_t[s[i]]){
    // formed--;    
    // }
    // m_s[s[i]]--;
    // }
    // i++;
    // }
    // j++;
    // }
    // return ans;


   
    if (t.size() > s.size()) return "";

    vector<int> need(128, 0), window(128, 0);

    for (char c : t) need[c]++;

    int formed = 0;
    int required = t.size();
    int left = 0, start = 0;
    int min_len = INT_MAX;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (need[c] > 0 && window[c] <= need[c]) {
            formed++;
        }

        while (formed == required) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                start = left;
            }

            char ch = s[left];
            window[ch]--;

            if (need[ch] > 0 && window[ch] < need[ch]) {
                formed--;
            }

            left++;
        }
    }

    return min_len == INT_MAX ? "" : s.substr(start, min_len);
}    
    
};