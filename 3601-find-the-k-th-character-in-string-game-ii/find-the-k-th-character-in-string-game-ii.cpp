class Solution {
public:
    char kthCharacter(long long k, vector<int>& arr) {
int count=0;
long long val=k;
        while(val>1){
            int x= ceil(log2(val));
            val-= pow(2,x-1);
            count +=arr[x-1];

        }
        return  'a' +(count%26);
        
    }
};