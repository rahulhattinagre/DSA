#include<iostream> 
#define MAX 50 
using namespace std; 
class priority 
{ 
public: 
string name; 
int pri; 
}; 
class Queue 
{ 
{ 
public: 
priority arr[MAX]; 
int rear; 
int front; 
Queue() 
rear = -1; 
front = -1; 
} 
bool isfull() 
Assignment No: 8 
{ 
if(rear == MAX-1) 
{ 
return true; 
} 
return false; 
} 
bool empty() 
{ 
if(rear == front || rear == -1) 
{ 
return true; 
} 
return false; 
} 
string check(int No) 
{ 
if(No == 1) 
{ 
return "Genral Checkup\n"; 
} 
else if(No == 2) 
{ 
return "Non-Serious\n"; 
} 
else if(No == 3) 
{ 
return "Serious\n"; 
} 
else 
return "Invalid\n"; 
} 
void enqueue(priority p) 
{ 
if(isfull()) 
{ 
cout<<"Queue is full\n"; 
} 
else 
{ 
int i = rear; 
while(i >= 0 && p.pri > arr[i].pri) 
{ 
arr[i + 1] = arr[i]; 
i--;  
} 
arr[i+1] = p; 
rear++; 
} 
} 
void dequeue() 
{ 
if(empty()) 
{ 
cout<<"Queue is empty\n"; 
} 
else 
{ 
front++; 
cout<<arr[front].name<<" : "; 
cout<<check(arr[front].pri); 
} 
} 
}; 
int main() 
{  
Queue obj; 
int count = 0; 
cout<<"Enter the count of patient : "; 
cin>>count; 
for(int i = 0; i < count; i++) 
{ 
priority p; 
cout<<"Enter the name of patient : "; 
cin>>p.name; 
cout<<"Enter the priority of patient : "; 
cin>>p.pri; 
obj.enqueue(p); 
} 
cout<<"\nData of Patient : \n"; 
while(!obj.empty()) 
{ 
obj.dequeue(); 
} 
return 0; 
} 
Output: 
student@student-OptiPlex-3010:~$ g++ prac8.cpp 
student@student-OptiPlex-3010:~$ ./a.out 
Enter the count of patient : 3 
Enter the name of patient : Rahul 
Enter the priority of patient : 2 
Enter the name of patient : Sahil 
Enter the priority of patient : 1 
Enter the name of patient : Anil 
Enter the priority of patient :3 
Data of Patient : 
Anil : Serious 
Rahul : Non-Serious 
Sahil : Genral Checkup 
