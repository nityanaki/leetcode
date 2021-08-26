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
    public TreeNode invertTree(TreeNode root) {
        //base case: when you reach a node with no children
        //a node with just one child should still be possible because you would just have a null treeNode
        //so if both left and right are null, then go ahead and return root? not entirely sure what to return at each level; in the end, it should be the very top node that's returned
        if (root == null) return root;
        if (root.left == null && root.right == null) return root;
        
        //swap left and right children node of root, using a temp
        //temp treenode = root.left, root.left = root.right, root.right = temp
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;
        
        //send a call to the next level
        //invertTree(root.left), and don't forget invertTree(root.left) (make sure that the call is only executed if the child is null)
        if (root.left!=null) invertTree(root.left);
        if (root.right!=null) invertTree(root.right);
        
        //return the root once done going through this code? think that makes sense here
        return root;
    }
}

// brute force solution:
// make a blank tree, and add all left nodes to the right and right nodes to the left
// will be a too high space complexity (2 bsts), but run time will be fine

//other possible solutions?
//go through the tree and use a temp treenode, then switch the nodes
//should have same time complexity as above solution (O(N) bc visiting each node once) but lower space complexity
//I believe O(N) is the lowest you can do since you have to reach every node
//going to use this second solution - traverse through tree recursively, level by level, if possible
