#include <iostream>
#include <bitset>
using namespace std;

int main() {
    bitset<14> receivedData("10101110111010");  // ���ŵ� ������ ��
    bitset<5> generator("10011");  // ���� ���׽�

    bitset<18> encodedData;

    for (int i = 0; i < 14; i++) {
        encodedData[i] = receivedData[i];
    }

    for (int i = 14; i < 18; i++) {
        encodedData[i] = encodedData[i - 4] ^ encodedData[i - 5] ^ encodedData[i - 10] ^ encodedData[i - 11];
    }

    // üũ�� ���
    bitset<4> checksum;
    for (int i = 14; i < 18; i++) {
        checksum[i - 14] = encodedData[i];
    }

    cout << "Received Data: " << receivedData << endl;
    cout << "Checksum: " << checksum << endl;

    // ���� �Ǻ�
    bool hasError = false;
    for (int i = 0; i < 4; i++) {
        if (checksum[i] != 0) {
            hasError = true;
            break;
        }
    }

    if (hasError) {
        cout << "���� �߰�. �����ϰ���." << endl;

        // ���� ��Ʈ�� ��ġ Ȯ��
        int errorPosition = 0;
        for (int i = 0; i < 4; i++) {
            if (checksum[i] == 1) {
                errorPosition += (1 << i);
            }
        }

        // ���� ��Ʈ�� ����
        receivedData.flip(errorPosition - 1);

        cout << "Edit Data: " << receivedData << endl;
    } else {
        cout << "���� ����" << endl;
    }

    return 0;
}


