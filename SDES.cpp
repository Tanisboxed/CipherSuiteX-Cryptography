#include <iostream>
#include <bitset>
using namespace std;

bitset<8> IP(bitset<8> in) {
    bitset<8> out;
    out[7] = in[1];
    out[6] = in[5];
    out[5] = in[2];
    out[4] = in[0];
    out[3] = in[3];
    out[2] = in[7];
    out[1] = in[4];
    out[0] = in[6];
    return out;
}

bitset<8> IP_inv(bitset<8> in) {
    bitset<8> out;
    out[7] = in[3];
    out[6] = in[0];
    out[5] = in[4];
    out[4] = in[1];
    out[3] = in[6];
    out[2] = in[2];
    out[1] = in[7];
    out[0] = in[5];
    return out;
}

bitset<4> SBox(bitset<4> input, bool sbox1) {
    int sbox[2][4][4] = {
        {
            {1, 0, 3, 2},
            {3, 2, 1, 0},
            {0, 2, 1, 3},
            {3, 1, 3, 2}
        },
        {
            {0, 1, 2, 3},
            {2, 0, 1, 3},
            {3, 0, 1, 0},
            {2, 1, 0, 3}
        }
    };

    int row = input[3] * 2 + input[0];
    int col = input[2] * 2 + input[1];

    int value = sbox[sbox1][row][col];

    bitset<4> result(value);
    return result;
}

bitset<4> fK(bitset<4> left, bitset<4> right, bitset<8> key) {
    bitset<8> exp;
    exp[7] = right[3];
    exp[6] = right[0];
    exp[5] = right[1];
    exp[4] = right[2];
    exp[3] = right[1];
    exp[2] = right[2];
    exp[1] = right[3];
    exp[0] = right[0];

    bitset<8> xor_res = exp ^ key;

    bitset<4> left_sbox = SBox(bitset<4>((xor_res >> 4).to_ulong()), true);
    bitset<4> right_sbox = SBox(bitset<4>(xor_res.to_ulong()), false);

    bitset<4> result;
    result[3] = left_sbox[1];
    result[2] = right_sbox[1];
    result[1] = right_sbox[3];
    result[0] = left_sbox[3];

    return result ^ left;
}

bitset<8> SDES(bitset<8> pt, bitset<8> key1, bitset<8> key2) {
    bitset<8> ip = IP(pt);
    bitset<4> left(ip.to_ulong() >> 4);
    bitset<4> right(ip.to_ulong());

    bitset<4> fk1 = fK(left, right, key1);
    left = right;
    right = fk1;

    bitset<4> fk2 = fK(left, right, key2);

    bitset<8> preoutput;
    preoutput = (fk2.to_ulong() << 4) | right.to_ulong();
    bitset<8> final_result = IP_inv(preoutput);
    final_result[2] = 0;
    return final_result;
    
}

int main() {
    string ptstr, key1str, key2str; 
    cin >> ptstr;
    cin >> key1str;
    cin >> key2str;
    bitset<8> PT(ptstr);
    bitset<8> key1(key1str);
    bitset<8> key2(key2str);
    bitset<8> CT = SDES(PT, key1, key2);
    cout << CT;
    return 0;
}
