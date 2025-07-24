class Solution {
public:

vector<int> dx={-1, 1, 0, 0};
vector<int> dy= { 0,0,-1, 1};
void bfs(int i , int j , vector<vector<int>> & arr){
    int n=arr.size();
    int m=arr[0].size();

    queue<pair<int,int>>q;
    q.push({i, j});
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        arr[top.first][top.second]=1;

        for(int p=0; p< 4 ; p++){
        int x= top.first+dx[p];
        int y= dy[p]+top.second;

        if(x<0 || y<0 || x>=n || y>=n){
            continue;
        } 
        if(arr[x][y]==0){
            q.push({x,y});
        arr[x][y]=1;

        }
        }
    }
}
    int regionsBySlashes(vector<string>& arr) {

        int n=arr.size();
        int m=arr[0].size();

        vector<vector<int>> ans(3*n , vector<int> (3*m, 0));

        for(int i=0; i< n ; i++){
            for(int j=0; j<m ; j++){

                int brow= i*3;
                int bcol=j*3;

                if(arr[i][j]=='/'){
                   ans[brow][bcol+2]=1;
                   ans[brow+1][bcol+1]=1;
                   ans[brow+2][bcol]=1;
                }
                else if (arr[i][j]=='\\'){
                    ans[brow][bcol]=1;
                    ans[brow+1][bcol+1]=1;
                    ans[brow+2][bcol+2]=1;

                }
            }
        }
        
        int cnt=0;
     
        for(int i=0; i<3*n; i++){
            for(int j=0; j<3*m; j++){
                if(ans[i][j]==0){
                    bfs(i, j, ans);
                    cnt++;
                }

            }
        }

        return cnt;
    }
};