class Solution {
public:
int maxi=INT_MIN;
int cnt=0;
void recur(int i, vector<int> & arr, int val){
    if(i==arr.size()){
        maxi=max(val, maxi);
        return ;
    }

    recur(i+1, arr, val | arr[i]);
    recur(i+1, arr, val);
}

int orrecur(int i, vector<int> & arr, int val, int maxi,unordered_map<int, unordered_map<int, int>> &dp){
    if(i==arr.size() ){
        if(val==maxi){
            return 1;
        }      
        return 0;
    }
   if (dp[i].count(val)) return dp[i][val];

   int x= orrecur(i+1, arr, val | arr[i], maxi, dp);
   int y= orrecur(i+1, arr, val, maxi, dp);

    return dp[i][val]=x+y;
}


int countMaxOrSubsets(vector<int>& arr) {

        int n=arr.size();
        recur(0, arr, 0);
        unordered_map<int, unordered_map<int, int>> dp;
        // orrecur(0, arr, 0, maxi);

        // cout<<maxi<<endl;
        return orrecur(0,arr,0 , maxi, dp);
        
    }
};