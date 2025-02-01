#include<bits/stdc++.h>
using namespace std;

void numericalDiff(double x[],double y[],int n,double val){
 double h = x[1]-x[0];
 double deri;
 int index = -1;
 for(int i=0;i<n;i++){
    if(x[i]==val){
        index = i;
        break;
    }
 }
 if(index == -1){
    cout<<"Error: x value not found in dataset. "<<endl;
    return;
 }
 if(index == 0){
    deri = (y[index + 1]-y[index])/h;
    cout<<"Using Forward Difference."<<endl;
 }
 else if(index == n-1){
    deri = (y[index]-y[index-1])/h;
    cout<<"Using Backward Difference."<<endl;
 }
 else{
    deri = (y[index+1]-y[index-1])/(2*h);
    cout<<"Using Central Difference."<<endl;
 }
 cout<<"Approximate Derivative at x = "<<val<<" is "<<deri<<endl;
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
 double val;
 cout<<"Enter the x value to differentiate : ";
 cin>>val;
 numericalDiff(x,y,n,val);

 return 0;
}
