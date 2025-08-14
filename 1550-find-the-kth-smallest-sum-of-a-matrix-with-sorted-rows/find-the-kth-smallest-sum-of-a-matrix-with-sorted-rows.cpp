class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {

        int n=mat.size();
        int m=mat[0].size();
        vector<int> temp;
        for(int i=0; i< m; i++){
            temp.push_back(mat[0][i]);
        }

        sort(temp.begin(), temp.end());


        for(int i=1; i<n ; i++){
            vector<int> curr;
            for(int j=0; j< m ; j++){
                for(auto it : temp){
                    curr.push_back(it+mat[i][j]);
                }
            }

            sort(curr.begin(), curr.end());
            temp.clear();

            for(int p=0; p<min((int)curr.size(), k); p++){
                temp.push_back(curr[p]);
            }
        }

        return temp[k-1];


        
    }
};