#include <iostream>
#include <memory>

// prototype interface
class Prototype
{
public:
    virtual std::unique_ptr<Prototype> clone() const = 0;
    virtual void use() const = 0;
};

// concrete prototype 1
class ConcretePrototype1 : public Prototype
{
public:
    std::unique_ptr<Prototype> clone() const override
    {
        return std::make_unique<ConcretePrototype1>(*this);
    }
    void use() const override
    {
        std::cout << "Using ConcretePrototype1" << std::endl;
    }
};

// concrete prototype 2
class ConcretePrototype2 : public Prototype
{
public:
    std::unique_ptr<Prototype> clone() const override
    {
        return std::make_unique<ConcretePrototype2>(*this);
    }
    void use() const override
    {
        std::cout << "Using ConcretePrototype2" << std::endl;
    }
};

int main()
{
    std::unique_ptr<Prototype> prototype1 = std::make_unique<ConcretePrototype1>();
    std::unique_ptr<Prototype> clone1 = prototype1->clone();
    clone1->use();

    std::unique_ptr<Prototype> prototype2 = std::make_unique<ConcretePrototype2>();
    std::unique_ptr<Prototype> clone2 = prototype2->clone();
    clone2->use();

    return 0;
}
