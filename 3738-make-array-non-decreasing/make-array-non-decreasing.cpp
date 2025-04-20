class Solution {
public:
    int maximumPossibleSize(vector<int>& arr) {

        int i=0;
        int j=i+1;
        int n=arr.size();
        int cnt=0;
        while( i<n){

             while(j< n && arr[i]>arr[j]){
                    cnt++;
                    j++;
             }

             i=j; 
             j++;
            //  if(arr[i]<=arr[j]){
            //     i++;
            //     j++;
            //  }           
        }

        return n-cnt; 
        
    }
};