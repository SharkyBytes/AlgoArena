class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        
       const int MOD = 1e9 + 7;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int remain = target - nums[i];
            if (nums[i] > remain) break;

            int j = upper_bound(nums.begin() + i, nums.end(), remain) - nums.begin();

            if (j > i) {
                ans = (ans + pow2[j - i - 1]) % MOD;
            }
        }
        return ans;
    }
};