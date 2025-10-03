#include<iostream> 
#include<queue> 
using namespace std; 
struct Node  
{ 
    int data;     
Node* left; 
    Node* right; 
    Node(int value)  
    {         data = value;         
left = right = nullptr; 
    } 
}; 
class BinarySearchTree  
{ 
public:     
Node* root; 
    BinarySearchTree()  
    { 
        root = nullptr;     
} 
    Node* insert(Node* node, int val)  
    { 
        if (node == nullptr)             
return new Node(val);  
        if (val < node->data)  
        { 
            node->left = insert(node->left, val); 
        }  
        else { 
            node->right = insert(node->right, val); 
        }         return 
node; 
    } 
    int height(Node* node)  
    { 
        if (node == nullptr)  
        { 
            return 0; 
        } 
        int leftDepth = height(node->left);         
int rightDepth = height(node->right); 
        return max(leftDepth, rightDepth) + 1; 
    } 
    int small(Node* node)  
    { 
        if (node == nullptr)  
        {             
return -1; 
        } 
        while (node->left != nullptr)  
        { 
            node = node->left; 
        } 
        return node->data; 
    } 
    void swapChildren(Node* node)  
    { 
        if (node == nullptr)  
        {             
return; 
        } 
        swapChildren(node->left);         swapChildren(node
>right); 
        swap(node->left, node->right); 
    } 
    Node* search(Node* node, int value)  
    { 
        if (node == nullptr || node->data == value)  
        {             return 
node; 
        } 
        if (value < node->data)  
        { 
            return search(node->left, value); 
        } 
        return search(node->right, value); 
    } 
    void inorder(Node* node)  
    {         if (node == 
nullptr) 
            return;         
inorder(node->left);         cout 
<< node->data << " "; 
        inorder(node->right); 
    } 
    void level(Node* node)  
    {         if (node == 
nullptr)             return; 
        queue<Node*> q;         
q.push(node); 
        while (!q.empty())  
        { 
            Node* temp = q.front();             
q.pop();             cout << temp
>data << " "; 
            if (temp->left != nullptr)  
            { 
                q.push(temp->left); 
            } 
            if (temp->right != nullptr)  
            { 
                q.push(temp->right); 
            } 
        } 
        cout << endl; 
    } 
}; 
int main()  
{ 
    BinarySearchTree tree;     
int ch, val, key; 
    do {         cout << "\nMenu:\n";         
cout << "1. Insert Node\n";         cout << 
"2. Search Node\n";         cout << "3. 
Find Small Value\n";         cout << "4. 
Height Of Tree\n";         cout << "5. Swap 
Children\n";         cout << "6. Inorder 
Display\n";         cout << "7. Level Order 
Display\n";         cout << "8. Exit\n";         
cout << "Enter your choice: ";         cin >> 
ch; 
        switch(ch)         {             case 1:                 
cout << "Enter value to insert: ";                 
cin >> val; 
                tree.root = tree.insert(tree.root, val);                  
break; 
            case 2: 
                cout << "Enter value to search: "; 
                cin >> key; 
                if (tree.search(tree.root, key) != nullptr)   
                { 
                    cout << "Value " << key << " found in the tree." << endl; 
                } else { 
                    cout << "Value " << key << " not found in the tree." << endl; 
                }                 
break;             
case 3: 
                cout << "Small Value: " << tree.small(tree.root) << endl;                  
break;             case 4: 
                cout << "Height of Tree: " << tree.height(tree.root) << endl;                  
break;             case 5: 
                tree.swapChildren(tree.root);   
                cout << "Children swapped in the tree." << endl;                 
break;             case 6: 
                cout << "Inorder Display: ";                 
tree.inorder(tree.root);                  
cout << endl;                 break;             
case 7: 
                cout << "Level Wise Display: "; 
                tree.level(tree.root);  
                break;             case 8:                 
cout << "Exiting..." << endl; 
                break;             
default: 
                cout << "Invalid choice, please try again!" << endl; 
        } 
    } while (ch != 8);  
    return 0; 
} 


Output : student@student-OptiPlex-3010:~/Local$ g++ 
dsal6.cpp student@student-OptiPlex-3010:~/Local$ 
./a.out 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 1 
Enter value to insert: 20 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 1 
Enter value to insert: 30 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 1 
Enter value to insert: 40 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 1 
Enter value to insert: 50 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 2 
Enter value to search: 30 
Value 30 found in the tree. 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 2 Enter 
value to search: 10 Value 10 
not found in the tree. 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 3 Small 
Value: 20 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 4 
Height of Tree: 4 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display8. Exit 
Enter your choice: 6 Inorder 
Display: 20 30 40 50  
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 7 
Level Wise Display: 20 30 40 50  
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. ExitEnter your choice: 5 Children swapped in the tree. 
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 7 Level Wise 
Display: 20 30 40 50  
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 6 Inorder 
Display: 50 40 30 20  
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 7 Level Wise 
Display: 20 30 40 50  
Menu: 
1. Insert Node 
2. Search Node 
3. Find Small Value 
4. Find Depth Value 
5. Swap Children 
6. Inorder Display 
7. Level Order Display 
8. Exit 
Enter your choice: 8 Exiting... 
student@student-OptiPlex-3010:~/Local$  
