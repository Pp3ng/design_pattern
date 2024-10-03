#include <iostream>
#include <memory>

// strategy interface
class Strategy
{
public:
    virtual void execute() = 0;
};

//concrete strategy A
class ConcreteStrategyA : public Strategy
{
public:
    void execute() override
    {
        std::cout << "Executing strategy A" << std::endl;
    }
};

//concrete strategy B
class ConcreteStrategyB : public Strategy
{
public:
    void execute() override
    {
        std::cout << "Executing strategy B" << std::endl;
    }
};

//context class
class Context
{
private:
    std::unique_ptr<Strategy> strategy;

public:
    void setStrategy(std::unique_ptr<Strategy> s)
    {
        strategy = std::move(s);
    }

    void executeStrategy()
    {
        if (strategy)
        {
            strategy->execute();
        }
    }
};

int main()
{
    Context context;

    context.setStrategy(std::make_unique<ConcreteStrategyA>());
    context.executeStrategy();

    context.setStrategy(std::make_unique<ConcreteStrategyB>());
    context.executeStrategy();

    return 0;
}
