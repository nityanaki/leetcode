/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        //iterate through the bst and go through every node
        //current node: where we're at
//         base case: when it reaches the end of the tree, or if it reaches a match
        if (root == null) {
            return false;
        }
        if (checkMatch(root, subRoot)) {
            return true;
        }
        //otherwise, continue
        return isSubtree(root.left, subRoot) || isSubtree(root.right, subRoot);
        
    }
    
    //check match method
    //recursive function; ret bool - > whether subtree
    //input values: (current node for the main tree; subTree)
    //base cases: reach a null node, or reach a point where the trees don't match, return false if they don't match, if one is null and the other is not, ret false; if both are null, return true (use &&)
    public boolean checkMatch(TreeNode curr, TreeNode subCurr) {
//         more efficient: return curr == null && subCurr == null
        if (curr == null && subCurr == null) {
            return true;
        } else if (curr != null && subCurr == null) {
            return false;
        } else if (curr == null && subCurr != null) {
            return false;
        } else if (curr.val != subCurr.val) {
            return false;
        }
        
        // recursive cases
        return checkMatch(curr.left, subCurr.left) && checkMatch(curr.right, subCurr.right);
    }
}

// looking for a matching value probably wouldn't work due to allowing duplicates, unless we check every instance of root val

// go according to first solution
// look through bst for every possible instance of the root value
// once i reach a match, then go through values of both the main tree and subtree and make sure all values match
// make sure to check all possible instances
