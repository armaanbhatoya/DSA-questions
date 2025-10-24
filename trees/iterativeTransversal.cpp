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
    cout << "InOrder Transversal: " << endl;
    for (auto it : arr)
    {
        cout << it << " ";
        cout << endl;
    }
}

vector<int> Inorder_iterative(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    vector<int> inorder;
    while (true)
    {
        if (node != nullptr)
        {
            st.push(node);
            node = node->left;
        }
        else
        {
            if (st.empty() == true)
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    return inorder;
}
void printInoderIterative(Node *root)
{
    vector<int> arr = Inorder_iterative(root);
    cout << "Inorder Transversal: " << endl;
    for (auto it : arr)
    {
        cout << it << " ";
        cout << endl;
    }
}
vector<int> Postorder_iterative(Node *root)
{
    vector<int> postorder;
    if (root == nullptr)
        return postorder;
    Node *curr = root;
    Node *temp;
    stack<Node *> st;

    while (curr != nullptr || !st.empty())
    {
        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
}
void printPostoderIterative(Node *root)
{
    vector<int> arr = Postorder_iterative(root);
    cout << "Postorder Transversal: " << endl;
    for (auto it : arr)
    {
        cout << it << " ";
        // cout << endl;
    }
}

// ----------------------------------------------------------
vector<vector<int>> All_treeTraversal(Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != nullptr)
            {
                st.push({it.first->left, 1});
            }
        }

        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != nullptr)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
}

void print_All_treeTransversal(Node *root)
{
    vector<vector<int>> ans = All_treeTraversal(root);
    cout << "Preorder Transversal: " << endl;
    for (auto it : ans[0])
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Inorder Transversal: " << endl;
    for (auto it : ans[1])
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "Postorder Transversal: " << endl;
    for (auto it : ans[2])
    {
        cout << it << " ";
    }
    cout << endl;
}
// ----------------------------------------------------------------------------
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    // printPreoderIterative(root);
    // printInoderIterative(root);
    // printPostoderIterative(root);
    print_All_treeTransversal(root);

    return 0;
}