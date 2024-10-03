#include <iostream>

// Singleton class
class Singleton
{
public:
    // get instance
    static Singleton &getInstance()
    {
        static Singleton instance;
        return instance;
    }

    void showMessage()
    {
        std::cout << "Hello Singleton!" << std::endl;
    }

private:
    // forbid the constructor, copy constructor and assignment operator
    Singleton() {}
    // forbid the copy constructor and assignment operator
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

int main()
{
    Singleton &singleton = Singleton::getInstance();
    singleton.showMessage();
    return 0;
}
