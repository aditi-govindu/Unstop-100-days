#include <bits/stdc++.h>
using namespace std;

/*
Description: B.N Sahoo,gives the two integers, x and y to you.Here your current position on a Cartesian grid: (x, y). You'll also be provided an array points, where each point[i] = [ai, bi] denotes the existence of a point at that location (ai, bi). If a point has the same x-coordinate or y-coordinate as your location, it is legitimate.

B.N Sahoo told you to return the index (0-indexed) of the valid point closest to your current position in Manhattan distance. If there are numerous valid points, return the one with the lowest index. Return -1 if there are no valid points.

abs(x1 - x2) + abs(x1 - x2) is the Manhattan distance between two points (x1, y1) and (x2, y2) (y1 - y2).
*/
    
int nearestValidPoint(int x, int y, vector<pair<int,int>>& points) {
        //first of all it should share either x or y cordinate. If it does not then return -1;
        int idx = -1;
        int minDistance = INT_MAX;
        for(int i=0;i<points.size();i++){
            if(points[i].first == x){ //checking if the X cordinate is same or not.
                //if point x is same
                //then storing the index. Only if the Distance is minimum. If it is same then we have to return the val with minimum index.
				if(abs(points[i].second-y)<minDistance){ 
                    idx = i;
                }
                minDistance = min(minDistance, abs(points[i].second-y)); //calculating the minDistance so keep track of what is the minimum distance that we need in order to get same points.
            }
            else if(points[i].second == y){
                //if point y is same
                if(abs(points[i].first-x)<minDistance){
                    idx = i;
                }
                minDistance = min(minDistance, abs(points[i].first-x));
            }
        }
		// now idx has the minimum index. If it did not found any index, then it have -1. Which is acc. to ques we have to return in case we did not found any solution.
        return idx;
    }
int main() {
     
       int x,y;
       cin>>x>>y;
       
       int n;
       cin>>n;
       
       
       vector<pair<int,int>> points(n);
       
       
       for(auto &x : points){
           cin>>x.first>>x.second;
       }
       
       int ans=nearestValidPoint(x,y,points);
       
       
       cout<<ans<<endl;

}