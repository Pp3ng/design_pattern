#include <iostream>
#include <vector>
#include <memory>

// component
class Component
{
public:
    virtual void operation() = 0;
};

// leaf
class Leaf : public Component
{
public:
    void operation() override
    {
        std::cout << "Leaf operation" << std::endl;
    }
};

// composite node
class Composite : public Component
{
private:
    std::vector<std::unique_ptr<Component>> children;

public:
    void add(std::unique_ptr<Component> component)
    {
        children.push_back(std::move(component));
    }

    void operation() override
    {
        std::cout << "Composite operation" << std::endl;
        for (auto &child : children)
        {
            child->operation();
        }
    }
};

int main()
{
    std::unique_ptr<Composite> root = std::make_unique<Composite>();
    root->add(std::make_unique<Leaf>());
    root->add(std::make_unique<Leaf>());

    std::unique_ptr<Composite> subComposite = std::make_unique<Composite>();
    subComposite->add(std::make_unique<Leaf>());
    root->add(std::move(subComposite));

    root->operation();

    return 0;
}
