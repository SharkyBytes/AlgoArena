class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& arr) {

        int n=arr.size();
        int m=arr[0].size();

        int s=0;
        int e=m-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int maxrow=0;
            for(int i=0; i< n ; i++){
                if(arr[i][mid]>arr[maxrow][mid]){
                    maxrow=i;
                }
            }

            if((mid==m-1 || arr[maxrow][mid]> arr[maxrow][mid+1]) &&(mid==0 || arr[maxrow][mid]>arr[maxrow][mid-1])){
                return {maxrow, mid};
            }
            else if((mid!=0 && arr[maxrow][mid-1] > arr[maxrow][mid])){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return {-1,-1};
        
    }
};