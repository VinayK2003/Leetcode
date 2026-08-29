class MedianFinder {
public:

    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(maxi.empty()) {
            maxi.push(num);
        }
        else if(num>maxi.top()){
            mini.push(num);
        }else{
            maxi.push(num);
        }

        if(maxi.size()>mini.size()+1){
            mini.push(maxi.top());
            maxi.pop();
        }else if(mini.size()>maxi.size()) {
                maxi.push(mini.top());
                mini.pop();
        }

    }
    
    double findMedian() {
        double ans;
        if(maxi.size()>mini.size()){
            ans=maxi.top();
        }
        else{
            double x=maxi.top();
            double y=mini.top();
            // cout<<x<<" "<<y<<endl;
            ans=(x+y)/2.0;
        }
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */