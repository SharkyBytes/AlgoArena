class Solution {
public:

    int maxSum(vector<int>& arr) {

        int n=arr.size();int sum=0;
        int x=*max_element(arr.begin(), arr.end());
int cnt=0;
        map<int,int> mp;
        for(auto it : arr){
            if(it<0 || mp.find(it)!=mp.end()){
                continue;
            }
            else {
                mp[it]=1;
                sum+=it;
                cnt++;
            }
        }
        if(cnt==0){
            sum+=x;
        }



        return sum;
        
    }
};