class Solution {
public:
    bool parseBoolExpr(string s) {

       stack<char> op;
       stack<char>st;
       int n=s.size();
       for(int i=0; i< n ; i++){
        if(s[i]=='|' || s[i]=='&' || s[i]=='!'){
            op.push(s[i]);
        }
        if(s[i]==',')continue;

        if(s[i]=='f' || s[i]=='t' || s[i]=='(')st.push(s[i]);

        else if(s[i]==')'){
            char ch= op.top();
            op.pop();
            if(ch=='&'){
                int ans=1;
                while(st.top()!='('){
                    char tp=st.top();
                    st.pop();
                    if(tp=='f'){
                        ans&=0;
                    }
                }
                st.pop();
                if(ans)st.push('t');
                else st.push('f');
            }
            else if(ch=='|'){
                int ans=0;
                while(st.top()!='('){
                    char tp=st.top();
                    st.pop();
                    if(tp=='t'){
                        ans|=1;
                    }
                }
                st.pop();
                if(ans)st.push('t');
                else st.push('f');
            }
            else if(ch=='!'){
                char tp= st.top();
                st.pop();
                if(tp=='t'){
                    st.pop();
                    st.push('f');
                }
                else{
                    st.pop();
                    st.push('t');
                }

            }
        }

       }

       if(st.top()=='t')return true;
       return false;
        

        
    }
};