class Solution {
public:
   double dfs(string first_val,string target_val, map<string,vector<pair<string,double>>>&m,unordered_set<string>&st){
   st.erase(first_val);
   for(auto it : m[first_val]){
   if(it.first==target_val) return it.second;
   else if(st.find(it.first)!=st.end()){
   double ans=dfs(it.first,target_val,m,st);
   if(ans!=-1.0) return ans*it.second; 
   }  
   }
   return -1.0;
   }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    map<string,vector<pair<string,double>>>m;
   
    for(int i=0;i<equations.size();i++){
    string first_val=equations[i][0];
    string sec_val=equations[i][1];
   
    double val=values[i];
    m[first_val].push_back({sec_val,val});
    m[sec_val].push_back({first_val,(1.0/val)});    
    }
    vector<double>result;
    for(int i=0;i<queries.size();i++){
    string first_val=queries[i][0];
    string sec_val=queries[i][1];
   if (m.find(first_val) == m.end() ||
    m.find(sec_val) == m.end()) {
    result.push_back(-1.0);
}
else if (first_val == sec_val) {
    result.push_back(1.0);
}
else {
    unordered_set<string> st;

    for (auto &it : m) {
        st.insert(it.first);
    }

    double ans = dfs(first_val, sec_val, m, st);
    result.push_back(ans);
}   
    }
    return result;    
    }
};