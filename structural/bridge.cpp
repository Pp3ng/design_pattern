#include <iostream>

// implementor
class Implementor
{
public:
    virtual void operationImpl() = 0;
    virtual ~Implementor() {}
};

// concrete implementor A
class ConcreteImplementorA : public Implementor
{
public:
    void operationImpl() override
    {
        std::cout << "ConcreteImplementorA operation" << std::endl;
    }
};

// concrete implementor B
class ConcreteImplementorB : public Implementor
{
public:
    void operationImpl() override
    {
        std::cout << "ConcreteImplementorB operation" << std::endl;
    }
};

// abstraction
class Abstraction
{
protected:
    Implementor *implementor;

public:
    Abstraction(Implementor *impl) : implementor(impl) {}
    virtual void operation()
    {
        implementor->operationImpl();
    }
    virtual ~Abstraction() {}
};

// refined abstraction
class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor *impl) : Abstraction(impl) {}
    void operation() override
    {
        implementor->operationImpl();
    }
};

int main()
{
    Implementor *implA = new ConcreteImplementorA();
    Abstraction *abstractionA = new RefinedAbstraction(implA);
    abstractionA->operation();

    Implementor *implB = new ConcreteImplementorB();
    Abstraction *abstractionB = new RefinedAbstraction(implB);
    abstractionB->operation();

    delete implA;
    delete abstractionA;
    delete implB;
    delete abstractionB;

    return 0;
}
