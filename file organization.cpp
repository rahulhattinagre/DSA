#include <iostream> 
#include <fstream> 
#include <cstring> 
using namespace std; 
struct Employee  
{ 
int id; 
char name[50]; 
char designation[50]; 
float salary; 
}; 
struct Index  
{ 
int id;         
long dataPos;    
}; 
void addEmployee(); 
void deleteEmployee(); 
void displayEmployee(); 
long searchEmployee(int id); 
const char *dataFile = "EmployeeData.dat"; 
const char *indexFile = "EmployeeIndex.dat"; 
int main()  
{ 
int choice; 
while (true)  
{ 
cout << "Employee Information :" << endl; 
cout << "1. Add Employee" << endl; 
cout << "2. Delete Employee" << endl; 
cout << "3. Display Employee" << endl; 
cout << "4. Exit" << endl; 
cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice)  
        { 
            case 1: 
                addEmployee(); 
                break; 
            case 2: 
                deleteEmployee(); 
                break; 
            case 3: 
                displayEmployee(); 
                break; 
            case 4: 
                cout << "Exiting..." << endl; 
                return 0; 
            default: 
                cout << "Invalid choice. Please try again." << endl; 
        } 
    } 
 
    return 0; 
} 
 
void addEmployee()  
{ 
    Employee emp; 
    Index idx; 
 
    cout << "Enter Employee ID: "; 
    cin >> emp.id; 
    cout << "Enter Employee Name: "; 
    cin.ignore(); 
    cin.getline(emp.name, 50); 
    cout << "Enter Designation: "; 
    cin.getline(emp.designation, 50); 
    cout << "Enter Salary: "; 
    cin >> emp.salary; 
 
    ofstream dataFileStream(dataFile, ios::app | ios::binary); 
    dataFileStream.seekp(0, ios::end); 
    long dataPos = dataFileStream.tellp(); 
    dataFileStream.write((char*)&emp, sizeof(Employee)); 
    dataFileStream.close(); 
 
    ofstream indexFileStream(indexFile, ios::app | ios::binary); 
    idx.id = emp.id; 
    idx.dataPos = dataPos; 
    indexFileStream.write((char*)&idx, sizeof(Index)); 
    indexFileStream.close(); 
} 
cout << "Employee added successfully!" << endl; 
void deleteEmployee()  
{ 
int id; 
cout << "Enter Employee ID to delete: "; 
cin >> id; 
long pos = searchEmployee(id); 
if (pos == -1)  
{ 
cout << "Employee not found!" << endl; 
return; 
} 
fstream dataFileStream(dataFile, ios::in | ios::out | ios::binary); 
Employee emp; 
dataFileStream.seekg(pos); 
dataFileStream.read((char*)&emp, sizeof(Employee)); 
strcpy(emp.name, "");  
strcpy(emp.designation, "");  
emp.salary = 0;           
dataFileStream.seekp(pos); 
dataFileStream.write((char*)&emp, sizeof(Employee)); 
dataFileStream.close(); 
cout << "Employee deleted successfully!" << endl; 
} 
void displayEmployee()  
{ 
int id; 
cout << "Enter Employee ID to display: "; 
cin >> id; 
long pos = searchEmployee(id); 
if (pos == -1)  
{ 
cout << "Employee not found!" << endl; 
return; 
} 
ifstream dataFileStream(dataFile, ios::binary); 
Employee emp; 
dataFileStream.seekg(pos); 
dataFileStream.read((char*)&emp, sizeof(Employee)); 
dataFileStream.close(); 
cout << "Employee ID: " << emp.id << endl; 
cout << "Name: " << emp.name << endl; 
cout << "Designation: " << emp.designation << endl; 
cout << "Salary: " << emp.salary << endl; 
} 
long searchEmployee(int id)  
{ 
ifstream indexFileStream(indexFile, ios::binary); 
Index idx; 
while (indexFileStream.read((char*)&idx, sizeof(Index)))  
{ 
if (idx.id == id) { 
indexFileStream.close(); 
return idx.dataPos; 
} 
} 
indexFileStream.close(); 
return -1; 
} 
Output : 
PS G:\4th Sem\DSA\Pratical\output> & .\'file2.exe' 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 1 
Enter Employee ID: 72 
Enter Employee Name: Rahul 
Enter Designation: pune 
Enter Salary: 200000 
Employee added successfully! 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 1 
Enter Employee ID: 76 
Enter Employee Name: Harsh 
Enter Designation: Pune 
Enter Salary: 25000 
Employee added successfully! 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 1 
Enter Employee ID: 71 
Enter Employee Name: Anil 
Enter Designation: Solapur 
Enter Salary: 30000 
Employee added successfully! 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 3 
Enter Employee ID to display: 76 
Employee ID: 76 
Name: Raj 
Designation: pune 
Salary: 280000 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 2 
Enter Employee ID to delete: 76 
Employee deleted successfully! 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 3 
Enter Employee ID to display: 76 
Employee ID: 76 
Name: 
Designation: 
Salary: 0 
Employee Information : 
1. Add Employee 
2. Delete Employee 
3. Display Employee 
4. Exit 
Enter your choice: 4 
Exiting... 
