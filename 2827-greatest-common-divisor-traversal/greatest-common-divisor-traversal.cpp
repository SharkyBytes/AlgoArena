class Solution {
public:
    vector<int> spf;

    void buildSieve(int maxNum) {
        spf.resize(maxNum + 1);
        for (int i = 0; i <= maxNum; i++) spf[i] = i;
        for (int i = 2; i * i <= maxNum; i++) {
            if (spf[i] == i) {
                for (int j = i; j <= maxNum; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
    }

    vector<int> getPrimeFactors(int num) {
        unordered_set<int> factors;
        while (num > 1) {
            factors.insert(spf[num]);
            num /= spf[num];
        }
        return vector<int>(factors.begin(), factors.end());
    }

    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) dfs(neighbor, graph, visited);
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        int maxNum = *max_element(nums.begin(), nums.end());
        buildSieve(maxNum);

        unordered_map<int, vector<int>> primeToIndices;
        for (int i = 0; i < n; i++) {
            vector<int> primes = getPrimeFactors(nums[i]);
            for (int p : primes) {
                primeToIndices[p].push_back(i);
            }
        }

        // Build graph
        vector<vector<int>> graph(n);
        for (auto& [prime, indices] : primeToIndices) {
            for (int i = 1; i < indices.size(); i++) {
                graph[indices[i - 1]].push_back(indices[i]);
                graph[indices[i]].push_back(indices[i - 1]);
            }
        }

        // Find index of max number to start DFS
        int start = find(nums.begin(), nums.end(), maxNum) - nums.begin();
        vector<bool> visited(n, false);
        dfs(start, graph, visited);

        // Check if all nodes visited
        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
