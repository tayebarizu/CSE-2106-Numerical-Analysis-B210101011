#include<bits/stdc++.h>
using namespace std;

double f(double x){
 return x*x-4;
}

double df(double x){
 return 2*x;
}

void newtonRapshon(double x0,int maxit,double tol){
 double x=x0;
 for(int i=0; i<maxit;i++){
    double fx = f(x);
    double dfx = df(x);
    if(dfx == 0){
        cout<<"Derivative is zero.No solution found."<<endl;
        return;
    }
    double x_new = x-fx/dfx;
    cout<<"Iteration "<<i+1<<": x = "<<x_new<<endl;
    if(fabs(x_new-x)<tol){
        cout<<"Root found:"<<x_new<<endl;
        return;
    }
    x = x_new;
 }
 cout<<"Maximum iterations reached. Approximate root: "<<x<<endl;
}

int main(){
 double initialGuess = 2.0;
 int maxit = 10;
 double tol = 1e-6;

 newtonRapshon(initialGuess,maxit,tol);

 return 0;
}
