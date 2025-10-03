#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;
struct Node 
{
    string value;
    Node* left;
    Node* right;
};
class Expression 
{
public:
    Node* constructTree(const string& prefix) 
    {
        stack<Node*> st;
        int i = prefix.length() - 1;
        while (i >= 0) 
        {
            if (isalnum(prefix[i])) 
            {
                string operand;
                while (i >= 0 && isalnum(prefix[i])) 
                {
                    operand = prefix[i] + operand;
                    i--;
                }
                Node* newNode = new Node;
                newNode->value = operand;
                newNode->left = nullptr;
                newNode->right = nullptr;
                st.push(newNode);
            } else if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') 
            {
                Node* node = new Node;
                node->value = string(1, prefix[i]);
                if (!st.empty()) 
                {
                    node->left = st.top();
                    st.pop();
                } else 
                {
                    node->left = nullptr;
                }
                if (!st.empty()) 
                {
                    node->right = st.top();
                    st.pop();
                } else 
                {
                    node->right = nullptr;
                }
                st.push(node);
                i--;
            } else 
            {
                i--; 
            }
        }
        return st.empty() ? nullptr : st.top();
    }
    void postOrderTraversal(Node* root) 
    {
        if (!root) return;
        stack<Node*> st1, st2;
        st1.push(root);
        while (!st1.empty()) 
        {
            Node* current = st1.top();
            st1.pop();
            st2.push(current);
            if (current->left) st1.push(current->left);
            if (current->right) st1.push(current->right);
        }
        while (!st2.empty()) 
        {
            cout << st2.top()->value << " ";
            st2.pop();
        }
    }
    void display(Node* root) 
    {
        if (!root) return;
        if (root->left) cout << "(";
        display(root->left);
        cout << root->value;
        display(root->right);
        if (root->right) cout << ")";
    }
    void deleteTree(Node* root) 
    {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};
int main() 
{
    Expression obj;
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;
    Node* root = obj.constructTree(prefix);
    if (!root) 
    {
        cout << "Invalid expression!" << endl;
        return 1;
    }
    cout << "Post-order traversal of the expression tree: ";
    obj.postOrderTraversal(root);
    cout << endl;
    cout << "In-order display of the expression tree: ";
    obj.display(root);
    cout << endl;
    obj.deleteTree(root);
    cout << "Tree Deleted Successfully" << endl;
    return 0;
}

Output :
PS G:\4th Sem\DSA\Pratical\output> & .\'dsa5.exe'
Enter the prefix expression: /+ab-*cde
Post-order traversal of the expression tree: ab cde * - + / 
In-order display of the expression tree: ((ab+((cde*-)/
Tree Deleted Successfully
