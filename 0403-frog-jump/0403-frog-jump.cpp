class Solution {
public:
    int drow[3]={-1,0,1};
    int jump(long long index,long long prev_step,map<pair<long long,long long>,bool>&dp,vector<int>&stones,unordered_map<long long,long long>&m){
    if(index==stones.size()-1) return true;
    if(dp.find({index,prev_step})!=dp.end()) return dp[{index,prev_step}];
    for(auto it : drow){
    long long new_step=it+prev_step;
    long long new_pos=new_step+stones[index];
    if(new_step>0 && m.find(new_pos)!=m.end() && jump(m[new_pos],new_step,dp,stones,m)==1) return dp[{index,prev_step}]=1;    
    }
    return dp[{index,prev_step}]=0;
    }
    bool canCross(vector<int>& stones) {
    map<pair<long long,long long>,bool>dp;
    unordered_map<long long,long long>m;
    for(int i=0;i<stones.size();i++) m[stones[i]]=i;
    return jump(0,0,dp,stones,m);     
    }
};