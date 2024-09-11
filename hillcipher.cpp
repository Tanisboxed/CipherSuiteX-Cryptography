#include <iostream>
using namespace std;

string encry(string str, int keymat[][3]){
    int strvec[3], ciphervec[3],sum;
    for(int i=0;i<3;i++){
        strvec[i]=str[i]-'A';
    }
    for (int i=0;i<3;i++){
        sum=0;
        for(int j=0;j<3;j++){
            sum+=(keymat[i][j] * strvec[j]);
        }
        ciphervec[i]= sum %26;
    }
    for(int i=0;i<3;i++){
        str[i]=ciphervec[i] +'A';
    }
    return str;
}

string decry(string str,int invkeymat[3][3]){
    return encry(str,invkeymat);
}
int main(){
    string str,encrypt, decrypt;
    cin >> str;
    int keymat[3][3],invkeymat[3][3];
    for(int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            cin >> keymat[i][j];
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> invkeymat[i][j];
        }
    }
    encrypt=encry(str,keymat);
    decrypt=decry(encrypt,invkeymat);
    cout << "Encrypted text: " << encrypt <<endl;
    cout << "Decrypted text: " << decrypt;
    return 0;
}