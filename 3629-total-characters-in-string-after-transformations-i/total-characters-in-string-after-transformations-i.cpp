#define ll long long
class Solution {
public:
int MOD=1e9+7;
int modadd(long a, long b){
    return ((a%MOD) +(b%MOD))%MOD;
}
    int lengthAfterTransformations(string s, int t) {

        int n=s.length();
        vector<long> arr(26,0);
        for(auto it:s){
            arr[it-'a']++;
        }

        for(int i=1; i<=t; i++){
            vector<long> temp(26,0);
            for(int i=0; i< 26; i++){
                if(i<25){
                    temp[i+1]=arr[i];
                }
                else{
                    temp[0]=arr[i];
                    temp[1]=modadd(temp[1],arr[i]);

                }

            }
        arr=temp;

        }


        long cnt=0;
        for(auto it: arr){
            cnt=modadd(cnt, it);
        }

        return cnt;
        
    }
};