#include <iostream>
#include <memory>
#include <fstream>

class File {
    std::unique_ptr<std::fstream> file;
public:
    // конструктор класса
    File(const std::string& filename) {
        // кладем в поле указатель на объекта типа fstream с открытием на запись
        file = std::make_unique<std::fstream>(filename, std::ios::out);
        
        // обработчик на случай ошибки открытия файла
        if (!file->is_open()) throw std::runtime_error("Can't open the file");
    }
    // деструктор класса (закрывает при вызоыве)
    ~File() { if (file) file->close(); }

    // функция записи чего-то в файл
    void write_in_file(const std::string& data) { *file << data; }
};

int main() {
    for (int i = 0; i < 100; i++) {
        std::unique_ptr<int> a = std::make_unique<int>(52); // автоматически удаляет 
    }

    File new_file("abcd.txt");
    new_file.write_in_file('I wanna get back to python :/')

    return 0;
}