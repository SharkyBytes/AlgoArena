class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = strategy.size();

        // prefix sum of prices
        vector<long long> allsum(n, 0);
        allsum[0] = prices[0];
        for (int i = 1; i < n; i++) {
            allsum[i] = allsum[i - 1] + prices[i];
        }

        // prefix sum of prices*strategy
        vector<long long> prefix(n, 0);
        prefix[0] = 1LL * prices[0] * strategy[0];
        long long sum = prefix[0];
        for (int i = 1; i < n; i++) {
            long long x = 1LL * prices[i] * strategy[i];
            sum += x;
            prefix[i] = prefix[i - 1] + x;
        }

        long long maxi = sum;

        for (int i = 0; i <= n - k; i++) {
            int x = i + k - 1;
            int mid = i + k / 2; // correct midpoint!

            // original contribution of left half [i .. mid-1]
            long long left = prefix[mid - 1] - (i > 0 ? prefix[i - 1] : 0);

            // original contribution of right half [mid .. x]
            long long rightOld = prefix[x] - prefix[mid - 1];

            // new contribution of right half = sum of prices[mid .. x]
            long long rightNew = allsum[x] - (mid > 0 ? allsum[mid - 1] : 0);

            // profit after modification
            long long temp = sum - left - rightOld + rightNew;
            maxi = max(maxi, temp);
        }

        return maxi;
    }
};
