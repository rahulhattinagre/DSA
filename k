#include <iostream>  
#include <string> #include 
<algorithm>  
using namespace std;  
  
class Node {   
public: string key;   
string value;   
Node * left;   
Node * right;   int 
height;  
  Node(string k, string v): key(k),   
value(v),   left(NULL),   
right(NULL),  
  height(1) {}  
};  
class Dictionary {   
public: Node * root;   
Dictionary() {  
    root = NULL;  
  }  
  int height(Node * node) {  
    return (node == NULL) ? 0 : node -> height;  
  }  
  int balance(Node * node) {  
    return (node == NULL) ? 0 : height(node -> left) - height(node -> right);  
  }  
  Node * rotateRight(Node * y) {  
    Node * x = y -> left;     
Node * T2 = x -> right;     
x -> right = y;     y -> left 
= T2;  
    y -> height = std::max(height(y -> left), height(y -> right)) + 1;     
x -> height = std::max(height(x -> left), height(x -> right)) + 1;  
  return x;  
}  
Node * rotateLeft(Node * x) {  
  Node * y = x -> right;   
Node * T2 = y -> left;   
y -> left = x;  
x -> right = T2;  
x -> height = std::max(height(x -> left), height(x -> right)) + 1;  
y -> height = std::max(height(y -> left), height(y -> right)) + 1; return y;  
} 
Node * insert(Node * node, string key, string value) {   
if (node == NULL) {     return new Node(key, value);  
  }  
  if (key < node -> key) {  
      node -> left = insert(node -> left, key, value);  
    } else if (key > node -> key) {  
      node -> right = insert(node -> right, key, value);  
    } else {       node -> 
value = value;  
      return node;  
    }  
    node -> height = 1 + std::max(height(node -> left), height(node -> right));     
int balance_factor = balance(node);     if (balance_factor > 1 && key < node -> left -> key) {       return rotateRight(node);  
    }  
    if (balance_factor < -1 && key > node -> right -> key) {       
return rotateLeft(node);  
    }  
    if (balance_factor > 1 && key > node -> left -> key) {       
node -> left = rotateLeft(node -> left);       return 
rotateRight(node);  
    }  
    if (balance_factor < -1 && key < node -> right -> key) {       
node -> right = rotateRight(node -> right);       return 
rotateLeft(node);  
    }  
    return node;  
  }  
  void create() {     string key, 
value;     cout << "\nEnter Key: 
";     getline(cin, key);     cout << 
"Enter Value: ";     getline(cin, 
value);     root = insert(root, key, 
value);  
  }  
  void displayAscending(Node * node) {  
    if (node == NULL)  
    return;  
  displayAscending(node -> left);  
  cout << node -> key << ": " << node -> value << endl;   
displayAscending(node -> right);  
}  
void displayDescending(Node * node) {  
if (node == NULL)  
return; 
displayDescending(node -> right);  
cout << node -> key << ": " << node -> value << endl; 
displayDescending(node -> left);  
} 
void update(Node * node, string key, string new_value) {  
  if (node == NULL) {  
    cout << "\nKey not found for update." << endl;     
return;  
    }  
    if (key < node -> key) {  
      update(node -> left, key, new_value);     
} else if (key > node -> key) {       
update(node -> right, key, new_value);  
    } else {  
      node -> value = new_value;  
      cout << "\nKey found and updated. New value: " << node -> value << endl;  
    }  
  }  
  int search(Node * node, string key, int comparisons) {  
    if (node == NULL) {       cout << "Key 
not found." << endl;       return 
comparisons;  
    }  
    comparisons++;     if (key == 
node -> key) {       cout << "\nKey 
found." << endl;       return 
comparisons;     } else if (key < 
node -> key) {  
      return search(node -> left, key, comparisons);  
    } else {  
      return search(node -> right, key, comparisons);  
    }  
  }  
  Node * findMax(Node * node) {     
while (node -> right != NULL) {  
      node = node -> right;  
    }  
    return node;  
  }  
  Node * remove(Node * node, string key) {  
    if (node == NULL)       
return node;     if (key < 
node -> key) {  
    node -> left = remove(node -> left, key);  
  } else if (key > node -> key) {  
    node -> right = remove(node -> right, key);  
  } else {  
    if (node -> left == NULL || node -> right == NULL) {  
      Node * temp = node -> left ? node -> left : node -> right;     
if (temp == NULL) {      temp = node;  
      node = NULL;  
    } else {  
      * node = * temp;  
     }  
      delete temp;  
    } else {  
      Node * temp = findMax(node -> left);       
node -> key = temp -> key;  
        node -> value = temp -> value;  
        node -> left = remove(node -> left, temp -> key);  
      }  
    }  
    if (node == NULL)       
return node;  
    node -> height = 1 + std::max(height(node -> left), height(node -> right));     
int balance_factor = balance(node);     if (balance_factor > 1 && 
balance(node -> left) >= 0) {       return rotateRight(node);  
    }  
    if (balance_factor < -1 && balance(node -> right) <= 0) {       
return rotateLeft(node);  
    }  
    if (balance_factor > 1 && balance(node -> left) < 0) {  
      node -> left = rotateLeft(node -> left);       
return rotateRight(node);  
    }  
    if (balance_factor < -1 && balance(node -> right) > 0) {       
node -> right = rotateRight(node -> right);       return 
rotateLeft(node);  
    }  
    return node;  
  }  
  void removeKey(string key) {  
    root = remove(root, key);  
  }  
};  
int main() {   int ch;   
Dictionary dict;   
string key;   string 
new_value;   int 
comparisons;  
  while (true) {  
  cout << "\n*********** MENU ***********";   
cout << "\n1. Create";  
  cout << "\n2. Display in Ascending Order";   
cout << "\n3. Display in Descending Order";   
cout << "\n4. Update";   cout << "\n5. 
Search Key";  
cout << "\n6. Delete Key"; 
cout << "\n7. Exit";  
cout << "\nEnter your choice: ";  
cin >> ch; 
cin.ignore();  switch 
(ch) {  
  case 1:     dict.create();     
break;   case 2:       if 
(dict.root != NULL) {  
        dict.displayAscending(dict.root);  
      } else {  
        cout << "Dictionary is empty." << endl;  
      }  
      break;     case 3:       if (dict.root != 
NULL) {         
dict.displayDescending(dict.root);  
      } else {  
        cout << "Dictionary is empty." << endl;  
      }  
      break;     
case 4:  
      cout << "\nEnter Key to update: ";       
getline(cin, key);       cout << "Enter new 
value: ";       getline(cin, new_value);       
dict.update(dict.root, key, new_value);  
      break;     
case 5:  
      comparisons = 0;       cout << 
"\nEnter Key to search: ";  
      getline(cin, key);  
      comparisons = dict.search(dict.root, key, comparisons);  
      cout << "\nComparisons made: " << comparisons << endl;       
break;     case 6:  
      cout << "\nEnter Key to delete: ";  
      getline(cin, key);       
dict.removeKey(key);  
      break;     case 7:       cout << 
"Exiting..." << endl;  
      return 0;    
default:  
     cout << "Invalid choice!" << endl;  
   }  
}  
} 

