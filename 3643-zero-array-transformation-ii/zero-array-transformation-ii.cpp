class Solution {
public:
bool cnt(int n, vector<int> &  arr, vector<vector<int>> & q ){
    int x=arr.size();
    vector<int> pre(x+1, 0);
    int m=q.size();
    int p=min(n,m);

    for(int i=0;i<p; i++){
        pre[q[i][0]]+=q[i][2];
        pre[q[i][1]+1]-=q[i][2];
        
    }
int tot=0;

    for(int i=0; i<arr.size(); i++){
        tot+=pre[i];
        if(tot<arr[i]){
            return false;
        }
    }

    return true;


}
    int minZeroArray(vector<int>& arr, vector<vector<int>>& q) {
        int n=arr.size();
        int  m=q.size();
        int s=0;
        int e=m;
        while(s<=e){
            int mid =s+(e-s)/2;
            if(cnt(mid, arr,q)){
                e=mid-1; 
            }
            else{
                s=mid+1;
            }

        }

if(cnt(s,arr,q)==0){
    return -1;
}

        return s;
        
    }
};