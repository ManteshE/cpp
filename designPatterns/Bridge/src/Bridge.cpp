//============================================================================
// Name        : Bridge.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
using namespace std;

// Implementor
class IDrawingImpl {
public:
    virtual void drawSquare(double) = 0;

    virtual ~IDrawingImpl() {
    }
};

// DrawingImplA
class DrawingImplA: public IDrawingImpl {
public:
	DrawingImplA() {
    }

    virtual ~DrawingImplA() {
    }

    void drawSquare(double side) {
        cout << "Called from DrawingImplA. square with side = "<< side << endl;
    }
};

// DrawingImplB
class DrawingImplB: public IDrawingImpl {
public:
	DrawingImplB() {
    }

    virtual ~DrawingImplB() {
    }

    void drawSquare(double side) {
        cout << "Called from DrawingImplB. square with side = "<< side << endl;
    }
};

// Abstraction
class Shape {
public:
    virtual void draw()= 0; // low-level
    virtual ~Shape() {
    }
};

// Refined Abstraction
class Square: public Shape {
public:
    Square(double s, IDrawingImpl& Implementor) :
		side(s), drawingImpl(Implementor) {
    }

    virtual ~Square() {
    }

    void draw() {
        drawingImpl.drawSquare(side);
    }
private:
    double side;
    IDrawingImpl& drawingImpl;
};

int main(int argc, char* argv[]) {
	DrawingImplA ImplementorA;
	DrawingImplB ImplementorB;

    Square sqA(1, ImplementorA);
    Square sqB(2, ImplementorB);

    Shape* shapes[2];
    shapes[0] = &sqA;
    shapes[1] = &sqB;

    for(int num = 0; num <2; num++) {
    	shapes[num]->draw();
    }
    return 0;
}
