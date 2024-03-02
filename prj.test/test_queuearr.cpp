#include <iostream>
#include <memory>

int main() {
    int size = 5; // Размер динамического массива

    // Создаем динамический массив целых чисел с помощью unique_ptr
    std::unique_ptr<int[]> dynamicArray(new int[size]);

    // Инициализируем динамический массив
    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 10;
    }

    // Выводим элементы динамического массива
    for (int i = 0; i < size; i++) {
        std::cout << "Элемент " << i << ": " << dynamicArray[i] << std::endl;
    }

    // Указатель уничтожится автоматически при выходе из области видимости
    return 0;
}
