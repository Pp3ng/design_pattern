#include <iostream>
#include <memory>

// define the handler interface
class Handler
{
public:
    virtual void setNext(std::shared_ptr<Handler> nextHandler) = 0;
    virtual void handleRequest(int request) = 0;
};

// concrete handler A
class ConcreteHandlerA : public Handler
{
private:
    std::shared_ptr<Handler> next;

public:
    void setNext(std::shared_ptr<Handler> nextHandler) override
    {
        next = nextHandler;
    }

    void handleRequest(int request) override
    {
        if (request < 10)
        {
            std::cout << "ConcreteHandlerA handled request " << request << std::endl;
        }
        else if (next)
        {
            next->handleRequest(request);
        }
    }
};

// concrete handler B
class ConcreteHandlerB : public Handler
{
private:
    std::shared_ptr<Handler> next;

public:
    void setNext(std::shared_ptr<Handler> nextHandler) override
    {
        next = nextHandler;
    }

    void handleRequest(int request) override
    {
        if (request >= 10)
        {
            std::cout << "ConcreteHandlerB handled request " << request << std::endl;
        }
        else if (next)
        {
            next->handleRequest(request);
        }
    }
};

int main()
{
    std::shared_ptr<Handler> handlerA = std::make_shared<ConcreteHandlerA>();
    std::shared_ptr<Handler> handlerB = std::make_shared<ConcreteHandlerB>();
    handlerA->setNext(handlerB);

    handlerA->handleRequest(5);
    handlerA->handleRequest(15);

    return 0;
}
