class Solution {
public:
    int mirrorDistance(int n) {
    // int num=0;
    // int temp=n;
    // while(n!=0){
    // num=num*10+(n%10);
    // n/=10;    
    // }
    // return abs(temp-num); 
    string s = to_string(n);
    reverse(s.begin(),s.end());
    int rev_n = stoi(s);
    return abs(n - rev_n);   
    }
};