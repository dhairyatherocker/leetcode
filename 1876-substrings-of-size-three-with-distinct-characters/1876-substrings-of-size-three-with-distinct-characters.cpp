// class Solution {
// public:
//     int countGoodSubstrings(string s) {
//     int count=0;
//     // unordered_set<string>st;
//     if(s.size()<3) return 0;
//     for(int i=0;i<s.size()-2;i++){
//     unordered_set<char>m;
//     string trav=""; 
//     for(int j=i;j<i+3;j++){
//     trav+=s[j];
//     m.insert(s[j]);
//     if(trav.size()==3 && m.size()==3) count++;
//     }    
//     }
//     return count;    
//     }
// };
class Solution {
public:
    int countGoodSubstrings(string s) {
        if(s.size() < 3) return 0;

        vector<int> freq(26, 0);
        int count = 0;

        // first window of size 3
        for(int i = 0; i < 3; i++) {
            freq[s[i] - 'a']++;
        }

        if(freq[s[0]-'a'] <= 1 &&
           freq[s[1]-'a'] <= 1 &&
           freq[s[2]-'a'] <= 1) {
            count++;
        }

        // slide the window
        for(int i = 3; i < s.size(); i++) {
            // remove left char
            freq[s[i-3] - 'a']--;

            // add new char
            freq[s[i] - 'a']++;

            // check distinct
            if(freq[s[i] - 'a'] == 1 &&
               freq[s[i-1] - 'a'] == 1 &&
               freq[s[i-2] - 'a'] == 1) {
                count++;
            }
        }

        return count;
    }
};