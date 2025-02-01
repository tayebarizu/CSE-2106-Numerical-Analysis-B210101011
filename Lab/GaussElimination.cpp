#include<bits/stdc++.h>
using namespace std;

void gaussEli(double a[][10],int n){
 for(int i=0; i<n; i++){
    if(a[i][i]==0){
        cout<<"Mathematical Error: Division by zero."<<endl;
        return;
    }
    for(int j=i+1; j<n; j++){
        double ratio = a[j][i]/a[i][i];
        for(int k=0; k<=n; k++){
            a[j][k] -=ratio*a[i][k];
        }
    }
  }
  double x[n];
  for(int i=n-1; i>=0; i--){
    x[i] = a[i][n];
    for(int j = i+1; j<n; j++){
        x[i]-=a[i][j]*x[j];
    }
    x[i]/=a[i][i];
  }
  cout<<"Solution : "<<endl;
  for(int i=0; i<n; i++){
    cout<<"x"<<i+1<<"="<<x[i]<<endl;
  }
}

int main(){
 int n;
 cout<<"Enter number of equations:"<<endl;
 cin>>n;
 double a[10][10];
 cout<<"Enter the augmented matrix (coefficients & RHS values) : "<<endl;
 for(int i=0; i<n; i++){
    for(int j=0; j<=n; j++){
        cin>>a[i][j];
    }
 }
 gaussEli(a,n);

 return 0;
}
