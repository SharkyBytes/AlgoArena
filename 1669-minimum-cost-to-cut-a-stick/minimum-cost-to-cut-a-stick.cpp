class Solution {
public:

vector<vector<int>> dp;
    int recur(int i, int j, vector<int>& cuts) {
        if (i > j) return 0;  // no cuts possible

        if(dp[i][j]!=-1)return dp[i][j];

        int mini = INT_MAX;
        for (int k = i; k <= j; k++) {
            int cost = (cuts[j+1] - cuts[i-1]) +
                        recur(i, k-1, cuts) +
                        recur(k+1, j, cuts);
            mini = min(mini, cost);
        }
        return dp[i][j]= mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        dp.assign(m+2, vector<int> (m+2 , -1));

        return recur(1, m, cuts);
    }
};
