class Solution {
public:
        int maxi=INT_MIN;
        int cnt=0;
void recur(int i, vector<int> & arr, int val){
    if(i==arr.size()){
        maxi=max(val, maxi);
        return ;
    }

    recur(i+1, arr, val | arr[i]);
    recur(i+1, arr, val);
}

void orrecur(int i, vector<int> & arr, int val, int maxi){
    if(i==arr.size() ){
        if(val==maxi){
            cnt++;
        }      
        return ;
    }


    orrecur(i+1, arr, val | arr[i], maxi);
    orrecur(i+1, arr, val, maxi);

}


    int countMaxOrSubsets(vector<int>& arr) {

        int n=arr.size();
        recur(0, arr, 0);
        orrecur(0, arr, 0, maxi);

        cout<<maxi<<endl;
        return cnt;
        
    }
};