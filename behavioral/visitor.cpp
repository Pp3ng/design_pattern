#include <iostream>
#include <vector>
#include <memory>

// interface of visitor
class Visitor
{
public:
    virtual void visit(class ConcreteElementA *element) = 0;
    virtual void visit(class ConcreteElementB *element) = 0;
};

// element interface
class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;
};

// concrete element A
class ConcreteElementA : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visit(this);
    }
    void operationA()
    {
        std::cout << "ConcreteElementA operation" << std::endl;
    }
};

// concrete element B
class ConcreteElementB : public Element
{
public:
    void accept(Visitor *visitor) override
    {
        visitor->visit(this);
    }
    void operationB()
    {
        std::cout << "ConcreteElementB operation" << std::endl;
    }
};

// concrete visitor
class ConcreteVisitor : public Visitor
{
public:
    void visit(ConcreteElementA *element) override
    {
        element->operationA();
    }
    void visit(ConcreteElementB *element) override
    {
        element->operationB();
    }
};

int main()
{
    std::vector<std::unique_ptr<Element>> elements;
    elements.push_back(std::make_unique<ConcreteElementA>());
    elements.push_back(std::make_unique<ConcreteElementB>());

    ConcreteVisitor visitor;
    for (auto &element : elements)
    {
        element->accept(&visitor);
    }

    return 0;
}
