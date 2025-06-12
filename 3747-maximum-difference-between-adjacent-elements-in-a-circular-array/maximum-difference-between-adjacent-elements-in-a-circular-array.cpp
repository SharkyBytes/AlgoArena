class Solution {
public:
    int maxAdjacentDistance(vector<int>& arr) {

        int n=arr.size();
        int diff=INT_MIN;
        for(int i=1; i< n; i++){

            diff=max(diff, abs(arr[i]-arr[i-1]));
            
        }
        diff=max(diff, abs(arr[n-1]-arr[0]));

        return diff;

        
        
    }
};