#include <iostream.h>  
using namespace std;  
  
void primsMST(int n, vector<vector<int>> &cost)  
{  
    int s, mincost = 0;     cout << 
"Enter start vertex: ";  
    cin >> s;  
  
    vector<int> visit(n, 0);  
    visit[s] = 1;  
  
    for (int k = 0; k < n - 1; k++)  
    {         int min = 
999;  
        int  row = -1, col = -1;  
  
        for (int i = 0; i < n; i++)  
        {  
            if (visit[i] == 1)  
            {  
                for (int j = 0; j < n; j++)  
                {  
                    if (visit[j] == 0 && cost[i][j] != -1 && cost[i][j] < min)  
                    {  
                        min = cost[i][j];                         
row = i;                         col = j;  
                    }  
                }  
            }  
        }  
            mincost += min;             
visit[col] = 1;             
cost[row][col] = -1;             
cost[col][row] = -1;  
          
    }  
  
    cout << "Minimum Cost: " << mincost << endl;  
}  
  
  
  
int main() {  
    int n;  
    cout << "Enter number of cities: ";  
    cin >> n;  
  
    vector<string> cities(n);     
for (int i = 0; i < n; i++)  
    {  
        cout << "Enter City " << i + 1 << ": ";  
        cin >> cities[i];  
    }  
  
    vector<vector<int>> cost(n, vector<int>(n, -1));  
  
    char op;  
    for (int i = 0; i < n; i++)  
    {  
        for (int j = i + 1; j < n; j++)  
        {  
            cout << "Is there path between " << cities[i] << " and " << cities[j] << "? (Y/N): ";             
cin >> op;  
  
            if (op == 'Y' || op == 'y')  
            {  
                cout << "Enter the Cost: ";  
                cin >> cost[i][j];                 
cost[j][i] = cost[i][j];  
            }             
else             {  
                cost[i][j] = cost[j][i] = -1;  
            }  
        }  
    }  
  
    primsMST(n, cost);  
  
    return 0;  
}  
  
Output: student@student:~$ g++ 
Prims.cpp student@student:~$ 
./a.out Enter number of cities: 4  
Enter City 1: Nanded  
Enter City 2: Mumbai 
Enter City 3: karad  
Enter City 4: Pune  
Is there path between Nanded and Mumbai? (Y/N): y  
Enter the Cost: 2  
Is there path between Nanded and karad? (Y/N): y  
Enter the Cost: 1  
Is there path between Nanded and Pune? (Y/N): n  
Is there path between Mumbai and karad? (Y/N): y  
Enter the Cost: 2  
Is there path between mumbai and Pune? (Y/N): y  
Enter the Cost: 3  
Is there path between karad and Pune? (Y/N): y  
Enter the Cost: 4  
Enter start vertex: Nanded 
Minimum Cost: 6  
