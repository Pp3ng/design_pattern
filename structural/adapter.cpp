#include <iostream>

// class being adapted
class Target
{
public:
    virtual void request() const
    {
        std::cout << "Target: The default target's behavior." << std::endl;
    }

    virtual ~Target() {}
};

// class needing adaptation
class Adaptee
{
public:
    void specificRequest() const
    {
        std::cout << "Adaptee: Specific request." << std::endl;
    }
};

// adapter class
class Adapter : public Target
{
private:
    Adaptee adaptee;

public:
    void request() const override
    {
        adaptee.specificRequest();
    }

    virtual ~Adapter() {}
};

int main()
{
    std::cout << "Client: I can work just fine with the Target objects:" << std::endl;
    Target *target = new Target();
    target->request();

    std::cout << "\nClient: The Adaptee class has a weird interface. See, I don't understand it:" << std::endl;
    Adaptee *adaptee = new Adaptee();
    adaptee->specificRequest();

    std::cout << "\nClient: But I can work with it via the Adapter:" << std::endl;
    Adapter *adapter = new Adapter();
    adapter->request();

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}
