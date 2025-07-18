class Solution {
public:
    int countBattleships(vector<vector<char>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        int cnt=0;
        for(int i=0; i< n; i++){
            for(int j=0; j< m ; j++){

                if(arr[i][j]=='X'){

                //up
                if(i>0 && arr[i-1][j]=='X' || (j>0 && arr[i][j-1]=='X')){
                    continue;
                }
                
                else{
                    cnt++;
                }

                }

            }
        }

        return cnt;
        
    }
};