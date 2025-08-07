#include <iostream>
#include <memory>

using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    Singleton() = default;

public:
    Singleton(const Singleton &obj) = delete;
    Singleton &operator=(const Singleton &obj) = delete;

    static Singleton *getInstance()
    {
        if (instance == nullptr)
            instance = new Singleton();

        return instance;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton *obj = Singleton::getInstance();
    if (obj == nullptr)
    {
        std::cout << "could not create obj\n";
        return 0;
    }

    std::cout << "Object created at " << &obj << std::endl;

    Singleton *obj2 = Singleton::getInstance();
    std::cout << &obj2 << std::endl;

    obj2 = obj;

    return 0;
}