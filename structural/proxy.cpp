#include <iostream>
#include <memory>

// subject
class Subject
{
public:
    virtual void request() = 0;
};

// real subject
class RealSubject : public Subject
{
public:
    void request() override
    {
        std::cout << "RealSubject request" << std::endl;
    }
};

// proxy
class Proxy : public Subject
{
private:
    std::unique_ptr<RealSubject> realSubject;

public:
    void request() override
    {
        if (!realSubject)
        {
            realSubject = std::make_unique<RealSubject>();
        }
        realSubject->request();
    }
};

int main()
{
    std::unique_ptr<Subject> subject = std::make_unique<Proxy>();
    subject->request();
    return 0;
}
