import java.util.*;

public class Solution {
    public class Pair {
        public TreeNode first, second;

        Pair(TreeNode a, TreeNode b) {
            first = a;
            second = b;
        }
    }

    public Pair flattenTree(TreeNode root) {

        Pair p = new Pair(null, null);
        if (root == null) {
            p.first = p.second = null;
            return p;
        }

        if (root.left == null && root.right == null) {
            p = new Pair(root, root);
            return p;
        } else if (root.left == null) {
            Pair rightPart = flattenTree(root.right);
            root.right = rightPart.first;
            p.first = root;
            p.second = rightPart.second;
        } else if (root.right == null) {
            Pair leftPart = flattenTree(root.left);
            // leftPart.second.right = root;
            root.right = leftPart.first;
            p.first = root;
            p.second = leftPart.second;
        } else {
            Pair leftPart = flattenTree(root.left);
            Pair rightPart = flattenTree(root.right);
            root.right = leftPart.first;
            leftPart.second.right = rightPart.first;
            p.first = root;
            p.second = rightPart.second;
        }

        return p;
    }

    void nullify(TreeNode root) {

        TreeNode temp = root;

        while (temp != null) {
            temp.left = null;
            temp = temp.right;
        }
    }

    public TreeNode flatten(TreeNode a) {
        Pair ans = flattenTree(a);
        nullify(a);
        return ans.first;
    }

    public static void main(String[] args) {

    }
}
