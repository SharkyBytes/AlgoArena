class MedianFinder {
public:
        priority_queue<int> maxi;
        priority_queue<int, vector<int>, greater<int>> mini;
    MedianFinder() {

       
        
    }
    
    void addNum(int num) {
        
        if(mini.size()==0 || mini.top()<=num){
            mini.push(num);
        }
        else {
            maxi.push(num);
        }
        if(mini.size()>maxi.size()+1){
            maxi.push(mini.top());
            mini.pop();
        }
        else if(maxi.size()> mini.size()){
            mini.push(maxi.top());
            maxi.pop();
        }
              
    }
    
    double findMedian() {

        if(maxi.size()==mini.size()){
            return (maxi.top()+ mini.top())/2.0;
        }
        else{
            return mini.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */