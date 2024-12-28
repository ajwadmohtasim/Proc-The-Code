//Basic BST implementation
#include <iostream>
using namespace std;

class Tree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;
        };
        Node* root;
        Node* InsertNode(Node*& node, int val) {
            if (node == nullptr) {
                node = new Node;
                node->data = val;
                node->left = node->right = nullptr;
            } else if (val < node->data) {
                InsertNode(node->left, val);
            } else {
                InsertNode(node->right, val);
            }
            return node;
        }
        void Destroy(Node*& node) {
            if (node != nullptr) {
                Destroy(node->left);
                Destroy(node->right);
                delete node;
                node = nullptr;
            }
        }
        void DeleteNode(Node*& node, int key) {
            if (node == nullptr) {
                cout << "No such key found\n";
                return;
            }
            if (key < node->data) {
                DeleteNode(node->left, key);
            } else if (key > node->data) {
                DeleteNode(node->right, key);
            } else {
                int val;
                Node* temp = node;
                if (node->left == nullptr) {
                    node = node->right;
                    delete temp;
                } else if (node->right == nullptr) {
                    node = node->left;
                    delete temp;
                } else {
                    Node* cur = node->left;
                    while (cur->right != nullptr) {
                        cur = cur->right;
                    }
                    node->data = cur->data;
                    DeleteNode(node->left, cur->data);
                }
            }
        }
    public:
        Tree() : root(nullptr) {}
        ~Tree() {
            Destroy(root);
        }
        void ResetTree() {
            Destroy(root);
        }
        int CountNodes(Node* node) {
            if (node == nullptr)
                return 0;
            else 
                return CountNodes(node->left) + CountNodes(node->right) + 1;
        }
        bool Search(Node* node, int& key) {
            if (node == nullptr) {
                return false;
            }
            if (node->data == key) {
                return true;
            }
            if (node->data < key) {
                return Search(node->right, key);
            } else  {
                return Search(node->left, key);
            }
        }
        Tree& Insert(int val) {
            InsertNode(root, val);
            return *this;
        }
        void Delete(int key) {
            DeleteNode(root, key);
        }
        Node* GetRoot() {
            return root;
        }
        void PreOrder(Node* node, void (*process)(int)) {
            if (node != nullptr) {
                process(node->data);
                PreOrder(node->left, process);
                PreOrder(node->right, process);
            }
        }
        void InOrder(Node* node, void (*process)(int)) {
            if (node != nullptr) {
                InOrder(node->left, process);
                process(node->data);
                InOrder(node->right, process);
            }
        }
        void PostOrder(Node* node, void (*process)(int)) {
            if (node != nullptr) {
                PostOrder(node->left, process);
                PostOrder(node->right, process);
                process(node->data);
            }
        }
        
};

void PrintNode(int val) {
    cout << val << " ";
};

int main() {
    Tree t1;
    t1.Insert(50).Insert(30).Insert(70).Insert(20).Insert(40).Insert(60).Insert(80);
    cout << t1.CountNodes(t1.GetRoot()) << "\n";
    cout << "Inorder : ";
    t1.InOrder(t1.GetRoot(), PrintNode);
    cout << "\n";
    cout << "PreOrder : ";
    t1.PreOrder(t1.GetRoot(), PrintNode);
    cout << "\n";
    cout << "PostOrder : ";
    t1.PostOrder(t1.GetRoot(), PrintNode);
    cout << "\n";
    t1.Delete(50);
    cout << t1.CountNodes(t1.GetRoot()) << "\n";
    cout << "Inorder : ";
    t1.InOrder(t1.GetRoot(), PrintNode);
    cout << "\n";
    return 0;
}