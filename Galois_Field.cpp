#include <iostream>
#include <vector>
using namespace std;

// Galois Field Table 구현
vector<int> GaloisFieldTable(int num) {
    vector<int> table(16, 0);  // 크기는 16부터 0000으로 돌아감. 

    for (int i = 0; i < 16; i++) {
        int value = i;
        for (int j = 0; j < 4; j++) {
            if (value & 0x8) {  // 가장 상위 비트 확인
                value = (value << 1) ^ num;
            } else {
                value <<= 1;
            }
        }
        table[i] = value;
    }

    return table;
}

int main() {
    int num = 0b10011;  // 다항식 g(x) = 1 + x + x^4
    vector<int> table = GaloisFieldTable(num);

    // Galois Field Table 출력
    cout << "Galois Field Table:" << endl;
    for (int i = 0; i < 16; i++) {
        cout << i << ": ";
        for (int j = 3; j >= 0; j--) {
            cout << ((table[i] & (1 << j)) >> j);
        }
        cout << endl;
    }

    return 0;
}


