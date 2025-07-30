class Solution {
public:

int area(vector<int> & temp){
    int n=temp.size();
    vector<int> left(n, -1);
    vector<int> right(n, n);

    stack<int> st;
    for(int i=0; i< n ; i++){
        while(!st.empty() &&  temp[st.top()]>=temp[i]){
            st.pop();
        }

        if(st.empty()){
            left[i]=-1;
        }
        else {
            left[i]=st.top();
        }
        st.push(i);
    }
    st=stack<int> ();

      for(int i=n-1; i>=0 ; i--){
        while(!st.empty() &&  temp[st.top()]>=temp[i]){
            st.pop();
        }

        if(st.empty()){
            right[i]=n;
        }
        else {
            right[i]=st.top();
        }
        st.push(i);
    }
    int ans=0;

    for(int i=0; i< n ; i++){
        int x= i-left[i];
        int y= right[i]-i;

        ans= max(ans,(x+y-1)*temp[i]);
    }
    return ans;
}
    int maximalRectangle(vector<vector<char>>& arr) {
int m=arr[0].size();
        int n=arr.size();
        vector<int> temp(m , 0);
        int maxi=INT_MIN;

        for(int i=0; i<  n ; i++){

            for(int j=0; j< m ; j++){
                if(arr[i][j]=='1'){
                    temp[j]++;
                }
                else if(arr[i][j]=='0'){
                    temp[j]=0;
                }
            }
            int ar=area(temp);
            maxi=max(maxi, ar);

        }
        return maxi;

        
    }
};