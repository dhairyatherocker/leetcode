class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int>v;
    int n=asteroids.size();
    stack<int>s;
    for(int i=0;i<n;i++){
    if(asteroids[i]>0) s.push(asteroids[i]);
    else{
    bool mark=false;     
    while(!s.empty() && s.top()>0 && s.top()<=abs(asteroids[i])){
    if(s.top()==abs(asteroids[i])){
    mark=true;
    s.pop();
    break;    
    }
    s.pop();    
    }
    if(!mark && s.empty()) s.push(asteroids[i]);
    else if(!s.empty() && s.top()<0 && !mark) s.push(asteroids[i]);    
    }    
    } 
    while(!s.empty()){
    v.push_back(s.top());
    s.pop();    
    }
    reverse(v.begin(),v.end());
    return v;
    }
};