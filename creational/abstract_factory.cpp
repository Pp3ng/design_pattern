#include <iostream>
#include <memory>

// product A
class AbstractProductA
{
public:
    virtual void use() = 0;
};

// product B
class AbstractProductB
{
public:
    virtual void eat() = 0;
};

// concrete product A1
class ConcreteProductA1 : public AbstractProductA
{
public:
    void use() override
    {
        std::cout << "Using Product A1" << std::endl;
    }
};

// concrete product A2
class ConcreteProductA2 : public AbstractProductA
{
public:
    void use() override
    {
        std::cout << "Using Product A2" << std::endl;
    }
};

// concrete product B1
class ConcreteProductB1 : public AbstractProductB
{
public:
    void eat() override
    {
        std::cout << "Eating Product B1" << std::endl;
    }
};

// concrete product B2
class ConcreteProductB2 : public AbstractProductB
{
public:
    void eat() override
    {
        std::cout << "Eating Product B2" << std::endl;
    }
};

// abstract factory
class AbstractFactory
{
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() = 0;
};

//concrete factory1
class ConcreteFactory1 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductA> createProductA() override
    {
        return std::make_unique<ConcreteProductA1>();
    }
    std::unique_ptr<AbstractProductB> createProductB() override
    {
        return std::make_unique<ConcreteProductB1>();
    }
};

//concrete factory2
class ConcreteFactory2 : public AbstractFactory
{
public:
    std::unique_ptr<AbstractProductA> createProductA() override
    {
        return std::make_unique<ConcreteProductA2>();
    }
    std::unique_ptr<AbstractProductB> createProductB() override
    {
        return std::make_unique<ConcreteProductB2>();
    }
};

int main()
{
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractProductA> productA1 = factory1->createProductA();
    std::unique_ptr<AbstractProductB> productB1 = factory1->createProductB();
    productA1->use();
    productB1->eat();

    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    std::unique_ptr<AbstractProductA> productA2 = factory2->createProductA();
    std::unique_ptr<AbstractProductB> productB2 = factory2->createProductB();
    productA2->use();
    productB2->eat();

    return 0;
}
