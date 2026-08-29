class KthLargest {
public:
vector<int>nums;
priority_queue<int, vector<int>, greater<int>> heap;
int k;

    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int it:nums){
                add(it);
        }
    }
    
    int add(int val) {
        if(heap.size()<k || heap.top()<val){
            heap.push(val);
            if(heap.size()>k){
                heap.pop();
            }
        }
        
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */