#include <iostream>
#include <memory>

class Data {
public:
    int value;
    explicit Data(int v) : value(v) {
        std::cout << "Data created" << std::endl; 
    }
    Data() : value(0) { 
        std::cout << "Data created" << std::endl; 
    }
    ~Data() { 
        std::cout << "Data destroyed" << std::endl; 
    }
    };

int main() {

    std::weak_ptr<Data> weak;
    
    auto shared = std::make_shared<Data>(100);
    
    std::cout << "Before weak was created - " << shared.use_count() << std::endl;
    
     // добавляем weak
    weak = shared;
    
    std::cout << "After weak was created - " << shared.use_count() << std::endl;
    
    // поднимаем weak до shared во время работа блока if
    if (auto nw = weak.lock()) { 
        std::cout << "Data is on live. Link counter - " << nw.use_count() << std::endl;
    }
    
    std::cout << "After weak.lock() count - " << shared.use_count() << std::endl;
    
    // в случае, если количество ссылок == 0, будет выведена строчка
    if (weak.expired()) { 
        std::cout << "Data demolished" << std::endl;
    }
    
    return 0;
}
