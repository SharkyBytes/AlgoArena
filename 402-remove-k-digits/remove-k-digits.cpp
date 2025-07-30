class Solution {
public:
    string removeKdigits(string s, int k) {
        int n=s.length();

        stack<char> st;
        for(int i=0; i< n ; i++){
        while(!st.empty() && k>0 && st.top()>s[i]){
            st.pop();
            k--;

        }
        st.push(s[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();

        }
        int ind=-1;

        reverse(ans.begin(), ans.end());
        for(int i=0; i< ans.size() ; i++){
            if(ans[i]=='0'){
                ind=i;
            }
            else{
                break;
            }
        }
        string f=ans.substr(ind+1);
        if(f.size()==0)return "0";
        return f ;

    }
};