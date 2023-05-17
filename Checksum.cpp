#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<11> receivedData("10101100111");  // 수신된 데이터 열
    bitset<5> generator("10011");  // 생성 다항식

    bitset<15> encodedData;

    for(int i=0;i<11;i++) {
        encodedData[i]=receivedData[i];
    }

    for (int i=11;i<15;i++) {
        encodedData[i]=encodedData[i-4]^encodedData[i-5]^encodedData[i-10]^encodedData[i-11];
    }

    // 체크섬 계산
    bitset<4> checksum;
    for (int i=0;i<4;i++) {
        checksum[i]=encodedData[i+11];
    }

    cout << "Received Data: " << receivedData << endl;
    cout << "Checksum: " << checksum << endl;

    bool hasError = false;
    for (int i=0;i<4;i++) {
        if (checksum[i]!=0) {
            hasError=true;
            break;
        }
    }

    if (hasError) {
        cout << "에러 있음" << endl;
    } else {
        cout << "에러 없음" << endl;
    }

    return 0;
}
