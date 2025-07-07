class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap; // stores end days
        int i = 0, res = 0, n = events.size();
        
        // Find the last day among all events
        int lastDay = 0;
        for (auto &e : events) {
            lastDay = max(lastDay, e[1]);
        }

        // Iterate from day 1 to last possible event end day
        for (int day = 1; day <= lastDay; day++) {
            // Add all events starting today
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]); // push end day
                i++;
            }

            // Remove all events that already expired
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Attend one event that ends the earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
            }
        }

        return res;
    }
};