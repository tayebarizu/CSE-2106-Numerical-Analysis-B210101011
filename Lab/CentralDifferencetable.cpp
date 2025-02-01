#include<bits/stdc++.h>
using namespace std;

void centralDiffTable(double x[],double y[], int n){
 double diffTable[n][n];
 for(int i=0; i<n; i++){
    diffTable[i][0] = y[i];
 }
 for(int j=1; j<n; j++){
    for(int i=j; i<n-j; i++){
        diffTable[i][j] = (diffTable[i+1][j-1]-diffTable[i-1][j-1])/2.0;
    }
 }
 cout<<"\nCentral Difference Table : "<<endl;
 cout<<setw(10)<<"x"<<setw(10)<<"y";
 for(int j=1; j<n/2+1; j++){
    cout<<setw(10)<<"del^"<<j<<"y";
 }
 cout<<endl;
 for(int i=0; i<n; i++){
    cout<<setw(10)<<x[i];
    for(int j=0; j<n-i; j++){
        if(i>=j && i<n-j)
            cout<<setw(10)<<diffTable[i][j];
    }
    cout<<endl;
 }
}

int main(){
 int n;
 cout<<"Enter number of data points: ";
 cin>>n;
 double x[n],y[n];
 cout<<"Enter values of x and y : "<<endl;
 for(int i=0; i<n; i++){
    cout<<"x["<<i<<"] = ";
    cin>>x[i];
    cout<<"y["<<i<<"] = ";
    cin>>y[i];
 }
 centralDiffTable(x,y,n);

 return 0;
}
