class Solution {
public:
    int M=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
     int n=arr.size();   
     vector<int>pse(n);
     vector<int>nse(n);
     stack<int>s;
     stack<int>s1;
    //  nse 

     for(int i=n-1;i>=0;i--){
     while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
     if(s.empty()) nse[i]=n;
     else nse[i]=s.top();
     s.push(i);   
     }

    //  pse

    for(int i=0;i<n;i++){
     while(!s1.empty() && arr[s1.top()]>=arr[i]) s1.pop();
     if(s1.empty()) pse[i]=-1;
     else pse[i]=s1.top();
     s1.push(i);   
     }

     long long count=0;
     for(int i=0;i<n;i++){
     long long left=i-pse[i];
     long long right=nse[i]-i;
     count=(count+((left*right)*arr[i])%M)%M;   
     } 
     return count;

    }
};