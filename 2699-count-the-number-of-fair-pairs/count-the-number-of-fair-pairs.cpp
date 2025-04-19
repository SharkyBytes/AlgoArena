class Solution {
public:
    long long countFairPairs(vector<int>& arr, int lower, int upper) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        long long cnt = 0;

        for (int i = 0; i < n; i++) {
            int x = lower - arr[i];
            int y = upper - arr[i];

            
            int p = lower_bound(arr.begin() + i + 1, arr.end(), x) - arr.begin();
            int q = upper_bound(arr.begin() + i + 1, arr.end(), y) - arr.begin() - 1;

            if (p <= q) {
                cnt += (q - p + 1);
            }
        }

        return cnt;
    }
};
