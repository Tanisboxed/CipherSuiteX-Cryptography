#include <iostream>
using namespace std;

string generateKey(const string& str, const string& key) {
    string newKey = key;
    for (int i = 0; newKey.size() < str.size(); i++) {
        newKey.push_back(newKey[i % key.size()]);
    }
    return newKey;
}

string cipherText(const string& str, const string& key) {
    string cipher_text;
    for (size_t i = 0; i < str.size(); i++) {
        char x = (str[i] - 'a' + key[i] - 'a') % 26 + 'a';
        cipher_text.push_back(x);
    }
    return cipher_text;
}

string decry(const string& cipher_text, const string& key) {
    string orig_text;
    for (size_t i = 0; i < cipher_text.size(); i++) {
        char x = (cipher_text[i] - key[i] + 26) % 26 + 'a';
        orig_text.push_back(x);
    }
    return orig_text;
}

int main() {
    string str,keyword;
    getline(cin,str);
    getline(cin,keyword);
    string key = generateKey(str, keyword);
    string cipher_text = cipherText(str, key);
    cout << "New key generated: " << key << "\n";
    cout << "Encrypted text: " << cipher_text << "\n";
    cout << "Decrypted text: " << decry(cipher_text, key) << "\n";
    return 0;
}
