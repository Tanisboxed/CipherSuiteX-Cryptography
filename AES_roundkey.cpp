#include <iostream>
#include <iomanip>
using namespace std;

unsigned char substituteBox(unsigned char value){
    switch (value){
        case 0x3A: return 0x80;
        case 0xF7: return 0x68;
        case 0xFA: return 0x2D;
        case 0xA0: return 0xE0;
        default: return value;
    }
}

void expandKey(unsigned char key[4][4],unsigned char rCon){
    unsigned char rotatedCol[4];
    for (int i=0;i<4;++i){
        rotatedCol[i]=key[i][3];
    }
    unsigned char temp=rotatedCol[0];
    rotatedCol[0]= rotatedCol[1];
    rotatedCol[1]=rotatedCol[2];
    rotatedCol[2]=rotatedCol[3];
    rotatedCol[3]=temp;
    for(int i=0;i<4;++i){
        rotatedCol[i] = substituteBox(rotatedCol[i]);
    }
    rotatedCol[0]^=rCon;
    for (int i=0;i<4;++i){
        key[i][0] ^= rotatedCol[i];
    }
    for (int j=1;j<4;++j){
        for(int i=0;i<4;++i){
            key[i][j] ^=key[i][j-1];
        }
    }
}

void displayKey(unsigned char key[4][4]){
    for (int i=0;i<4;++i){
        for (int j=0;j<4;++j){
            cout << "0x" << uppercase << hex << setw(2) << setfill('0') << (int)key[i][j] << " "; 
        }
        cout << endl;
    }
}
int main(){
    unsigned char secondRoundKey[4][4]={
        {0x56, 0xC7, 0x76, 0xA0},
        {0x08, 0x1A, 0x43, 0x3A},
        {0x20, 0xB1, 0x55, 0xF7},
        {0x07, 0x8F, 0x69, 0xFA}
    };
    unsigned char rCon = 0x04;
    expandKey(secondRoundKey,rCon);
    displayKey(secondRoundKey);
    return 0;
    
}
