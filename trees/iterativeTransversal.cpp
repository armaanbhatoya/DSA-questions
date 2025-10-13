#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int v)
    {
        data = v;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> Preorder_iterative(Node *root)
{
    vector<int> preorder;
    if (root == nullptr)
        return preorder;
    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preorder.push_back(root->data);

        if (root->right != nullptr)
            st.push(root->right);
        if (root->left != nullptr)
            st.push(root->left);
    }
    return preorder;
}
void printPreoderIterative(Node *root)
{
    vector<int> arr = Preorder_iterative(root);
    cout << "Level Order Transversal: " << endl;
    for (auto it : arr)
    {
        cout << it << " ";
        cout << endl;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    printPreoderIterative(root);

    return 0;
}