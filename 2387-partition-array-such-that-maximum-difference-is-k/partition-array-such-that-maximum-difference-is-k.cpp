class Solution {
public:
    int partitionArray(vector<int>& arr, int k) {

sort(arr.begin(),arr.end());
int i=0;
int n=arr.size();
 int j=0;
  int cnt=0;
  while(i< n && j<n){
    while(j< n && arr[j]-arr[i]<=k){
        j++;
        cout<<j<< " "<<i<<endl;
    }
    i=j;
    j++;
    cnt++;
  }

  if(i<n){cnt++;}

  return cnt;

        
    }
};