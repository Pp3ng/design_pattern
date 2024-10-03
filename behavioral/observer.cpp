#include <iostream>
#include <vector>
#include <memory>

// interface of observer
class Observer
{
public:
    virtual void update(const std::string &message) = 0;
};

// concrete observer
class ConcreteObserver : public Observer
{
private:
    std::string name;

public:
    ConcreteObserver(const std::string &n) : name(n) {}
    void update(const std::string &message) override
    {
        std::cout << name << " received: " << message << std::endl;
    }
};

// subject class
class Subject
{
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addObserver(std::shared_ptr<Observer> observer)
    {
        observers.push_back(observer);
    }

    void notifyObservers(const std::string &message)
    {
        for (const auto &observer : observers)
        {
            observer->update(message);
        }
    }
};

int main()
{
    std::shared_ptr<Subject> subject = std::make_shared<Subject>();

    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("Observer1");
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("Observer2");

    subject->addObserver(observer1);
    subject->addObserver(observer2);

    subject->notifyObservers("Hello Observers!");

    return 0;
}
