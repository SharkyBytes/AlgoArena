class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        stack<int> st;
        for(auto it :arr){
            if(it<0){
                bool chota=false;
                while(!st.empty()){
                    if(st.top()>0 && st.top()<abs(it)){
                        st.pop();
                    }
                    else if(st.top()>0 && st.top()==abs(it)){
                        st.pop();
                        chota=true;
                        break;
                    }
                    else if(st.top()>0){
                        chota=true;
                        break;
                    }
                    else{
                        break;
                    }
                }
                if(!chota){
                    st.push(it);
                }

            }
            else{
                st.push(it);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();

        }
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};