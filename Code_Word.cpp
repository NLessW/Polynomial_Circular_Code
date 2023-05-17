#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<11> data("10101100111");  // 데이터 열
    bitset<5> generator("10011");  // 생성 다항식

    bitset<15> encodedData;

    for (int i = 0; i < 11; i++) {
        encodedData[i] = data[i];
    }

    for (int i = 11; i < 15; i++) {
        encodedData[i] = encodedData[i - 4] ^ encodedData[i - 5] ^ encodedData[i - 10] ^ encodedData[i - 11];
    }

    cout << "Encoded Data: " << encodedData << endl;

    return 0;
}
