#include<bits/stdc++.h>
using namespace std;

int fact(int n){
 int fact = 1;
 for(int i=2; i<=n; i++)
    fact*=i;
    return fact;
}

double newtonForwardInter(double x[],double y[],int n,double val){
 double diffTable[n][n];
 for(int i=0; i<n; i++)
    diffTable[i][0] = y[i];
 for(int j=1; j<n; j++){
    for(int i=0; i<n-j; i++){
        diffTable[i][j] = diffTable[i+1][j-1]-diffTable[i][j-1];
    }
 }
 cout<<"\nForward Difference Table : "<<endl;
 for(int i=0; i<n; i++){
    cout<<setw(10)<<x[i];
    for(int j=0; j<n-i; j++){
        cout<<setw(10)<<diffTable[i][j];
    }
    cout<<endl;
 }
 double h = x[1]-x[0];
 double p = (val - x[0])/h;
 double result = y[0];
 double term = 1;
 for(int j=1; j<n; j++){
    term*=(p-(j-1));
    result+=(term*diffTable[0][j])/fact(j);
 }
 return result;
}

int main(){
 int n;
 cout<<"Enter number of data points: ";
 cin>>n;
 double x[n],y[n];
 cout<<"Enter values of x and y : "<<endl;
 for(int i=0; i<n; i++){
    cout<<"x["<<i<<"]=";
    cin>>x[i];
    cout<<"y["<<i<<"]=";
    cin>>y[i];
 }
 double val;
 cout<<"Enter the value to interpolate: ";
 cin>>val;
 double result = newtonForwardInter(x,y,n,val);
 cout<<"Interpolated value at x = "<<val<<" is "<<result<<endl;

 return 0;
}
