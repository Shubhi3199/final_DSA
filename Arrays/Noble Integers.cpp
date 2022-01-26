// https://www.interviewbit.com/problems/noble-integer/
// Time - O(N) and space - O(N), asked @ Amazon interview
int Solution::solve(vector<int> &A) {
    vector<int> cnt_frequencies(A.size() + 1, 0);
    for (int ele: A) {
        if (ele < 0) continue; // As we can't have negative counts, so negative numbers can never be solution
        else if (ele >= A.size()) {
            cnt_frequencies[A.size()]++; // This will store the number of elements that are greater than any possible solution
            // As, any number greater than or equals to A.size() can never be the ans because it will require that many number of 
            // elemnts grater than it to be the ans which is not possible as the size of the complete array is lesser than it
        }
        else cnt_frequencies[ele]++; // stores the frequency of each element in the array, so that if 5 occurs 3 times then cnt_fre[5] = 3
        // so as to make sure for any number lesser than 5 3 is added to the cnt of numbers greater than it
    }
    int total_greater_till_now = cnt_frequencies[A.size()]; // stores the number of elements that are greater than the size of the array
    for (int ele = A.size()-1; ele >= 0; ele--) {
        // we start from A.size()-1 as all the numbers greater than this can never be the solution
        // Also, we go right to left to make sure that before checking an ele we add the frequencies of numbers to the right of it 
        // (greater numbers) to the total_greater_till_now variable
        if (ele == total_greater_till_now and cnt_frequencies[ele] > 0) {
            return 1; // found the ele
        }
        else if (ele < total_greater_till_now) {
            return -1; // as out total_greater is already greater than the ele, so it can never happen now when we move from right to left 
            // that we'll find an ele = total_greater as ele are gonna decrease in this direction
        }
        total_greater_till_now += cnt_frequencies[ele]; // As for the num = ele-1, ele is greater than it, so we'll add it's frequency to total_greater
    }
    return -1;
}
