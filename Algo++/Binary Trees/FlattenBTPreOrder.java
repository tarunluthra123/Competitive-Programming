import java.util.*;

public class FlattenBTPreOrder {
    public static class Node {
        Node left;
        Node right;
        int data;

        Node() {
            data = 0;
            left = right = null;
        }

        Node(int d) {
            data = d;
            left = right = null;
        }
    }

    public static class Pair {
        public Node first, second;

        Pair(Node a, Node b) {
            first = a;
            second = b;
        }
    }

    public static Pair flattenTree(Node root) {

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
            leftPart.second.right = root;
            p.first = leftPart.first;
            p.second = root;
        } else {
            Pair leftPart = flattenTree(root.left);
            Pair rightPart = flattenTree(root.right);
            root.right = rightPart.first;
            leftPart.second.right = root;
            p.first = leftPart.first;
            p.second = rightPart.second;
        }

        return p;
    }

    public static void nullify(Node root) {

        Node temp = root;

        while (temp != null) {
            temp.left = null;
            temp = temp.right;
        }
    }

    public static Node flatten(Node root) {
        Pair ans = flattenTree(root);
        nullify(ans.first);
        return ans.first;
    }

    static int i = 0;

    public static Node createTreeFromTrav(int[] inOrder, int[] preOrder, int s, int e) {
        // Base Case
        if (s > e) {
            return null;
        }
        // Rec Case
        Node root = new Node(preOrder[i]);
        // System.out.println("node created with data = " + preOrder[i]);

        int index = -1;
        for (int j = s; j <= e; j++) {
            if (inOrder[j] == preOrder[i]) {
                index = j;
                break;
            }
        }

        i++;
        // System.out.println("i = " + i);
        root.left = createTreeFromTrav(inOrder, preOrder, s, index - 1);
        root.right = createTreeFromTrav(inOrder, preOrder, index + 1, e);
        return root;
    }

    public static void printLinkedList(Node head) {
        Node temp = head;
        while (temp != null) {
            if (temp.left != null) {
                System.out.println(-1);
            }
            System.out.print(temp.data + " ");
            temp = temp.right;
        }
    }

    public static void printPostOrder(Node root) {
        if (root == null) {
            return;
        }

        printPostOrder(root.left);
        printPostOrder(root.right);
        System.out.println(root.data + " ");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] preOrder = new int[n];
        int[] inOrder = new int[n];

        for (int i = 0; i < n; i++) {
            preOrder[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            inOrder[i] = sc.nextInt();
        }

        Node root = createTreeFromTrav(inOrder, preOrder, 0, n - 1);

        System.out.println("Tree built");

        // printPostOrder(root);

        // print(root);

        Node head = flatten(root);

        printLinkedList(head);
    }
}
