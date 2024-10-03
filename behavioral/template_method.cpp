#include <iostream>

// abstract class
class AbstractClass
{
public:
    void templateMethod()
    {
        primitiveOperation1();
        primitiveOperation2();
    }

    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
};

// concrete class A
class ConcreteClassA : public AbstractClass
{
public:
    void primitiveOperation1() override
    {
        std::cout << "ConcreteClassA Operation1" << std::endl;
    }

    void primitiveOperation2() override
    {
        std::cout << "ConcreteClassA Operation2" << std::endl;
    }
};

// concrete class B
class ConcreteClassB : public AbstractClass
{
public:
    void primitiveOperation1() override
    {
        std::cout << "ConcreteClassB Operation1" << std::endl;
    }

    void primitiveOperation2() override
    {
        std::cout << "ConcreteClassB Operation2" << std::endl;
    }
};

int main()
{
    ConcreteClassA classA;
    classA.templateMethod();

    ConcreteClassB classB;
    classB.templateMethod();

    return 0;
}
