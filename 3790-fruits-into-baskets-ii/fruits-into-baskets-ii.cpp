class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int j=0;
        int cnt=0;
        for(int i=0; i< fruits.size(); i++){
            bool hua=false;
            
            for(int j=0; j< baskets.size(); j++){
                if(fruits[i]<=baskets[j]){

                    baskets[j]=0;
                    hua=true;
                    break;
                }
            }

            if(!hua)cnt++;

        }
        return cnt;


        
    }
};