class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//     int i=0;
//     int stops=0;
//     int fuel_consumption=0;
//     if(startFuel>=target) return 0;
//     while(target!=0){      
//     priority_queue<pair<int,int>>pq;
//     for(;i<stations.size();i++){
//     if((stations[i][0]-fuel_consumption)>startFuel) break;
//     pq.push({stations[i][1],stations[i][0]-fuel_consumption});    
//     }
//     if(pq.empty()) return -1;
//     auto [fuel,consumption]=pq.top();
//     startFuel=startFuel-consumption+fuel;
//     target-=consumption;
//     fuel_consumption+=consumption;
//     stops++;
//     if(target<=startFuel) return stops; 
//     }
//   return 0;

    priority_queue<int> pq;
    int fuel = startFuel;
    int stops = 0;
    int i = 0;

    while (fuel < target) {
        while (i < stations.size() && stations[i][0] <= fuel) {
            pq.push(stations[i][1]);
            i++;
        }

        if (pq.empty()) return -1;

        fuel += pq.top();
        pq.pop();
        stops++;
    }

    return stops;

    }
};