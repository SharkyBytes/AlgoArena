class Solution {
public:

int matrixcnt(vector<int> & nums){
    int n=nums.size();
    int sum=0;
    int cnt=0;
    for(int i=0; i< n ; i++){
        if(nums[i]==1){
            cnt++;
            sum+=cnt;
        }
        else{
            cnt=0;
        }

    }

    return sum;
}
    int numSubmat(vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();

        int cnt=0;

        for(int s=0; s<n ; s++){
            vector<int> process(m, INT_MAX);

            for(int e=s; e<n ; e++){

                for(int i=0; i< m ; i++){
                    process[i]= process[i]& mat[e][i];
                }

                cnt+= matrixcnt(process);
            }
        }
        return cnt;
    }
};