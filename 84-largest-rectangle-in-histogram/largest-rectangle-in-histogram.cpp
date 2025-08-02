class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n=heights.size();
        stack<int> s;
        vector<int> right(n, n);
        vector<int> left(n, -1);


        for(int i=0; i< n; i++){

            while(!s.empty() && heights[s.top()]>heights[i]){
                right[s.top()]=i;
                s.pop();
            }   

            s.push(i);
            
        }
        s=stack<int> ();
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                left[s.top()]=i;
                s.pop();
            }

            s.push(i);
        }
        int area=INT_MIN;
        for(int i=0; i< n ; i++){
            int x= right[i];
            int y= left[i];
            int curr_area= (x-y-1)* heights[i];
            // cout<<x<<" "<<y<<" "<<curr_area<<endl;
            area=max(area, curr_area);
        }
        return area;
    }
};