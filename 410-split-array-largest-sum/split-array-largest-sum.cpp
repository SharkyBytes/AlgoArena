class Solution {
public:

int  count (int mid, vector<int> & arr, int k ){
    int cnt=1;
    int n=arr.size();
    int curr=0;
    for(int i=0; i< n ; i++){
        if(curr+arr[i]>mid){
            cnt++;
            curr=arr[i];
        }
        else{
            curr+=arr[i];
        }
    }
    return cnt;
}
    int splitArray(vector<int>& nums, int k) {

        int n= nums.size();
        int s=*max_element(nums.begin(), nums.end());;
        int e= accumulate(nums.begin(), nums.end(), 0);
        while(s<=e){
            int mid=s+(e-s)/2;
            if(count(mid, nums,k)>k){
                s= mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s;
        
    }
};