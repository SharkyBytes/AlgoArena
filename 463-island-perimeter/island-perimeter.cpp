class Solution {
public:
    int islandPerimeter(vector<vector<int>>& arr) {

        int n=arr.size();
        int m= arr[0].size();
        vector<int> dx={-1, 0 , 1, 0};
        vector<int> dy= {0, -1, 0, 1};
        int cnt=0;
        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){
                if(arr[i][j]==1){
                for(int p=0; p<4; p++){
                    
                    int x= dx[p]+i;
                    int y= dy[p]+j;
                    if(x<0 || y<0 | x>=n|| y>=m || arr[x][y]==0){
                        cnt++;
                    }
                    

                }
                }
            }
        }

        return cnt;
        
    }
};