#include <iostream>
#include <memory>

// interface of state
class State
{
public:
    virtual void handle() = 0;
};

// concrete state A
class ConcreteStateA : public State
{
public:
    void handle() override
    {
        std::cout << "Handling state A" << std::endl;
    }
};

// concrete state B
class ConcreteStateB : public State
{
public:
    void handle() override
    {
        std::cout << "Handling state B" << std::endl;
    }
};

// context class
class Context
{
private:
    std::unique_ptr<State> state;

public:
    void setState(std::unique_ptr<State> s)
    {
        state = std::move(s);
    }

    void request()
    {
        if (state)
        {
            state->handle();
        }
    }
};

int main()
{
    Context context;

    context.setState(std::make_unique<ConcreteStateA>());
    context.request();

    context.setState(std::make_unique<ConcreteStateB>());
    context.request();

    return 0;
}
