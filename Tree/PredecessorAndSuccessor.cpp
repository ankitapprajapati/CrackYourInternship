class Solution
{
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        if (!root) return;

        if (root->key == key) {
            // Find the predecessor
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) temp = temp->right;
                pre = temp;
            }
            
            // Find the successor
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) temp = temp->left;
                suc = temp;
            }
            return; // Exit after finding both pre and suc
        }

        if (root->key > key) {
            suc = root;
            findPreSuc(root->left, pre, suc, key);
        } else {
            pre = root;
            findPreSuc(root->right, pre, suc, key);
        }
    }
};
