class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> arr(26);  // One stack for each character 'a' to 'z'

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                int st = 0;
                // Find the smallest non-empty stack
                while (st < 26 && arr[st].empty()) {
                    st++;
                }
                if (st < 26) {
                    int x = arr[st].top();
                    arr[st].pop();
                    s[x] = '*';  // Mark the character for deletion
                }
            } else {
                arr[s[i] - 'a'].push(i);  // Push index of character
            }
        }

        // Build the result string by skipping '*'
        string result;
        for (char c : s) {
            if (c != '*') {
                result += c;
            }
        }

        return result;
    }
};
