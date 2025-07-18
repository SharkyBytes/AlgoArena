class Solution {
public:
    bool isBipartite(vector<vector<int>>& arr) {

        int n = arr.size();
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {
                queue<int> q;
                q.push(i);
                col[i] = 0;

                while (!q.empty()) {
                    int x = q.front();
                    q.pop();

                    for (auto it : arr[x]) {
                        if (col[it] == -1) {
                            col[it] = !col[x];
                            q.push(it);
                        } else if (col[it] == col[x]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
