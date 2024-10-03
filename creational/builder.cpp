#include <iostream>
#include <memory>

// product
class Product
{
public:
    void setPartA(const std::string &part) { partA = part; }
    void setPartB(const std::string &part) { partB = part; }
    void setPartC(const std::string &part) { partC = part; }
    void show()
    {
        std::cout << "Product Parts: " << partA << ", " << partB << ", " << partC << std::endl;
    }

private:
    std::string partA;
    std::string partB;
    std::string partC;
};

// adstract builder
class Builder
{
public:
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;
    virtual std::unique_ptr<Product> getResult() = 0;
};

// concrete builder
class ConcreteBuilder : public Builder
{
public:
    ConcreteBuilder() { product = std::make_unique<Product>(); }
    void buildPartA() override { product->setPartA("PartA"); }
    void buildPartB() override { product->setPartB("PartB"); }
    void buildPartC() override { product->setPartC("PartC"); }
    std::unique_ptr<Product> getResult() override { return std::move(product); }

private:
    std::unique_ptr<Product> product;
};

// director
class Director
{
public:
    void setBuilder(Builder *b) { builder = b; }
    void construct()
    {
        builder->buildPartA();
        builder->buildPartB();
        builder->buildPartC();
    }

private:
    Builder *builder;
};

int main()
{
    Director director;
    ConcreteBuilder builder;
    director.setBuilder(&builder);
    director.construct();
    std::unique_ptr<Product> product = builder.getResult();
    product->show();
    return 0;
}
