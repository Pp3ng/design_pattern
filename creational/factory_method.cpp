#include <iostream>
#include <memory>

// product interface
class Product
{
public:
    virtual void use() = 0;
};

// concrete product A
class ConcreteProductA : public Product
{
public:
    void use() override
    {
        std::cout << "Using Product A" << std::endl;
    }
};

// concrete product B
class ConcreteProductB : public Product
{
public:
    void use() override
    {
        std::cout << "Using Product B" << std::endl;
    }
};

// factory interface
class Factory
{
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
};

// concrete factory A
class ConcreteFactoryA : public Factory
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<ConcreteProductA>();
    }
};

// concrete factory B
class ConcreteFactoryB : public Factory
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<ConcreteProductB>();
    }
};

int main()
{
    std::unique_ptr<Factory> factoryA = std::make_unique<ConcreteFactoryA>();
    std::unique_ptr<Product> productA = factoryA->createProduct();
    productA->use();

    std::unique_ptr<Factory> factoryB = std::make_unique<ConcreteFactoryB>();
    std::unique_ptr<Product> productB = factoryB->createProduct();
    productB->use();

    return 0;
}
