class Solution {
public:
    int longestSubarray(vector<int>& arr) {

        int n=arr.size();
        int ans=-1;
        for(auto it : arr){
            ans=max(it, ans);
    }
cout<<n<<endl;
    int i=0;
    int j=0;
    int cnt=INT_MIN;
   for(int i=0; i<n ;){
    int temp=0;
    
    int j;
    for(j=i; j<n ; j++){
        if(arr[i]==ans && arr[i]==arr[j]){
            temp++;
        }
        else{
            j++;
            break;
        }
    }
    cnt=max(temp,cnt);
    i=j;
   }

    return cnt;
        
    }
};