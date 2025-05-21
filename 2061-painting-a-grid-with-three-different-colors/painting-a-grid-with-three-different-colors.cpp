class Solution {
public:
int mod=1e9+7;

int cnt(int m , int n, int r, int c, int curr_state, int prev_state){
    if(c==n){
        return 1;
    }

    if(r==m){
        return cnt(m, n, 0, c+1, 0, curr_state);
    }
    if(r==0 && dp[c][prev_state]!=-1){
        return dp[c][prev_state];
    }

    int up_row=0;
    if(r>0){
        up_row= curr_state&3;
    }
    int left=0;
    if(c>0){
        int mask= (m-r-1)*2;
        left= (prev_state>>mask)&3;
    }

    int ways=0;

    for(int i=1; i<=3;  i++){
        if(i!=up_row && i!= left){
         ways= (ways+ cnt(m, n, r+1, c, (curr_state<<2) + i , prev_state) )%mod;
            
        }
    }
   
   if(r==0){
    dp[c][prev_state]=ways;

   }

return ways;

}

    int dp[1000+2][1023];
    int colorTheGrid(int m, int n) {
        memset(dp,-1, sizeof(dp));

        return cnt(m,n,0,0,0,0);
        
        
    }
};