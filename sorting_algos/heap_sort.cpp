#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums, int parent_idx, int end) {
	int max_ele_idx = parent_idx; // we assume this parent node at parent_idx to be the max ele
	int left_child_idx = 2 * parent_idx + 1;
	int right_child_idx = 2 * parent_idx + 2;
	// Now we try to find the max_ele out of these 3(parent, left child and right child)
	if (left_child_idx < end and nums[left_child_idx] > nums[max_ele_idx]) {
		max_ele_idx = left_child_idx; //  as we found the left child to be greater than the parent
	}
	if (right_child_idx < end and nums[right_child_idx] > nums[max_ele_idx]) {
		max_ele_idx = right_child_idx;
	}
	if (max_ele_idx != parent_idx) {
		// i.e. the parent is not the max ele so we need to swap it with max child
		swap(nums[parent_idx], nums[max_ele_idx]);
		heapify(nums, max_ele_idx, end);
	}
}

void heapsort(vector<int> &nums) {
	int size = nums.size();
	// step1: Create a max-heap, so that we can start the process of filling the max ele at the end of the nums one by one inplace
	for (int idx = size / 2 - 1; idx >= 0; idx--) {
		//  we start the idx from size/2 - 1 as this is the idx for the first non-leaf node and as we are performing a down-heapify algorithm
		// we donot require to consider the leaf nodes as they donot have a child, so downheapify is not applicable to them
		heapify(nums, idx, size);
	}
	// step2: As we have a max heap, we are now gonna one by one take the max-ele from the heap and place it at the last position
	// of the array to sort it
	for (int idx = size - 1; idx >= 0; idx--) {
		swap(nums[0], nums[idx]); //  as we know the max ele for the current subarray is placed at 0th index
		// step3: After this swap, our left out arr(from 0 to idx-1 place) is not a max-heap, so we again heapify the remaining part
		heapify(nums, 0, idx); // idx is non-inclusive as from (n-1 to idx position the array is already sorted)
	}
}

int main() {
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}
	heapsort(nums);
	for (int ele : nums) cout << ele << " ";
	return 0;
}
