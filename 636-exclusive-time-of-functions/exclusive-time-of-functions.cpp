class Solution {
public:

struct Stack{
    int id,  start,  ch;
};

vector<int>  process(string & s){
    int x=0;
    int i=0;
    int num=0;
    bool st=0;
    while(i< s.length()){
        if(s[i]==':'){
            i++;
            x=num;     
            break;       
        }
        num*=10;
        num+=s[i]-'0';
        i++;
    }

    if(s[i]=='s'){
        st=true;
    }   
    num=0;
     while(i< s.length()){
        if(s[i]==':' || (s[i]<'0' || s[i]>'9')){
           i++;      
           continue;
        }
        num*=10;
        num+=s[i]-'0';
        i++;
    }

    int interval=num;
cout<<x<<" "<<st<<" "<<interval<<endl;

    return {x, st, interval };

}
    vector<int> exclusiveTime(int n, vector<string>& logs) {

        stack<Stack> st;

        int m= logs.size();
        map<int,int> mp;
        int ch=0;
        for(int i=0; i< m ; i++){

            string p=logs[i];
            vector<int> info=process(p);
            if(info[1]==1){
                st.push({info[0], info[2], 0});
            }  

            else{
                auto it = st.top();
                int num= info[2]-it.start+1;
                int x=num;
                x-=it.ch;
                cout<<x<<endl;
                mp[it.id]+=x;
                st.pop();
                if(!st.empty()){
                    st.top().ch+=num;
                }
            }          

        }

        vector<int> ans(n,0);

        for(auto it : mp){
            int idd=it.first;
            int time= it.second;
            ans[idd]=time;
        }

        return ans;

        
    }
};