OUTPUT :  
{ g++ dsa12.cpp -o dsa12 } ; if ($?) { .\dsa12 }  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 1  
Enter Key: Name   
Enter Value: Rahul 
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 1  
Enter Key: Div  
Enter Value: B  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key 7. Exit  
Enter your choice: 1  
Enter Key: Branch  
Enter Value: cs  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 2  
Branch: cs  
Div: B  
Name: Rahul  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 3  
Name: Durvesh  
Div: B  
Branch: cs  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 4  
Enter Key to update: Div  
Enter new value: C  
Key found and updated. New value: C  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key 7. Exit  
Enter your choice: 1  
Enter Key: Fruit  
Enter Value: apple  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 2  
Branch: cs  
Div: C  
Fruit: apple  
Name: Rahul 
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 5  
Enter Key to search: Name  
Key found.  
Comparisons made: 2  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key 7. Exit  
Enter your choice: 6  
Enter Key to delete: Fruit  
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key 7. Exit  
Enter your choice: 2  
Branch: cs  
Div: C  
Name: Rahul 
*********** MENU ***********  
1. Create  
2. Display in Ascending Order  
3. Display in Descending Order  
4. Update  
5. Search Key  
6. Delete Key  
7. Exit  
Enter your choice: 7 Exiting...  
