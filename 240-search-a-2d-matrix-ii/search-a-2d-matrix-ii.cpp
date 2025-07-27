class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tgt) {

        int n=arr.size();
        int m=arr[0].size();
        int row=0;
         int col=m-1;
         while(row<n && col>=0){
            if(arr[row][col]==tgt){
                return true;
            }
             if(arr[row][col]<tgt){
                row++;
             }
             else{
                col--;
             }
         }

         return false;


        
    }
};