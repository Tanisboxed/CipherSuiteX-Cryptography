#include <iostream>
#include <string>
using namespace std;

string p10(string userinput){
    int p10[]={3,5,2,7,4,10,1,9,8,6};
    string perm10="";
    for(int i=0;i<10;++i){
        perm10+=userinput[p10[i]-1]; 
    }
    return perm10;
} 

string p8(string userinput){
    int p8[]={6,3,7,4,8,5,10,9};
    string perm8="";  
    for (int i=0;i<8; ++i){  
        perm8+=userinput[p8[i]-1]; 
    }
    return perm8;
} 

string splitshiftkey(string userinput,int n){
    string left=userinput.substr(0,5);
    string right=userinput.substr(5);
    //left circular shift
    left=left.substr(n)+left.substr(0,n);
    right= right.substr(n) +right.substr(0,n);
    return left+right;
}

int main(){
    string userinput,newkey,key1,key2;
    getline(cin, userinput);
    userinput=p10(userinput);
    newkey=splitshiftkey(userinput,1);
    key1=p8(newkey);
    newkey=splitshiftkey(newkey,2);
    key2=p8(newkey);
    cout<<key1 <<endl;
    cout<<key2;
}
