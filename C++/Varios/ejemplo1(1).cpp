#include <cstring>
#include <fstream>
#include <iostream>

class info
{
private:
    char name[15];
    char surname[15];
    int age;

public:
    info()
    {
    }

    void input()
    {
        std::cout << "Your name:" << std::endl;
        std::cin.getline(name, 15);

        std::cout << "Your surname:" << std::endl;
        std::cin.getline(surname, 15);

        std::cout << "Your age:" << std::endl;
        std::cin >> age;

        to_file();
    }

    void to_file()
    {
        std::ofstream fs("example.bin", std::ios::out | std::ios::binary | std::ios::app);
        fs.write(name, sizeof name);
        fs.write(surname, sizeof surname);
        fs.write(reinterpret_cast<const char*>(&age), sizeof age);
        fs.close();
    }
};

int main()
{
    info ob;
    ob.input();
}
