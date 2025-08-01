class Solution {
public:
    vector<vector<int>> generate(int n) {

        vector<vector<int>> arr;
        for(int i=0; i< n ; i++){
            vector<int> temp;
            if(i==0){
                temp.push_back(1);
            }
            else{
                vector<int> last= arr.back();
                temp.push_back(1);
                for(int j=1; j<last.size(); j++){
                    int x=last[j];
                    int y=last[j-1];

                    temp.push_back(x+y);

                }
                temp.push_back(1);


            }
            arr.push_back(temp);
        }

        return arr;
        
    }
};