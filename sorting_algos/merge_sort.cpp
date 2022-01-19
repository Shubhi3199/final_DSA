// https://www.programiz.com/dsa/merge-sort

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int start, int end, int mid) {
	// temp will be our final sorted array formed by merging 2 sorted arrays: nums[start..mid] and nums[mid+1...end]
	vector<int> temp(end - start + 1);
	int i = start, j = mid+1, k = 0;
	while (i <= mid or j <= end) {
		if (i <= mid and j <= end) {
			temp[k++] = (nums[i] <= nums[j] ? nums[i++] : nums[j++]);
		}
		else if (i <= mid) {
			temp[k++] = nums[i++];
		}
		else if (j <= end) {
			temp[k++] = nums[j++];
		}
	}
	for (int i = 0; i < end - start + 1; i++) {
		nums[start + i] = temp[i];
	}
}

void merge_sort(vector<int> &nums, int start, int end) {
	if (start < end) { // as a single ele is already sorted (so we don't go upto start <= end)
		int mid = start + (end - start) / 2;
		merge_sort(nums, start, mid);
		merge_sort(nums, mid+1, end);
		// Now, after these 2 recurssive calls, my left and right half are already sorted and now I just have to use 
		// 2 sorted arrays to merge and make a complete sorted array which can be done in O(n+m) time
		merge(nums, start, end, mid);
	}
}

int main() {
	int size;
	cin >> size;
	vector<int> nums(size);
	for (int i = 0; i < size; i++) {
		cin >> nums[i];
	}
	merge_sort(nums, 0, nums.size()-1);
	for (int ele : nums) cout << ele << " ";
	return 0;
}
