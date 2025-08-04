class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int n=pushed.size();
        int j=0;

        for(int i=0; i<n ; i++){
            while(j<popped.size() && !st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }
            st.push(pushed[i]);
        }
        while(j<popped.size() && !st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
        }

        if(st.empty()){
            return true;
        }
        return false;
    }
};