class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) {

        int n=arr.size();
        int i=0;
        int j=0;
        map<int,int> mp;
        while( i< n){

            while(j<n){
                if(arr[i]==arr[j]){
                    j++;
                }
                else{
                    break;
                }
                cout<<j<<endl;
            }
            if(mp.find(arr[i])!=mp.end()){
                mp[arr[i]]+=(j-i);
            }
            else{
                mp[arr[i]]=(j-i);
            }
            i=j;
            cout<<i<<"i"<<endl;
        }
        priority_queue<pair<int,int>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        vector<int> ans;
        while(ans.size()<k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        
    }
};