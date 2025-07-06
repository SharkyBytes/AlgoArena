class FindSumPairs {
public:

vector<int> a, b;
unordered_map<int,int> mp;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a=nums1;
        b=nums2;
        for(auto it : b){
            mp[it]++;
        }
        
    }
    
    void add(int index, int val) {
        mp[b[index]]--;
b[index]+=val;
        mp[b[index]]++;
        
    }
    
    int count(int tot) {
int cnt=0;
        for(auto it: a){
            int x= tot-it;
            if(mp.find(x)!=mp.end()){
                cnt+=mp[x];
            }
        }

        return cnt;
        
    }

};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */