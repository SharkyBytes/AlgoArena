class Solution {
public:
    int differenceOfSums(int n, int m) {
int sum1=0, sum2=0;
        for(int it=0; it<=n; it++){
            if(it%m!=0){
                sum1+=it;
            }
        }
           for(int it=0; it<=n ; it++){
            if(it%m==0){
                sum2+=it;
            }
        }

        return sum1-sum2;
        
    }
};