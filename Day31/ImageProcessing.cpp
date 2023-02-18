#include <bits/stdc++.h>
using namespace std;

/*
Description: There is an mxn image given in front of you. You have to do image processing on the image by colouring it with a given colour using the following algorithm. In the algorithm, you will be given a starting point in the image as (sr,sc) where (0<=s1<m,0<=s2<n) as colour a (color) variable whose color you apply on the image. Colouring of the image should follow these rules-:

 Elements to be coloured should be adjacent to the starting point and have the same value as the starting point.
The adjacent elements should be coloured with the given number (colour)
Will you be able to colour the image?
*/

vector<vector<int>> solution(vector<vector<int>>& image,int sr,int sc,int newColor)
{
    int n=image.size();
    int m=image[0].size();
    
    
    vector<pair<int,int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
    
    
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    int number=image[sr][sc];
    
    image[sr][sc]=newColor;
    
    // Creating queue for bfs
    queue<pair<int,int>>q;
    q.push({sr,sc});
    // Pushing pair of {x, y}

        // Until queue is empty
    while(q.size()!=0){
        pair<int,int>pfront=q.front();
        q.pop();
        
        for(auto d:dir){
            int newRow=pfront.first + d.first;
            int newCol=pfront.second + d.second;
            
            if(newRow>=0 and newCol>=0 and newRow<n and newCol<m and image[newRow][newCol]==number and !visited[newRow][newCol]){
                image[newRow][newCol]=newColor;
                    // Marking {x, y} as visited
                visited[newRow][newCol]=true;
                q.push({newRow,newCol});
            }
        }
    }
    
    return image;
}


int main() 
{
    int n,m;
     //taking inputs
    cin>>n>>m;

    vector<vector<int>>image(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>image[i][j];
        }
    }

    int sr;
    int sc;
    int newColor;
    cin>>sr>>sc>>newColor;

    vector<vector<int>>ans=solution(image,sr,sc,newColor);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
	}