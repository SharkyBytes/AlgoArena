class Solution {
public:
    int numberOfArrays(vector<int>& arr, int lower, int upper) {

    long  sum = 0;
        long  mini = 0;
        long  maxi = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            mini = min(mini, sum);
            maxi = max(maxi, sum);
        }

        long  ans= upper -lower - maxi +mini +1;

       return max(0L, ans);
        
    }
};