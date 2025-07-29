class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& arr) {

        int n=arr.size();
        vector<int> num(32, -1);
        vector<int> ans(n, 1);
        for(int i=n-1; i>=0; i--){
            int curr=arr[i];

            for(int j=0 ;j< 32; j++){
                int temp= curr>>j & 1;
                if(temp>0){
                    num[31-j]=i;
                }
            }
            int far=i;
            for(int j=0; j< 32; j++){
                if(num[j]!=-1){
                    far=max(far, num[j]);
                }

            }
            ans[i]= (far-i+1); 
        }
        return ans;
        
    }
};