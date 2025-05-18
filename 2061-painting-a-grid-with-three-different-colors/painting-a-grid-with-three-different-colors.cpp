class Solution {
public:
    int mod = 1e9 + 7;

    void generate(int m, vector<vector<int>>& patterns, vector<int>& curr) {
        if (curr.size() == m) {
            patterns.push_back(curr);
            return;
        }

        for (int color = 0; color < 3; ++color) {
            if (curr.empty() || curr.back() != color) {
                curr.push_back(color);
                generate(m, patterns, curr);
                curr.pop_back();
            }
        }
    }

    int colorTheGrid(int m, int n) {
        vector<vector<int>> patterns;
        vector<int> curr;
        generate(m, patterns, curr);

        int sz = patterns.size();
        vector<vector<int>> valid(sz);

        for (int i = 0; i < sz; ++i) {
            for (int j = 0; j < sz; ++j) {
                bool ok = true;
                for (int k = 0; k < m; ++k) {
                    if (patterns[i][k] == patterns[j][k]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) valid[i].push_back(j);
            }
        }

        vector<int> dp(sz, 1);

        for (int i = 1; i < n; ++i) {
            vector<int> new_dp(sz, 0);
            for (int j = 0; j < sz; ++j) {
                for (int k : valid[j]) {
                    new_dp[j] = (new_dp[j] + dp[k]) % mod;
                }
            }
            dp = new_dp;
        }

        int result = 0;
        for (int val : dp) result = (result + val) % mod;
        return result;
    }
};
