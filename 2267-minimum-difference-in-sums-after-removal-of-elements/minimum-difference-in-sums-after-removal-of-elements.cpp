
class Solution {
public:
    long long minimumDifference(vector<int>& arr) {

        int m= arr.size();
        int n= m/3;
        priority_queue<long long > pq;
        long long  left=0;

        for(int i=0; i< n; i++){
            left+=arr[i];
            pq.push(arr[i]);
        }
        vector<long long > pre(n+1, 0);
        pre[0]=left;
        for(int i=n; i< 2*n; i++){
            left+=arr[i];
            pq.push(arr[i]);
            int x=pq.top();
            pq.pop();
            left-=x;
            pre[i-(n-1)]=left;
        }

        priority_queue<long long , vector<long long >, greater<long long >> mpq;
        long long  right=0;
        for(int i=3*n-1; i>=2*n ; i--){
            right+=arr[i];
            mpq.push(arr[i]);
        }
long  long ans= pre[n]-right;
for(int i=2*n-1; i>=n ; i--){
    right+=arr[i];
    mpq.push(arr[i]);
    int x=mpq.top();
    mpq.pop();
    right-=x;
    ans=min(ans, pre[i-(n)]-right );
    
}

return ans;


        

    }
};