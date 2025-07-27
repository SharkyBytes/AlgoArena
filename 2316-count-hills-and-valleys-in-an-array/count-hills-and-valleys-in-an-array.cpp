class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size();

vector<int> arr;
arr.push_back(nums[0]);
        for(int i=1; i<n ; i++){
            if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                arr.push_back(nums[i]);
            }
        }

        n=arr.size();
for(auto it : arr){
    cout<<it<<endl;
}

        int cnt=0;

        for(int i=1; i< n-1 ; i++){
            if(arr[i]>arr[i-1] && arr[i]> arr[i+1] || (arr[i]< arr[i-1] && arr[i]< arr[i+1] )){
                cnt++;
            }


        }

        return cnt;
        
    }
};