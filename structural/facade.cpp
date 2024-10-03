#include <iostream>

// subsystem A
class SubsystemA
{
public:
    void operationA()
    {
        std::cout << "SubsystemA operation" << std::endl;
    }
};

// subsystem B
class SubsystemB
{
public:
    void operationB()
    {
        std::cout << "SubsystemB operation" << std::endl;
    }
};

// subsystem C
class SubsystemC
{
public:
    void operationC()
    {
        std::cout << "SubsystemC operation" << std::endl;
    }
};

// facade class
class Facade
{
private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
    SubsystemC subsystemC;

public:
    void operation()
    {
        subsystemA.operationA();
        subsystemB.operationB();
        subsystemC.operationC();
    }
};

int main()
{
    Facade facade;
    facade.operation();
    return 0;
}