# Design Patterns Project

This project contains examples of various common design patterns. Each design pattern is implemented in a separate file and includes a simple `main` function to demonstrate its usage.
The best way to learn it is to read the code and run the examples in your local environment.

## Table of Contents

- [Behavioral Patterns](#behavioral-patterns)
  - [Iterator Pattern](#iterator-pattern)
  - [Template Method Pattern](#template-method-pattern)
  - [Memento Pattern](#memento-pattern)
  - [State Pattern](#state-pattern)
  - [Visitor Pattern](#visitor-pattern)
  - [Command Pattern](#command-pattern)
- [Structural Patterns](#structural-patterns)
  - [Proxy Pattern](#proxy-pattern)
  - [Bridge Pattern](#bridge-pattern)
  - [Facade Pattern](#facade-pattern)
  - [Adapter Pattern](#adapter-pattern)
  - [Decorator Pattern](#decorator-pattern)
- [Creational Patterns](#creational-patterns)
  - [Builder Pattern](#builder-pattern)
  - [Prototype Pattern](#prototype-pattern)
  - [Factory Method Pattern](#factory-method-pattern)
  - [Singleton Pattern](#singleton-pattern)
  - [Abstract Factory Pattern](#abstract-factory-pattern)

## Behavioral Patterns

### Iterator Pattern

The Iterator Pattern provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

### Template Method Pattern

The Template Method Pattern defines the skeleton of an algorithm in an operation, deferring some steps to subclasses. Template Method lets subclasses redefine certain steps of an algorithm without changing the algorithm's structure.

### Memento Pattern

The Memento Pattern captures and externalizes an object's internal state so that the object can be restored to this state later, without violating encapsulation.

### State Pattern

The State Pattern allows an object to alter its behavior when its internal state changes. The object will appear to change its class.

### Visitor Pattern

The Visitor Pattern represents an operation to be performed on the elements of an object structure. It lets you define a new operation without changing the classes of the elements on which it operates.

### Command Pattern

The Command Pattern encapsulates a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations.

## Structural Patterns

### Proxy Pattern

The Proxy Pattern provides a surrogate or placeholder for another object to control access to it.

### Bridge Pattern

The Bridge Pattern decouples an abstraction from its implementation so that the two can vary independently.

### Facade Pattern

The Facade Pattern provides a unified interface to a set of interfaces in a subsystem, making the subsystem easier to use.

### Adapter Pattern

The Adapter Pattern converts the interface of a class into another interface that clients expect, allowing classes to work together that couldn't otherwise because of incompatible interfaces.

### Decorator Pattern

The Decorator Pattern attaches additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

## Creational Patterns

### Builder Pattern

The Builder Pattern separates the construction of a complex object from its representation, allowing the same construction process to create different representations.

### Prototype Pattern

The Prototype Pattern is used to create a duplicate object or clone of the current object to enhance performance. This pattern is used when the cost of creating an object is expensive or complicated.

### Factory Method Pattern

The Factory Method Pattern defines an interface for creating an object, but lets subclasses alter the type of objects that will be created.

### Singleton Pattern

The Singleton Pattern ensures a class has only one instance and provides a global point of access to it.

### Abstract Factory Pattern

The Abstract Factory Pattern provides an interface for creating families of related or dependent objects without specifying their concrete classes.

## Running the Examples

There is a Makefile in root directory of the project.You can run

```bash
make
```

to compile all the examples. Then you can run each example.

## Contribution

Issues and PRs are welcome.

Feel free to submit a Pull Request to improve this project. If you have any questions or suggestions, please open an Issue.
