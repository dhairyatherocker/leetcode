class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    map<string,vector<string>>m;
    for(int i=0;i<products.size();i++){
    string ans="";    
    for(int j=0;j<products[i].size();j++){
    ans+=products[i][j];
    m[ans].push_back(products[i]);
    }    
    }
    string ans="";
    vector<vector<string>>result;
    for(int i=0;i<searchWord.size();i++){
    ans+=searchWord[i];
    if(m.find(ans)!=m.end()){
    vector<string>arr=m[ans];    
    sort(arr.begin(),arr.end());
    vector<string>temp;
    for(int j=0;j<arr.size() && j<3;j++) temp.push_back(arr[j]);
    result.push_back(temp);     
    }
    else result.push_back({});    
    }
    return result;    
    }
};