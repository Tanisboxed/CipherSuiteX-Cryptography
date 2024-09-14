#include <iostream>
using namespace std;

string encry(string s, int key){
    string cipher="";
    int size=s.length();
    for(int i = 0; i < size; i++){
        if (isupper(s[i])){
            cipher +=char((int(s[i])+key-65)%26 + 65);
        }else if (islower(s[i])){
            cipher +=char((int(s[i])+key-97)%26 + 97 );
        }else if(s[i]==' '){
            cipher += " ";
        }
        else{
            cipher +=char((int(s[i])+key-48)%10 +48);
        }
    }
    return cipher;
}
string decry(string cipher, int key){
    string decipher="";
    int size=cipher.length();
    for (int i=0;i<size;i++){
        if (isupper(cipher[i])){
            decipher +=char((int(cipher[i])-key-65)%26 + 65);
        }else if (islower(cipher[i])){
            decipher +=char((int(cipher[i])-key-97)%26 + 97 );
        }else if (cipher[i]==' '){
            decipher += " ";
        }
        else{
            decipher +=char((int(cipher[i])-key-48)%10 +48);
        }        
    }
    return decipher;
}

int main(){
    string s;
    int key;
    getline(cin,s);
    cin >> key;
    string cipher=encry(s,key);
    string decipher=decry(cipher,key);
    cout << "Encrypted text: " << cipher;
    cout << "\nDecrypted text: " << decipher;
}
