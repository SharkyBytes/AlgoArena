class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {

        int n=a.size();
        int m=b.size();
        vector<int> pref(m, -1);
        map<int,int> mp;
        for(int i=0; i<m ; i++){
            mp[b[i]]=i;
        }

        stack<int> st;
        for(int i=m-1; i>=0; i--){
            while(!st.empty()){
                if(st.top()<b[i]){
                    st.pop();
                }
                else{
                    break;
                }
            }
            if(st.empty()){
                pref[i]=-1;
            }
            else{
                pref[i]=st.top();
            }

            st.push(b[i]);
        }

        vector<int> ans;
        for(int i=0; i< n ; i++){
            int ind=mp[a[i]];
            ans.push_back(pref[ind]);
        }

        return ans;
        
    }
};