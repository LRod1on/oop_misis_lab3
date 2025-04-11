#include <iostream>
#include <memory>

class Data {
public:
    int value;
    // конструктор класса, создает число
    Data(int v) : value(v) { std::cout << "Data created" << std::endl; }
    // деструктор класса, уничтожает число
    ~Data() { std::cout << "Data destroyed" << std::endl; }
};

int main() {
    // сохранием указатель на выделенный объект класса
    auto gg1 = std::make_shared<Data>(100);
    std::cout << "Use count: " << gg1.use_count() << std::endl; // 1 овнер
    // добавляем совладельца оригинальному объекту
    auto gg2 = gg1;
    std::cout << "Use count: " << gg1.use_count() << std::endl; // 2 овнера
    return 0;
}