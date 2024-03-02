#include <iostream>
#include <memory>

int main() {
    int size = 5; // ������ ������������� �������

    // ������� ������������ ������ ����� ����� � ������� unique_ptr
    std::unique_ptr<int[]> dynamicArray(new int[size]);

    // �������������� ������������ ������
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 10;
    }

    // ������� �������� ������������� �������
    for (int i = 0; i < size; i++) {
        std::cout << "������� " << i << ": " << dynamicArray[i] << std::endl;
    }

    // ��������� ����������� ������������� ��� ������ �� ������� ���������
    return 0;
}
