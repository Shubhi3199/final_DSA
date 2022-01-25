class MedianFinder {
    priority_queue<int> smaller_half; // max heap to store the first half/ smaller elements, beecause all the elements left to the median are smaler than it, so if we wnt to construct the median from the left half, we'll require the largest ele from the left half & thus max heap 
    priority_queue<int, vector<int>, greater<int>> greater_half; // min heap to store the larger eleemnts, as all the eles to the right of median are greater than it, so we'll require the min elements from the right half to form the median
public:
    /** initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (smaller_half.size() == 0 or num < smaller_half.top()){
            // so for a new incoming number, if the number is lesser than the top of the max_heap(smaller_half) then it belongs to the left half, as the number at top of the max heap is assumed to be as a potential median 
            smaller_half.push(num);
        }
        else greater_half.push(num); // else if the number is greater than the top of left half then it will be part of the right half
        if (smaller_half.size() > 1 + greater_half.size()){
            // rebalancing the 2 heaps,  as we don't want the difference in sizes of the 2 heaps to be greater than 1, as the median is present in the middle of a sorted array, so either the median will be the top of any one of the 2 heaps or it will be the mean of the top of both the heaps
            int top = smaller_half.top();
            smaller_half.pop();
            greater_half.push(top);
        }
        else if (greater_half.size() > 1 + smaller_half.size()){
            int top = greater_half.top();
            greater_half.pop();
            smaller_half.push(top);
        }
    }
    
    double findMedian() {
        if (smaller_half.size() == greater_half.size()){
            // we have even numebr of elements in total 
            return ((double) smaller_half.top() + greater_half.top()) / 2;
        }
        else {
            // we have odd number of elements in our cuurrent data stream
            if (smaller_half.size() > greater_half.size()) return (double) smaller_half.top();
            return (double) greater_half.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
