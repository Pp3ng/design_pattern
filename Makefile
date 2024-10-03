# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++14 -Wall
# Source files
SOURCES = \
    behavioral/chain_of_responsibility.cpp \
    behavioral/command.cpp \
    behavioral/interpreter.cpp \
    behavioral/iterator.cpp \
    behavioral/mediator.cpp \
    behavioral/memento.cpp \
    behavioral/observer.cpp \
    behavioral/state.cpp \
    behavioral/strategy.cpp \
    behavioral/template_method.cpp \
    behavioral/visitor.cpp \
    creational/abstract_factory.cpp \
    creational/builder.cpp \
    creational/factory_method.cpp \
    creational/prototype.cpp \
    creational/singleton.cpp \
    structural/adapter.cpp \
    structural/bridge.cpp \
    structural/composite.cpp \
    structural/decorator.cpp \
    structural/facade.cpp \
    structural/flyweight.cpp \
    structural/proxy.cpp

# Executable files
EXECUTABLES = $(SOURCES:.cpp=)

# Default target
all: $(EXECUTABLES)

# Pattern rule to build each executable
%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Clean target
clean:
	rm -f $(EXECUTABLES)