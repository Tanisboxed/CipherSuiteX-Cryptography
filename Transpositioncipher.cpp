#include <iostream>
#include <cstring>
using namespace std;

string encry(int nrow,int lenofkey, int lenofmsg,string msg, int colval[]){
    int x=0;
    char em[nrow+1][lenofkey];
    for (int i=0;i<nrow+1;i++){
        for (int j=0;j<nrow+1;j++){
            if (x>=lenofmsg){
                em[i][j]=' ';
            }
            else{
                em[i][j]=msg[x];
            }
            x++;
        }
    }
    int t=1;
    string cipher= "";
    while(t<=lenofkey){
        for (int i=0;i<lenofkey;i++){
            int k=colval[i];
            if(k==t){
                for(int j=0;j<nrow+1;j++){
                    cipher+=em[j][i];
                }
                t++;
            }
        }
    }
    return cipher;
} 

string decry(int nrow,int lenofkey, string cipher, int colval[]){
    char dm[nrow+1][lenofkey];
    int x=0,t=1;
    while(t<lenofkey){
        for(int i=0;i<lenofkey;i++){
            int k=colval[i];
            if (k==t){
                for(int j =0;j<nrow+1;j++){
                    dm[j][i]=cipher[x];
                    x++;
                }
                t++;
            }
        }
    }
    string msg="";
    for(int i=0;i<nrow+1;i++){
        for (int j=0;j<lenofkey;j++){
            if (dm[i][j] =='_'){
                dm[i][j]=' ';
            }
            msg+=dm[i][j];
        }
    }
    return msg;
}

int main(){
    string msg,key;
    getline(cin,msg);
    getline(cin,key);
    int lenofkey = key.length();
    int lenofmsg = msg.length();
    int count=0, val=1, ind;
    int colval[lenofkey];
    memset(colval,0,sizeof(colval));
    while(count <lenofkey){
        int min =999;
        for (int i=0;i<lenofkey;i++){
            if ((min >int(key[i]))&&(colval[i]==0)){
                min =int(key[i]);
                ind=i;
            }
        }
        colval[ind]=val;
        count++;
        val++;
    }
    int nrow=lenofmsg/lenofkey;
    string cipher= " ";
    cipher= encry(nrow,lenofkey,lenofmsg,msg,colval);
    cout << "Encrypted text: " << cipher <<endl;
    string decrypted=" ";
    decrypted = decry(nrow,lenofkey,cipher,colval);
    cout << "Decrypted text: " << decrypted << endl;
}
