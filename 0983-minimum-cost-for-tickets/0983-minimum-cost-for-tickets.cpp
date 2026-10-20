class Solution {
public:
    int duration[3]={1,7,30};
    int upper_bound(int day,vector<int>&days){
    int low=0;
    int high=days.size()-1;
    while(low<=high){
    int mid=(low+high)>>1;
    if(days[mid]>=day) high=mid-1;
    else low=mid+1;    
    }
    return low;
    } 
    int travel_tickets(int index,vector<int>&days,vector<int>&costs,vector<int>&dp){
    if(index>=days.size()) return 0;
    if(dp[index]!=-1) return dp[index];
    int min_price=INT_MAX;
    for(int i=0;i<costs.size();i++){
    int new_day=days[index]+duration[i];
    int new_index=upper_bound(new_day,days);
    min_price=min(min_price,costs[i]+travel_tickets(new_index,days,costs,dp));    
    }
    return dp[index]=min_price;     
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int>dp(days.size(),-1);
    sort(days.begin(),days.end());
    return travel_tickets(0,days,costs,dp);    
    }
};