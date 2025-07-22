class Solution {
public:
    int islandPerimeter(vector<vector<int>>& arr) {

        int n=arr.size();
        int m=arr[0].size();
        int cnt=0;
        for(int i=0; i<n ; i++){
            for(int j=0; j< m ; j++){
                
                if(arr[i][j]==1){
                    cnt+=4;
                
                if(i>0 && arr[i-1][j]==1){
                    cnt-=2;

                }

                if(j>0 && arr[i][j-1]==1){
                    cnt-=2;
                }
                }
            }
        }
        return cnt;
        
    }
};