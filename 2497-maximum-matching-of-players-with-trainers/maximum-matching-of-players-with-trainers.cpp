class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {

int n=p.size();
int m=t.size();
int cnt=0;
        sort(t.begin(), t.end());
        sort(p.begin(),p.end());
        int i=0; int j=0;
        while(i< n && j< m){
            if(p[i]>t[j]){
                j++;
            }
            else{
                i++;
                j++;
                cnt++;
            }
        }

        return cnt;
        
    }
};