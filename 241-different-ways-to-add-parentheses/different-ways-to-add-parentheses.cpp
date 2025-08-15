class Solution {
public:
    vector<int> dp[20][20];

    int extract_number(int st, int e, const string &s) {
        int num = 0;
        while (st <= e) {
            num = num * 10 + (s[st] - '0');
            st++;
        }
        return num;
    }

    vector<int> recur(int st, int e, const string &s) {
        if (dp[st][e].size()!=0) {
            return dp[st][e];
        }

        vector<int> ans;
        for (int i = st; i <= e; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = recur(st, i - 1, s);
                vector<int> right = recur(i + 1, e, s);

                for (auto l : left) {
                    for (auto r : right) {
                        if (s[i] == '+') ans.push_back(l + r);
                        else if (s[i] == '-') ans.push_back(l - r);
                        else ans.push_back(l * r);
                    }
                }
            }
        }

        if (ans.size()==0) { 
            int x = extract_number(st, e, s);
            dp[st][e] = {x};
            return dp[st][e];
        }

        return dp[st][e] = ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        return recur(0, n - 1, expression);
    }
};
