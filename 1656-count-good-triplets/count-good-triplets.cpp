class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {

        int n=arr.size();
        vector<int> prefix(1001, 0);
int cnt=0;
        for(int j=0; j< n; j++){
            int mini=INT_MAX;
            for(int k=j+1; k<n ; k++){
                int x= abs(arr[j]-arr[k]);
                if(x>b){
                    continue;
                }

                mini= max(0, max(arr[j]-a,arr[k]-c));
                int maxi= min(1000, min(arr[j]+a,arr[k]+c));

                if(mini<=maxi){
                    if(mini==0){
                        cnt+=prefix[maxi];
                    }
                    else{
                        cnt+= prefix[maxi]-prefix[mini-1];
                    }
                }

            }
            for(int i=arr[j]; i<=1000; i++){
                ++prefix[i];
            }
        }

        return cnt;

        
    }
};