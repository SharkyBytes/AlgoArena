class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {

        int n= colors.length();
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        indegree[it[1]]++;
        }
queue<int> q;
        for(int i=0; i<n ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
vector<vector<int>> dp(n, vector<int>(26,0));

for(int i=0; i< n ; i++){
    dp[i][colors[i]-'a']++;
}
int ans=INT_MIN;
int cnt=0;

        while(!q.empty()){
            int node =q.front();
            cnt++;
            q.pop();
            for(auto it: adj[node]){
                for(int i=0; i< 26; i++){
                    dp[it][i]= max(dp[it][i], dp[node][i]+ (colors[it]-'a'==i));
                }
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            ans=max(ans,*max_element(dp[node].begin(), dp[node].end()));
        }
        if(cnt<n){
            return -1;
        }

return ans;      
    }
};