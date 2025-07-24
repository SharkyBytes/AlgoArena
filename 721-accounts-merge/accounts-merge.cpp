class DisjointSet{

    vector<int> rank, parent;
public:
DisjointSet(int n){
    rank.resize(n,0);
    parent.resize(n, 0);
    for(int i=0; i< n ; i++){
        parent[i]=i;
    }
}

int findp(int node){
    if(node==parent[node]){return node;}
    return parent[node]=findp(parent[node]);
}

void uni(int u, int v){
    int pu=findp(u);
    int pv=findp(v);
    if(pu==pv){
        return;
    }
    if(rank[pu]< rank[pv]){
        parent[pu]=pv;
        
    }
    else if(rank[pv]<rank[pu]){
        parent[pv]=pu;
    }
    else{
        rank[pu]++;
        parent[pv]=pu;
    }
}



};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        int n=arr.size();

        DisjointSet ds(n);
        vector<set<string>> ans(n);

        map<string,int> mp;
        for(int i=0; i<arr.size() ; i++){
            for(int j=1; j<arr[i].size() ;j++){
                string p=arr[i][j];
                if(mp.find(p)!=mp.end()){
                    int x=ds.findp(mp[p]);
                    ds.uni(x, i);
                }
                else{
                    mp[p]=i;
                }
            }
            
        }
        for(int i=0; i<n ; i++){
            int p=ds.findp(i);
            for(int j=1; j<arr[i].size(); j++){
                ans[p].insert(arr[i][j]);
            }
        }
        vector<vector<string>> finall;
        for(int i=0; i< n ; i++){
            if(ans[i].size()==0){
                continue;
            }
            else{
                vector<string> temp;
                temp.push_back(arr[i][0]);
                 for (auto it : ans[i]) {
                temp.push_back(it);
            }
                finall.push_back(temp);
            }
        }

        return finall;
        
    }
};