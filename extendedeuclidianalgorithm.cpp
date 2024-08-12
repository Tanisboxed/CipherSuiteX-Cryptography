#include <iostream>
using namespace std;

int exec(int a, int b, int x1, int x2){
    if(b==0){
        return x1;
    }
    int q,r,x;
    q=a/b;
    r=a%b;
    x=x1-(q*x2);
    return exec(b,r,x2,x);
}


int main(){
    int a,m,mulIn;
    cin >> a >> m;
    if (a>m){
        mulIn=exec(a,m,1,0);
    }
    else if(m>a){
        mulIn=exec(m,a,0,1);
    }
    cout <<mulIn;
    return 0;
}