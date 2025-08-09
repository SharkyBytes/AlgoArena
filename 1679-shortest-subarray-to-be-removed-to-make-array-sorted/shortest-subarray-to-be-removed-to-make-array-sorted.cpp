class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        int n=arr.size();
        int left=0;
        int right = n-1;
        while(left+1<n && arr[left]<=arr[left+1]){
            left++;
        }

        if(left==n-1){
            return 0;
        }

        while(right>0 && arr[right-1]<=arr[right]){
            right--;
        }

        int mini=min(n-left-1, right);
        int j=right;
        for(int i=0; i<=left && j<n;){
            if(arr[i]<=arr[j]){
                mini=min(mini, j-i-1);
                i++;
            }
            else{
                j++;
            }
        }
        return mini;
        
    }
};