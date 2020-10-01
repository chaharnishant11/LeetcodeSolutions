class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    double ans;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int l= left.size(), r=right.size();
        if(l==0 && r==0) {
            left.push(num);
            ans= num;
        } else if(l==r) {
            if(num<ans) {
                left.push(num);
                ans= left.top();
            } else {
                right.push(num);
                ans= right.top();
            }
        } else if(l>r) {
            if(ans<=num) right.push(num);
            else {
                int temp= left.top();
                left.pop();
                right.push(temp);
                left.push(num);
            }
            ans= (left.top()+right.top())/2.0;
        } else {
            if(ans<=num) {
                int temp= right.top();
                right.pop();
                left.push(temp);
                right.push(num);
            } else left.push(num);
            ans= (left.top()+right.top())/2.0;
        }
    }
    
    double findMedian() {
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
