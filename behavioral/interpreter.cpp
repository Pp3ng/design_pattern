#include <iostream>
#include <string>
#include <unordered_map>

// interface of expression
class Expression
{
public:
    virtual int interpret(const std::unordered_map<std::string, int> &context) = 0;
    virtual ~Expression() = default; // Add virtual destructor
};

// variable expression
class VariableExpression : public Expression
{
private:
    std::string name;

public:
    VariableExpression(const std::string &n) : name(n) {}
    int interpret(const std::unordered_map<std::string, int> &context) override
    {
        return context.at(name);
    }
};

// add expression
class AddExpression : public Expression
{
private:
    Expression *left;
    Expression *right;

public:
    AddExpression(Expression *l, Expression *r) : left(l), right(r) {}
    int interpret(const std::unordered_map<std::string, int> &context) override
    {
        return left->interpret(context) + right->interpret(context);
    }
};

int main()
{
    std::unordered_map<std::string, int> context = {{"x", 5}, {"y", 10}};

    Expression *x = new VariableExpression("x");
    Expression *y = new VariableExpression("y");
    Expression *add = new AddExpression(x, y);

    std::cout << "Result: " << add->interpret(context) << std::endl;

    delete x;
    delete y;
    delete add;

    return 0;
}
