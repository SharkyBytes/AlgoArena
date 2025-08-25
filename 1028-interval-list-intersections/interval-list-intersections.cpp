class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {

        int n=f.size();
        int m=s.size();
        vector<vector<int>> ans;
        int i=0;
        int j=0;
        while(i<n && j<m){
            int st=max(f[i][0], s[j][0]);
            int end=min(f[i][1], s[j][1]);

             if (st <= end) {
                ans.push_back({st, end});
            }

            if(f[i][1]==s[j][1]){
                i++;
                j++;
            }

           else if(f[i][1]<s[j][1]){
                i++;
            }
            else{
                j++;
            }

        }
        return ans;
        
    }
};