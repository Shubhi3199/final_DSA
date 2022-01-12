class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int, int> get_maxsum(Node* node) {
        if (node == NULL) return {0, 0}; // {inlucde_cur_node, exclude_cur_node}
        pair<int, int> left_sum = get_maxsum(node -> left);
        pair<int, int> right_sum = get_maxsum(node -> right);
        // when we taje the cur node, then we can ony take the values from left and right when we excude the
        // left and right child nodes
        int include_cur_node = left_sum.second + right_sum.second + node -> data;
        // when we exclude the cur node, we don't know if taking the child nodes is best option or leaving them
        // in the hope that their childs might be huge, so we take the max of left's include and exclude sum
        // and add it with max of right's include and exxclude sum
        int exclude_cur_node = max(left_sum.first, left_sum.second) + max(right_sum.first, right_sum.second);
        
        return {include_cur_node, exclude_cur_node};
    }
    int getMaxSum(Node *root) 
    {
        pair<int, int> max_sum = get_maxsum(root);
        return max(max_sum.first, max_sum.second);
    }
};
