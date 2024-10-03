#include <iostream>
#include <memory>

// component interface
class Component
{
public:
    virtual void operation() = 0;
};

//concrete component
class ConcreteComponent : public Component
{
public:
    void operation() override
    {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// decorator
class Decorator : public Component
{
protected:
    std::unique_ptr<Component> component;

public:
    Decorator(std::unique_ptr<Component> comp) : component(std::move(comp)) {}
    void operation() override
    {
        component->operation();
    }
};

// concrete decorator A
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(std::unique_ptr<Component> comp) : Decorator(std::move(comp)) {}
    void operation() override
    {
        Decorator::operation();
        addedBehavior();
    }
    void addedBehavior()
    {
        std::cout << "ConcreteDecoratorA added behavior" << std::endl;
    }
};

// concrete decorator B
class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(std::unique_ptr<Component> comp) : Decorator(std::move(comp)) {}
    void operation() override
    {
        Decorator::operation();
        addedBehavior();
    }
    void addedBehavior()
    {
        std::cout << "ConcreteDecoratorB added behavior" << std::endl;
    }
};

int main()
{
    std::unique_ptr<Component> component = std::make_unique<ConcreteComponent>();
    std::unique_ptr<Component> decoratorA = std::make_unique<ConcreteDecoratorA>(std::move(component));
    std::unique_ptr<Component> decoratorB = std::make_unique<ConcreteDecoratorB>(std::move(decoratorA));
    decoratorB->operation();

    return 0;
}
