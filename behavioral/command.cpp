#include <iostream>
#include <vector>
#include <memory>

// command interface
class Command
{
public:
    virtual void execute() = 0;
};

// concrete command
class ConcreteCommand : public Command
{
private:
    std::string payload;

public:
    ConcreteCommand(const std::string &p) : payload(p) {}
    void execute() override
    {
        std::cout << "Executing command with payload: " << payload << std::endl;
    }
};

// invoker
class Invoker
{
private:
    std::vector<std::shared_ptr<Command>> commands;

public:
    void addCommand(std::shared_ptr<Command> command)
    {
        commands.push_back(command);
    }

    void executeCommands()
    {
        for (const auto &command : commands)
        {
            command->execute();
        }
    }
};

int main()
{
    std::shared_ptr<Command> command1 = std::make_shared<ConcreteCommand>("Payload1");
    std::shared_ptr<Command> command2 = std::make_shared<ConcreteCommand>("Payload2");

    Invoker invoker;
    invoker.addCommand(command1);
    invoker.addCommand(command2);

    invoker.executeCommands();

    return 0;
}
