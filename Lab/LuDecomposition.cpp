#include<bits/stdc++.h>
using namespace std;
#define n 3

void luDe(float a[n][n],float l[n][n],float u[n][n]){
 for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        l[i][j] = (i==j)?1:0;
        u[i][j] = 0;
    }
 }
 for(int k = 0; k<n; k++){
    for(int j=k; j<n; j++){
        float sum = 0;
    for( int p = 0; p<k; p++)
        sum += l[k][p]*u[p][j];
    u[k][j] = a[k][j] - sum;
 }
 for(int i = k+1; i<n; i++){
    float sum = 0;
    for(int p = 0; p<k; p++)
        sum += l[i][p]*u[p][k];
    l[i][k] = (a[i][k]-sum)/u[k][k];
 }
}
}

void display(float m[n][n]){
 for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cout<<m[i][j]<<" ";
    }
    cout<<endl;
 }
}

int main(){
 float a[n][n] = {{2,-1,-2},
                  {-4,6,3},
                  {-4,-2,8}

                  };
 float l[n][n],u[n][n];
 cout<<"Original Matrix A : "<<endl;
 display(a);

 luDe(a,l,u);

 cout<<"Lower Triangular Matrix : "<<endl;
 display(l);

 cout<<"Upper Triangular Matrix : "<<endl;
 display(u);

 return 0;

}
