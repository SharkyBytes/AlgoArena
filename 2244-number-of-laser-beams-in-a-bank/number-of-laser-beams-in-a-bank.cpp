class Solution {
public:
    int numberOfBeams(vector<string>& arr) {

        int n=arr.size();
        vector<int> row;
        for(auto it: arr){
            int cnt=0;
            for(int i=0; i< it.length(); i++){
                if(it[i]=='1'){
                    cnt++;
                }
            }
            row.push_back(cnt);
        }
int ans=0;
int prev=1;
bool flag=false;
int sum=0;
        for(int i=0; i< n; i++){
            cout<< row[i]<<" "<<prev<<endl;
            int x= row[i]*prev;
            if(!flag && x!=0){
                sum=x;
                flag=true;
            }
            if(x!=0){
                prev=row[i];
            }
            ans+=x;
        }
return ans-sum;

        
    }
};