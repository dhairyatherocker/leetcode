class Solution {
public:
    int mySqrt(int x) {
    int low=0;
    int high=x;
    while(low<=high){
    long long mid=(low+high)>>1;
    long long left=pow(mid,2);
    long long right=pow(mid+1,2);
    if(left<=x && right>x) return mid;
    else if(left>x) high=mid-1;
    else low=mid+1;    
    }
    return -1;    
    }
};