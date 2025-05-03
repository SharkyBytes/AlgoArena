class Solution {
public:
 int poss (int n, vector<int> & top, vector<int> & bottom){
     map<int,int> mp;
        // int n=top.size();
        int mini=INT_MAX;
        for(auto it: top){
            mp[it]++;
        }
        
        for(auto it: mp){
            int x= it.first;
            int cnt=0;
            bool notposs=0;
            for(int i=0; i< n; i++){
                if(top[i]!=x && bottom[i]!=x){
                    notposs=1;
                    break; 
                }
                else if( top[i]!=x && bottom[i]==x){
                    cnt++;
                }

            }
            if(!notposs){
                mini=min(cnt,mini);
            }
            
        }
        return mini==INT_MAX ? -1 : mini;
 }
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {

        int n=top.size();

        int x=poss(n, top, bottom);
        int y= poss(n, bottom, top);

        if(x==-1){
            return y;
        }
        else if ( y==-1){
            return x;
        }
        else{
            return min(x,y);
        }
    }
};