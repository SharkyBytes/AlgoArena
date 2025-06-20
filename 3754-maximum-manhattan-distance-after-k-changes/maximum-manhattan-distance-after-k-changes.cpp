class Solution {
public:
    int maxDistance(string st, int k) {

        int n=0;
        int w=0;
        int e=0, s=0;

    int ans=0;

        for(auto it : st){
            if(it=='N'){
                n++;
            }
            else if (it=='S'){
                s--;
            }
            else if(it=='W'){
                w++;
            }
            else{
                e--;
            }


          int   maxi=max(abs(n), abs(s))+max(abs(e), abs(w));
           int  mini=min(abs(n), abs(s))+min(abs(e), abs(w));
           ans=max(ans, (maxi+min(k,mini) - (mini-min(k,mini))));


        }

        return ans;
        
    }
};