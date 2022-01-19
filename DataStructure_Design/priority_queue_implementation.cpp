#include<bits/stdc++.h>
using namespace std;

class _priority_queue {
	vector<int> data; // min heap
public:
	_priority_queue() {
		data = vector<int> ();
	}
	int peek() {
		if (data.size() == 0) return -1; // underflow condition
		return data[0]; // root of the CBT, complete binary tree (hence the smallest ele)
	}
	void upheapify(int child_idx) {
		// To re-establish the min heap condition
		if (child_idx == 0) return;
		int parent_idx = (child_idx - 1) / 2;
		if (data[parent_idx] > data[child_idx]) {
			swap(data[parent_idx], data[child_idx]);
			upheapify(parent_idx);
		}
	}
	void downheapify(int parent_idx) {
		int left_child_idx = 2 * parent_idx + 1;
		int right_child_idx = 2 * parent_idx + 2;

		int min_ele_idx = parent_idx; // idx at which we have minimum value;  we have assumed it to be parent_idx
		if (left_child_idx < data.size() and data[left_child_idx] < data[min_ele_idx]) {
			// that means the left_child is smaller than the parent, so we update the min_ele_idx
			min_ele_idx = left_child_idx;
		}
		if (right_child_idx < data.size() and data[right_child_idx] < data[min_ele_idx]) {
			min_ele_idx = right_child_idx;
		}
		// after the above 2 if conditions, we now know which idx out of parent, left_child or the right_child has the minimum value
		if (parent_idx != min_ele_idx) {
			// that means parent is not at its correct position and should be swapped with the min_ele_idx
			swap(data[parent_idx], data[min_ele_idx]);
			downheapify(min_ele_idx); // recursively calling on min_ele_idx as now after swap, min_ele_idx might not be the minimum in its subtree
		}
	}
	void insert(int item) {
		// 1. insert the new ele at the last of the CBT as push_back in an array is O(1) operation
		data.push_back(item);
		// 2. Up-heapify so that the min-heap condition is not violated
		upheapify(data.size() - 1); // as the newly inserted ele is at the last idx
	}
	int pop() {
		if (data.size() == 0) return -1; // underflow condition
		// 1. swap the root with the last ele, as removal from the end of the vector is O(1) operation
		int val = data[0];
		swap(data[0], data[data.size() - 1]);
		// 2. remove that from the array
		data.pop_back();
		// 3. down-heapify the entire CBT as due to the swap in step1. the array is not yet following min heap condition
		downheapify(0); // as this is the place which is violating the heap property
		return val;
	}
	bool empty() {
	    return data.size() == 0;
	}
};

int main() {
	_priority_queue pq = _priority_queue();
    pq.insert(10);
    pq.insert(20);
    cout<<pq.peek()<<endl;
    pq.insert(1);
    cout<<pq.peek()<<endl;
    pq.insert(30);
    pq.insert(25);
    cout<<pq.peek()<<endl;
    pq.insert(15);
    cout<<pq.peek()<<endl;
    cout<<"========================"<<endl;
    while (!pq.empty()) {
        cout<<pq.pop()<<" "<<pq.peek()<<endl;
    }
	return 0;
}
