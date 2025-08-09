class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n>0){
            if(n&1){
                int temp= n>>1;
                if(temp==0){
                    return true;
                }
                else{
                    break;
                }
            }
            n>>=1;
        }

        return false;
        
    }
};