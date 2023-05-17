#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<14> receivedData("10101110111010");  // 수신된 데이터 열
    bitset<5> generator("10011");  // 생성 다항식

    bitset<18> encodedData;

    for (int i = 0; i < 14; i++) {
        encodedData[i] = receivedData[i];
    }

    for (int i = 14; i < 18; i++) {
        encodedData[i] = encodedData[i - 4] ^ encodedData[i - 5] ^ encodedData[i - 10] ^ encodedData[i - 11];
    }

    // 체크섬 계산
    bitset<4> checksum;
    for (int i = 14; i < 18; i++) {
        checksum[i - 14] = encodedData[i];
    }

    cout << "Received Data: " << receivedData << endl;
    cout << "Checksum: " << checksum << endl;

    // 오류 판별
    bool hasError = false;
    for (int i = 0; i < 4; i++) {
        if (checksum[i] != 0) {
            hasError = true;
            break;
        }
    }

    if (hasError) {
        cout << "에러 발견. 수정하겠음." << endl;

        // 오류 비트의 위치 확인
        int errorPosition = 0;
        for (int i = 0; i < 4; i++) {
            if (checksum[i] == 1) {
                errorPosition += (1 << i);
            }
        }

        // 오류 비트를 정정
        receivedData.flip(errorPosition - 1);

        cout << "Edit Data: " << receivedData << endl;
    } else {
        cout << "에러 없음" << endl;
    }

    return 0;
}


