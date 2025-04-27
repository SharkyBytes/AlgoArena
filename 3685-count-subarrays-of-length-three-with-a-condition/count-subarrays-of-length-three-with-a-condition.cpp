class Solution {
public:
    int countSubarrays(vector<int>& arr) {
        int cnt=0;
        int n=arr.size();
        for(int i=0; i< n-2; i++){
            int x=arr[i];
            int y= arr[i+1];
            int z=arr[i+2];

            if(y%2==0){

            if(y/2 == (x+z)){
                cnt++;
            }
            }
        }

        return cnt;
    }
};