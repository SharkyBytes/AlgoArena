class Solution {
public:
    vector<int> dr = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<int>>& arr) {

        arr[i][j] = 1;
        int n= arr.size();
        int m= arr[0].size();
        for (int p = 0; p < 4; p++) {
            int x = dr[p] + i;
            int y = dy[p] + j;
            if (x < 0 || y < 0 || y >= m || x >= n || arr[i][j]==0) {
                continue;
            }
            if (arr[x][y] == 0) {
                dfs(x, y, arr);
            }
        }
    }
    int closedIsland(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        for (int i = 0; i < m; i++) {
            if (arr[0][i] == 0) {
                dfs(0, i, arr);
            }
            if (arr[n - 1][i] == 0)
                dfs(n - 1, i, arr);
        }
        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 0)
                dfs(i, 0, arr);
            if (arr[i][m - 1] == 0)
                dfs(i, m - 1, arr);
        }
int cnt=0;
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (arr[i][j] == 0) {
                    dfs(i, j , arr);
                    cnt++;

                }
            }
        }

        return cnt;
    }
};