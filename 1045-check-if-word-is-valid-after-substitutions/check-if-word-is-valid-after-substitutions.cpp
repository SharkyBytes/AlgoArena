class Solution {
public:
    bool isValid(string s) {

        int n=s.length();
        stack<string> st;
        for(int i=0; i< n ; i++){

            if(s[i]=='a'){
                st.push("(");
            }
            else if(s[i]=='b'){
                if(!st.empty() && st.top()=="("){
                    st.pop();
                    st.push("(*");
                }
                else{
                    return false;
                }
            }
            else{
                if(!st.empty() && st.top()=="(*"){
                    st.pop();
                }
                else return false;

            }


        }
        if(st.empty())
        return true;
        return false;
        
    }
};