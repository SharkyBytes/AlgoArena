class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();

        vector<int> ans;

        for(int i=0; i<=m+n-2; i++){
            if(i%2==0){
                int first=i;
                int second=0;
                for(int k=0; k<=i ; k++){
                    if(first>=0 && second<=m-1 && first<=n-1 && second>=0){
                        ans.push_back(mat[first][second]);
                       
                    }
                    first--;
                    second++;
                }
            }

            else{
                int second= i;
                int first= 0;
                 for(int k=0; k<=i ; k++){
                    if(first>=0 && second<=m-1 && first<=n-1 && second>=0){
                        ans.push_back(mat[first][second]);
                       
                    }
                    first++;
                    second--;
                }
            }
        }
        return ans;
        
    }
};