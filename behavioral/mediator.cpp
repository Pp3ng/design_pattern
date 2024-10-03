#include <iostream>
#include <string>
#include <vector>
#include <memory>

// interface of Mediator
class Mediator
{
public:
    virtual void sendMessage(const std::string &message, class Colleague *colleague) = 0;
};

// interface of Colleague
class Colleague
{
protected:
    Mediator *mediator;

public:
    Colleague(Mediator *m) : mediator(m) {}
    virtual void receiveMessage(const std::string &message) = 0;
};

// concrete colleague A
class ConcreteColleagueA : public Colleague
{
public:
    ConcreteColleagueA(Mediator *m) : Colleague(m) {}
    void receiveMessage(const std::string &message) override
    {
        std::cout << "ColleagueA received: " << message << std::endl;
    }
};

// concrete colleague B
class ConcreteColleagueB : public Colleague
{
public:
    ConcreteColleagueB(Mediator *m) : Colleague(m) {}
    void receiveMessage(const std::string &message) override
    {
        std::cout << "ColleagueB received: " << message << std::endl;
    }
};

// concrete mediator
class ConcreteMediator : public Mediator
{
private:
    std::vector<Colleague *> colleagues;

public:
    void addColleague(Colleague *colleague)
    {
        colleagues.push_back(colleague);
    }

    void sendMessage(const std::string &message, Colleague *sender) override
    {
        for (Colleague *colleague : colleagues)
        {
            if (colleague != sender)
            {
                colleague->receiveMessage(message);
            }
        }
    }
};

int main()
{
    ConcreteMediator mediator;
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);

    mediator.addColleague(&colleagueA);
    mediator.addColleague(&colleagueB);

    colleagueA.receiveMessage("Hello from A");
    colleagueB.receiveMessage("Hello from B");

    return 0;
}
