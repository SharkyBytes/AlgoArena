class Solution {
public:
vector<int> dx= {-1, 0 , 1,0};
vector<int> dy= { 0, -1, 0, 1};

bool dfs(int i , int j, vector<vector<int>> & arr, vector<vector<int>> & p){
    int n=arr.size();
    int m= arr[0].size();

    if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 0) {
            return true;
        }
 
        arr[i][j]=0;
    
bool ans=(p[i][j]==1);
    for(int z=0;z< 4 ; z++){

        int x= dx[z]+i;
        int y= dy[z]+j;

        if(x<0 || y<0 || y>=m || x>=n){
            continue;
        }
        else{
            if(arr[x][y]==1){
                ans&= dfs(x, y, arr, p);
            }
        }

    }

    return ans;
}
    int countSubIslands(vector<vector<int>>& p, vector<vector<int>>& arr) {

        int n=arr.size();
        int m= arr[0].size();
        int cnt=0;
        for(int i=0; i< n;i++){
            for(int j=0; j< m ; j++){

                if(arr[i][j]==1){
                   bool x= dfs(i, j, arr, p);
                   if(x)cnt++;
                }


            }
        }



        return cnt;
    }
};