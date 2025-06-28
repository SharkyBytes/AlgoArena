class Solution {
public:

static bool cmp(pair<int,int> & a, pair<int,int> & b){
    return a.second<b.second;
}
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;
        int n=nums.size();
        for(int i=0;i< n; i++){
            pq.push({nums[i], i});

        }
        int cnt=0;vector<pair<int,int>> ans;

        while(cnt<k){
            cnt++;
            auto it =pq.top();
            ans.push_back(it);
            pq.pop();
            
        }

        sort(ans.begin(), ans.end(),  cmp);
        vector<int> final;
        for(auto it : ans){
            final.push_back(it.first);
        }
return final;


        
    }
};