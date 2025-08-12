class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n= matrix.size();
        int m= matrix[0].size();

        int s=0;
        int e= m*n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int x= mid/m;
            int y= mid%m;
            if(matrix[x][y]==target){
                return true;
            }
            else if(matrix[x][y]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return false;
    }
};