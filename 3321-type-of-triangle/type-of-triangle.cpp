class Solution {
public:
    string triangleType(vector<int>& arr) {
        string ans;

        sort(arr.begin(), arr.end());
        // First, check if it's a valid triangle
        if (arr[0] + arr[1] <= arr[2]) {
            ans = "none"; // Not a valid triangle
        } else if (arr[0] == arr[1] && arr[1] == arr[2]) {
            ans = "equilateral";
        } else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) {
            ans = "isosceles";
        } else {
            ans = "scalene";
        }

        return ans;
    }
};
