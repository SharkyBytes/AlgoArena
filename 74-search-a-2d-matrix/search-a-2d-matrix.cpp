class Solution {
public:
   bool searchMatrix(vector<vector<int>>& mat, int target) {
    int N = mat.size(), M = mat[0].size();

    // Start from top-right corner
    int row = 0, col = M - 1;

    while (row < N && col >= 0) {
        if (mat[row][col] == target) return true;

        if (mat[row][col] < target) {
            // Binary search in the column to find the first row
            // where value >= target
            int low = row + 1, high = N - 1, lb = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mat[mid][col] >= target) {
                    lb = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (lb == -1) return false; // No possible row found
            // Binary search in row lb
            int l = 0, r = M - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (mat[lb][m] == target)
                    return true;
                else if (mat[lb][m] < target)
                    l = m + 1;
                else
                    r = m - 1;
            }
            return false; // Not found in that row
        } else {
            col--; // Move left
        }
    }

    return false; // Exhausted all possibilities
}

};