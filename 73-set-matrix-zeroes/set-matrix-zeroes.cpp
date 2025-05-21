class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {

        bool firstrow=0 , firstcol=0;
        int n=arr.size();
        int m=arr[0].size();

        for(int i=0; i<m; i++){
            if(arr[0][i]==0){
                firstrow=true;
                break;

            }
        }
        
        for(int j=0;j<  n; j++){
            if(arr[j][0]==0){
                firstcol=true;
                break;
            }

        }

        for(int i=1; i< n; i++){
            for(int j=1; j< m; j++){
                if(arr[i][j]==0){
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }

        for(int i=1; i< n; i++){
            for(int j=1; j< m ; j++){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }

        if(firstrow){
         for(int i=0; i<m; i++){
           arr[0][i]=0;
        }
        }
        if(firstcol)
        { for(int i=0; i<n; i++){
           arr[i][0]=0;
        }

        }
    }
};