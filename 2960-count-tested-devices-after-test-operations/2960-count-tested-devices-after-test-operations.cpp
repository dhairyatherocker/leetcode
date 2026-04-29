class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
    int count=0;
    int operations=0;
    for(int i=0;i<batteryPercentages.size();i++){
    batteryPercentages[i]=max((batteryPercentages[i]+operations),0);    
    if(batteryPercentages[i]>0){
    operations--;
    count++;    
    }}
    return count;
    }
};