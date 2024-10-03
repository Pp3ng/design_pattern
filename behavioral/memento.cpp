#include <iostream>
#include <string>
#include <vector>

// memento definition
class Memento
{
private:
    std::string state;

public:
    Memento(const std::string &s) : state(s) {}
    std::string getState() const
    {
        return state;
    }
};

// originator class
class Originator
{
private:
    std::string state;

public:
    void setState(const std::string &s)
    {
        state = s;
        std::cout << "State set to: " << state << std::endl;
    }

    Memento saveStateToMemento()
    {
        return Memento(state);
    }

    void getStateFromMemento(const Memento &memento)
    {
        state = memento.getState();
        std::cout << "State restored to: " << state << std::endl;
    }
};

// caretaker class
class Caretaker
{
private:
    std::vector<Memento> mementos;

public:
    void saveMemento(const Memento &m)
    {
        mementos.push_back(m);
    }

    Memento getMemento(int index) const
    {
        if (index < 0 || static_cast<size_t>(index) >= mementos.size())
        {
            throw std::out_of_range("Invalid memento index");
        }
        return mementos[index];
    }
};

int main()
{
    Originator originator;
    Caretaker caretaker;

    originator.setState("State1");
    caretaker.saveMemento(originator.saveStateToMemento());

    originator.setState("State2");
    caretaker.saveMemento(originator.saveStateToMemento());

    originator.setState("State3");
    originator.getStateFromMemento(caretaker.getMemento(0)); // restore to State1

    originator.getStateFromMemento(caretaker.getMemento(1)); // restore to State2

    return 0;
}
