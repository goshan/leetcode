public class Solution {

public TreeNode last;
public void flatten(TreeNode root) {
    // Start typing your Java solution below
    // DO NOT write int main() function
    
    if (root == null)
    {
        /* code */
        return;
    }
    TreeNode left = root.left;
    TreeNode right = root.right;
    root.left = null;
    root.right = null;
    if (last != null){
        last.right = root;
    }
    last = root;
    flatten(left);
    flatten(right);
}

public static void main(String[] args) {
    TreeNode root = new TreeNode(1);
    TreeNode child1 = new TreeNode(2);
    TreeNode child2 = new TreeNode(3);
    root.left = child1;
    child1.right = child2;
    Solution s = new Solution();
    s.flatten(root);
    TreeNode current = root;
    while (current != null){
        System.out.print(current.val+" ");
        current = current.right;
    }
    System.out.println();
}


};
