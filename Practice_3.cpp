#include<iostream>
using namespace std;

class TreeNode
{
public:
    TreeNode *right;
    TreeNode *left;
    int data;
    int height;

    TreeNode()
    {
        right = NULL;
        left = NULL;
        data = 0;
        height = 1;
    }
    TreeNode(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
        height = 1;
    }
    ~TreeNode(){}
};

class BST
{
public:
    TreeNode *root;

    BST(TreeNode * &obj)
    {
        root = obj;
    }
    TreeNode* insert(TreeNode *root, int data)
    {
        if(root == NULL)
        {
            root = new TreeNode(data);
            return root;
        }
        if(root->data > data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
    }
    void DeleteNode(TreeNode *root, int key)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->data < key)
        {
            DeleteNode(root->left, key);
        }
        else if(root->data > key)
        {
            DeleteNode(root->right, key);
        }
        else
        {
            TreeNode *temp = root;

            if(root->left == NULL)
            {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL)
            {
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                TreeNode *temp = root->right;

                while(temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;

                DeleteNode(root->right, temp->data);
            }
            delete temp;
        }
    }
    void DeleteAVLNode(TreeNode *root, int data)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->data < data)
        {
            DeleteAVLNode(root->left, data);
        }
        else if(root->data > data)
        {
            DeleteAVLNode(root->right, data);
        }
        else
        {
            TreeNode *temp = root;

            if(root->left == NULL)
            {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL)
            {
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            }
            else
            {
                TreeNode *temp = root->right;

                while(temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;

                DeleteAVLNode(root->right, temp->data);
            }
            delete temp;
        }

        root->height = max(height(root->left), height(root->right)) + 1;

        int balanceFactor = height(root->left) - height(root->right);

        if(balanceFactor > 1 && root->left->data > data)
        {
            root = rightRotate(root);
        }
        if(balanceFactor < -1 && root->right->data < data)
        {
            root = leftRotate(root);
        }
        if(balanceFactor > 1 && root->left->data < data)
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        if(balanceFactor < -1 && root->right->data > data)
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }
    }

    TreeNode* rightRotate(TreeNode *root)
    {
        TreeNode *rotate = root->left;
        TreeNode *temp = rotate->right;

        rotate->right = root;
        root->left = temp;

        root->height = 1 + max(height(root->left), height(root->right));
        rotate->height = 1 + max(height(rotate->left), height(rotate->right));

        return rotate;
    }
    TreeNode* leftRotate(TreeNode *root)
    {
        TreeNode *rotate = root->right;
        TreeNode *temp = rotate->left;

        rotate->left = root;
        root->right = temp;

        root->height = 1 + max(height(root->left), height(root->right));
        rotate->height = 1 + max(height(rotate->left), height(rotate->right));

        return rotate;
    }
    int max(int a, int b)
    {
        if(a > b)
        {
            return a;
        }
        return b;
    }
    int height(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return root->height;
    }
    int SecondLargest(TreeNode *root)
    {
        if(root == NULL || root->right == NULL)
        {
            return root->data;
        }
        for(; root->right->right != NULL; root = root->right);
        
        return root->data;
    }
    TreeNode* InsertAVLTree(TreeNode *root, int data)
    {
        if(root == NULL)
        {
            root = new TreeNode(data);
            return root;
        }
        if(root->data > data)
        {
            root->left = InsertAVLTree(root->left, data);
        }
        else
        {
            root->right = InsertAVLTree(root->right, data);
        }

        root->height = max(height(root->left), height(root->right)) + 1;

        int balanceFactor = height(root->left) - height(root->right);

        if(balanceFactor > 1 && root->left->data > data)
        {
            root = rightRotate(root);
        }
        if(balanceFactor < -1 && root->right->data < data)
        {
            root = leftRotate(root);
        }
        if(balanceFactor > 1 && root->left->data < data)
        {
            root->left = leftRotate(root->left);
            root = rightRotate(root);
        }
        if(balanceFactor < -1 && root->right->data > data)
        {
            root->right = rightRotate(root->right);
            root = leftRotate(root);
        }

        return root;
    }
    void Inorder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
    void Preorder(TreeNode *root)
    {
        if(root == NULL)
        {
            return;
        }
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
    ~BST(){}
};  

bool MirrorImaged(TreeNode *root1, TreeNode *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    return MirrorImaged(root1->left, root2->right) && MirrorImaged(root1->right, root2->left);
}

int main()
{
    TreeNode *root = NULL;

    BST B(root);

    root = B.insert(root, 10);
    root = B.insert(root, 20);
    root = B.insert(root, 5);
    root = B.insert(root, 15);
    root = B.insert(root, 30);

    cout << "Second Largest = " << B.SecondLargest(root) << endl;

    B.DeleteNode(root, 20);

    B.Inorder(root);

    cout << endl;

    TreeNode *_root = NULL;

    BST B1(root);

    _root = B1.insert(_root, 10);
    _root = B1.insert(_root, 20);
    _root = B1.insert(_root, 30);

    B1.Inorder(_root);

    cout << endl;

    if(MirrorImaged(root, _root))
    {
        cout << "Mirror Imgaes" << endl;
    }
    else
    {
        cout << "Not mirror images" << endl;
    }

    TreeNode *AVL_root = NULL;

    BST B2(AVL_root);

    AVL_root = B2.InsertAVLTree(AVL_root, 10);
    AVL_root = B2.InsertAVLTree(AVL_root, 20);
    AVL_root = B2.InsertAVLTree(AVL_root, 30);

    //B2.DeleteAVLNode(AVL_root, 20);

    cout << endl;

    B2.Preorder(AVL_root);

    cout << endl;
}
//20 10 30 expected