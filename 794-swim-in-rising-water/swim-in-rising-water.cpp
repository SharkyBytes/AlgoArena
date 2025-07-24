class Solution {
public:

vector<int> dx= {-1, 1, 0, 0};
vector<int> dy= {0,0,-1, 1};

    int swimInWater(vector<vector<int>>& arr) {

        int n=arr.size();
        int m=arr[0].size();


        vector<vector<int>> dist(n, vector<int> (m , 1e5));

       priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        pq.push({arr[0][0], {0, 0}});
        dist[0][0]=arr[0][0];
        while(!pq.empty()){
            auto p=pq.top();
            int dis=p.first;
            int i=p.second.first;
            int j=p.second.second;
            pq.pop();
            for(int a=0; a< 4; a++){
                int x= dx[a]+i;
                int y= dy[a]+j;
                if(x<0 || y<0 || x>=n || y>=n)continue;

                if(dist[x][y]>dis){
                    pq.push({max(arr[x][y], dis), {x,y}});
                    dist[x][y]=max(arr[x][y], dis);
                }
             
            }
        }
        return dist[n-1][m-1];
        
    }
};