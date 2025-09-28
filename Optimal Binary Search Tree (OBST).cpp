#include<iostream> using 
namespace std;  
  
void ConstructOBST(float p[],float q[],int n,float c[][20],int r[][20],float w[][20]){     
for(int i=0;i<=n;i++){         c[i][i]=0;         r[i][i]=0;         w[i][i]=q[i];  
    }  
    for (int len=1;len<=n;len++){         
for(int i=0;i<=n-len;i++){             
int j=i+len;  
            w[i][j]=p[j]+q[j]+w[i][j-1];             
c[i][j]=9999;  
  
            for(int k=i+1;k<=j;k++){  
                float cost=c[i][k-1]+c[k][j]+w[i][j];                 
if(cost<c[i][j]){                     c[i][j]=cost;                     
r[i][j]=k;  
                }  
            }  
       }  
    }  
}  
  
void PrintOBST(int r[][20],int i,int j){     
if(i>=j){         return;  
    }   
        int root=r[i][j];  
        cout<<" Root of Subtree [" <<i<<","<<j<<"] is key "<<root<<endl;  
  
        if(i<root-1){  
            cout<<" Left Child of "<<root<<" :";  
            PrintOBST(r,i,root-1);  
        }  
        if(root<j){  
            cout<<" Right Child of "<<root<<" :";  
            PrintOBST(r,root,j);  
        }  
}  
int main(){  
    int n;  
    cout<<"Enter number of keys :";     
cin>>n;  
  
    float p[10]={0};     
float q[10]={0};     float 
c[20][20]={0};    int 
r[20][20]={0};     float 
w[20][20]={0};  
  
    cout<<"\nEnter success probabilities (p[i]) for "<<n<<" keys:"<<endl;     
for(int i=1;i<=n;i++){         cout<<"Enter p["<<i<<"]: ";         cin>>p[i];  
    }  
  
    cout<<"\nEnter unsuccessful probabilities (q[i]) for "<<n<<" keys:"<<endl;     
for(int i=0;i<=n;i++){         cout<<"Enter q["<<i<<"]: ";         cin>>q[i];  
          
    }  
  
    ConstructOBST(p,q,n,c,r,w);  
  
    cout<<"\nOptimal BST Weight: "<<w[0][n]<<endl;     
cout<<"\nOptimal BST Cost: "<<c[0][n]<<endl;     cout<<"\nRoot 
of the Optimal BST: key "<<r[0][n]<<endl;  
      
  
    cout << "\nOptimal Binary Search Tree Structure:\n";  
    PrintOBST(r, 0, n);  
  
    return 0;  
}  
OUTPUT:  
Enter number of keys :4  
  
Enter success probabilities (p[i]) for 4 keys:  
Enter p[1]: 3  
Enter p[2]: 3  
Enter p[3]: 1   
Enter p[4]: 1  
Enter unsuccessful probabilities (q[i]) for 4 keys:  
Enter q[0]: 2  
Enter q[1]: 3  
Enter q[2]: 1  
Enter q[3]: 1  
Enter q[4]: 1  
Optimal BST Weight: 16  
Optimal BST Cost: 32  
Root of the Optimal BST: key 2  
Optimal Binary Search Tree Structure:  
Root of Subtree [0,4] is key 2  
Left Child of 2 : Root of Subtree [0,1] is key 1  
Right Child of 2 : Root of Subtree [2,4] is key 3  
Right Child of 3 : Root of Subtree [3,4] is key 4  
PS C:\Users\sits\Desktop\CPP>  
