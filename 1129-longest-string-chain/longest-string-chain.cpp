class Solution {
public:

vector<vector<int>>dp;

bool cmp(string a, string b){
   if(a.size()+1!=b.size())return false;
   int i=0;
   int j=0;
//    sort(a.begin(), a.end());
//    sort(b.begin(), b.end());
   bool done=false;
   while(i< a.size() && j<b.size()){
    if(a[i]==b[j]){
        i++;
        j++;
    }
    else if(!done){
        j++;
        done=true;
    }
    else return false;
   }
   if(i!=a.size() && j!=b.size())return false;

   return true;
}

static bool comp(string & a, string & b){
    return a.size()< b.size();
}

int recur(int ind, vector<string> & words, int n, int prev){
    if(ind==n)return 0;
    int take=0;
    if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];

    if(prev==-1 || cmp(words[prev], words[ind])){
        take= 1+ recur(ind+1, words, n, ind);
    }
    int notake= recur(ind+1, words, n , prev);

    return dp[ind][prev+1]= max(take, notake);
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(), comp);

        dp.assign(n, vector<int> (n+1, -1));

        vector<int> lis(n, 1);
        // vector<int> prev(n, -1);
        int maxi=0;

        for(int i=0; i< n ; i++){
            // prev[i]=i;
            for(int j=0; j< i; j++){
                if(cmp(words[j], words[i]) && lis[i]<lis[j]+1){
                    lis[i]=lis[j]+1;
                    // prev[i]=j
                }
            }

            if(lis[i]>maxi){
                maxi=lis[i];
            }

        }
        return maxi;


        // return recur(0, words, n, -1);
        
    }
};