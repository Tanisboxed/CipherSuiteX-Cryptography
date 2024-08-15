#include <iostream>
using namespace std;

int modInverse(int a, int m){
    for(int x=1;x<m;x++){
        if ((a*x)%m==1){
            return x;
        }
    }
    return -1;
}
int crt(int a[], int k[]){
    int m[3], minverse[3], M=1, y=0;
    for(int i=0;i<3;i++){
        M*=k[i];
    }
    for(int i=0;i<3;i++){
        m[i]=M/k[i];
        minverse[i]=modInverse(m[i],k[i]);
    }
    for(int i=0;i<3;i++){
        y+=(a[i]*m[i]*minverse[i]);
    }
    return y%M;
}
int main(){
    int a[3],k[3];
    for(int i=0;i<3;i++){
        cin >> a[i]>>k[i];
    }
    int result=crt(a,k);
    cout << result;
}