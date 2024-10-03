#include <iostream>
#include <unordered_map>
#include <memory>

// flyweight interface
class Flyweight
{
public:
    virtual void operation(const std::string &extrinsicState) = 0;
};

// concrete flyweight
class ConcreteFlyweight : public Flyweight
{
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string &state) : intrinsicState(state) {}
    void operation(const std::string &extrinsicState) override
    {
        std::cout << "ConcreteFlyweight: IntrinsicState = " << intrinsicState
                  << ", ExtrinsicState = " << extrinsicState << std::endl;
    }
};

// flyweight factory
class FlyweightFactory
{
private:
    std::unordered_map<std::string, std::shared_ptr<Flyweight>> flyweights;

public:
    std::shared_ptr<Flyweight> getFlyweight(const std::string &key)
    {
        if (flyweights.find(key) == flyweights.end())
        {
            flyweights[key] = std::make_shared<ConcreteFlyweight>(key);
        }
        return flyweights[key];
    }
};

int main()
{
    FlyweightFactory factory;
    std::shared_ptr<Flyweight> flyweight1 = factory.getFlyweight("state1");
    flyweight1->operation("extrinsic1");

    std::shared_ptr<Flyweight> flyweight2 = factory.getFlyweight("state2");
    flyweight2->operation("extrinsic2");

    std::shared_ptr<Flyweight> flyweight3 = factory.getFlyweight("state1");
    flyweight3->operation("extrinsic3");

    return 0;
}
