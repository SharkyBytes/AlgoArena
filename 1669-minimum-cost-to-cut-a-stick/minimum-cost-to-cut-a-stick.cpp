class Solution {
public:
    int minCost(int n, vector<int>& cuts) {

        int m=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());


        vector<vector<int>> dp(m+2, vector<int> (m+2, 0));

        for(int len=1; len<=m ; len++){
            for(int i=1; i+len-1<=m ; i++){

                int j= i+len-1;
                int mini=INT_MAX;
                int cost= cuts[j+1]-cuts[i-1];
                for(int k=i; k<=j;k++){
                    mini=min(mini, dp[i][k-1]+ dp[k+1][j]+cost);
                }

                dp[i][j]=mini;
            }
        }

        return dp[1][m];
        
    }
};