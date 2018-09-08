Design Patterns 

1. Creational patterns - It more concentrate on class installation and object creation
	1. Abstract Factory Design Pattern - The purpose of the Abstract Factory is to provide an interface for creating families of related objects, without specifying concrete classes
	2. Builder - Separates object construction of a complex object from its representation so that the same construction process can create different representation. 
	3. Factory Method - In Factory pattern, we create object without exposing the creation logic to client and the client use the same common interface to create new type of object
	4. Object Pool
	5. Prototype
	6. Singleton - Ensure a class has only one instance

2. Structural patterns - open for expention close for modification
	1. Adapter Design Pattern - Convert the interface of a class into another interface that clients expect.
	2. Bridge design pattern
		The bridge pattern allows the Abstraction and the Implementation to be developed independently and the client code can access only the Abstraction part without being 			concerned about the Implementation part.
	3. Composite Design Pattern
		1. Compose objects into tree structures to represent whole-part hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.
	4. Decorator Design Pattern
		1. Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.
		2. Problem - You want to add behavior or state to individual objects at run-time. Inheritance is not feasible because it is static and applies to an entire class.
	5. Facade Design Pattern
		1. Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.
		2. Problem - A segment of the client community needs a simplified interface to the overall functionality of a complex subsystem.
	6. Flyweight Design Pattern
		1. Flyweight describes how to share objects, so that their use at fine granularity is not cost prohibitive.
	7. Proxy Design Pattern
		1. Provide a surrogate or placeholder for another object to control access to it.

3. Behavioral patterns
	1. Chain of responsibility
	2. Command - Encapsulates a request as an object, thereby letting us parameterize other objects with different requests, queue or log requests, and support undoable operations.
	3. Interpreter
	4. Iterator - Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
	5. Mediator
	6. Memento
	7. Null Object
	8. Observer - Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.
	9. State
	10. Strategy - The strategy pattern is intended to provide a means to define a family of algorithms, encapsulate each one as an object, and make them interchangeable.
	11. Template method
	12. Visitor
