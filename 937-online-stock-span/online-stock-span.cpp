class StockSpanner {
public:
stack<int>st;
int lev=1;
vector<int> arr;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && arr[st.top()-1]<=price){
            st.pop();            
        }
        int x=0;

        // int cnt=1;
        if(!st.empty()){
            x=st.top();
        }
        cout<<x<<" "<<lev<<endl;
        st.push(lev);
        int cnt= lev-x;
        lev++;
        arr.push_back(price);
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */