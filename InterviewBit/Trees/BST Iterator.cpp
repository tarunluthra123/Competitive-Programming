//https://www.interviewbit.com/problems/bst-iterator/
/*
BST Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.
*/
class BSTIterator {
    public:
        stack<TreeNode *> myStack;

        BSTIterator(TreeNode *root) {
            pushAll(root);
        }

        /** @return whether we have a next smallest number */
        bool hasNext() {
            return !myStack.empty();
        }

        /** @return the next smallest number */
        int next() {
            TreeNode *tmpNode = myStack.top();
            myStack.pop();
            pushAll(tmpNode->right);
            return tmpNode->val;
        }

    private:
        void pushAll(TreeNode *node) {
            while (node != NULL) {
                myStack.push(node);
                node = node->left;
            }
        }
};
