#include <iostream>
#include <stdexcept>
#include <Windows.h>

template <typename T>
class SimpleVector {
private:
    T* data;          // указатель на данные
    int currentSize;  // текущий размер
    int currentCapacity;  // текущая вместимость

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        currentCapacity = newCapacity;
    }

public:
    SimpleVector() : data(nullptr), currentSize(0), currentCapacity(0) {}

    ~SimpleVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (currentSize == currentCapacity) {
            int newCapacity = currentCapacity == 0 ? 1 : currentCapacity * 2;
            resize(newCapacity);
        }
        data[currentSize++] = value;
    }

    T& at(int index) {
        if (index < 0 || index >= currentSize) {
            throw std::out_of_range("Вне диапазона");
        }
        return data[index];
    }

    int size() const {
        return currentSize;
    }

    int capacity() const {
        return currentCapacity;
    }
};

// Пример использования SimpleVector
int main() {

    setlocale(LC_ALL, "RU");
    SimpleVector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Элементы в векторе: ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Размер: " << vec.size() << std::endl;
    std::cout << "Вместимость: " << vec.capacity() << std::endl;

    return 0;
}
