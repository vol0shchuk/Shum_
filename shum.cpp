/*
//завдання 1

#include <iostream>
#include <cmath>
using namespace std;

class Equation {
public:
    virtual void solve() const = 0;
};

class LinearEquation : public Equation {
private:
    double a;
    double b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void solve() const override {
        if (a == 0) {
            if (b == 0) {
                cout << "Рiвняння має безлiч розв'язкiв" << endl;
            }
            else {
                cout << "Рiвняння не має розв'язкiв" << endl;
            }
        }
        else {
            double x = -b / a;
            cout << "Розв'язок лiнiйного рiвняння: x = " << x << endl;
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() const override {
        if (a == 0) {
            LinearEquation linear(b, c);
            linear.solve();
            return;
        }

        double discriminant = b * b - 4 * a * c;
        if (discriminant > 0) {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Розв'язки квадратного рiвняння: x1 = " << x1 << ", x2 = " << x2 << endl;
        }
        else if (discriminant == 0) {
            double x = -b / (2 * a);
            cout << "Розв'язок квадратного рiвняння (дискримінант = 0): x = " << x << endl;
        }
        else {
            cout << "Квадратне рiвняння не має розв'язкiв" << endl;
        }
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    Equation* equation1 = new LinearEquation(16, 41);
    equation1->solve();
    delete equation1;

    Equation* equation2 = new QuadraticEquation(15, -3, 12);
    equation2->solve();
    delete equation2;
}*/


/*

//Завдання 2

#include <iostream>
#include <fstream>

using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
};

class Square : public Shape {
private:
    int x;
    int y;
    int side;

public:
    Square(int x, int y, int side) : x(x), y(y), side(side) {}

    void Show() const override {
        cout << "Square: Top-left corner (" << x << ", " << y << "), Side: " << side << endl;
    }

    void Save(ofstream& file) const override {
        file << "Square " << x << " " << y << " " << side << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    int x;
    int y;
    int width;
    int height;

public:
    Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}

    void Show() const override {
        cout << "Rectangle: Top-left corner (" << x << ", " << y << "), Width: " << width << ", Height: " << height << endl;
    }

    void Save(ofstream& file) const override {
        file << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    int centerX;
    int centerY;
    int radius;

public:
    Circle(int centerX, int centerY, int radius) : centerX(centerX), centerY(centerY), radius(radius) {}

    void Show() const override {
        cout << "Circle: Center (" << centerX << ", " << centerY << "), Radius: " << radius << endl;
    }

    void Save(ofstream& file) const override {
        file << "Circle " << centerX << " " << centerY << " " << radius << endl;
    }

    void Load(ifstream& file) override {
        file >> centerX >> centerY >> radius;
    }
};

class Ellipse : public Shape {
private:
    int x;
    int y;
    int majorAxis;
    int minorAxis;

public:
    Ellipse(int x, int y, int majorAxis, int minorAxis) : x(x), y(y), majorAxis(majorAxis), minorAxis(minorAxis) {}

    void Show() const override {
        cout << "Ellipse: Top-left corner (" << x << ", " << y << "), Major Axis: " << majorAxis << ", Minor Axis: " << minorAxis << endl;
    }

    void Save(ofstream& file) const override {
        file << "Ellipse " << x << " " << y << " " << majorAxis << " " << minorAxis << endl;
    }

    void Load(ifstream& file) override {
        file >> x >> y >> majorAxis >> minorAxis;
    }
};

int main() {
    Shape* shapes[] = {
        new Square(7, 5, 12),
        new Rectangle(5, 5, 5, 5),
        new Circle(12, 16, 24),
        new Ellipse(5, 15, 11, 10)
    };

    ofstream outFile("shapes.txt");
    if (outFile.is_open()) {
        for (const auto& shape : shapes) {
            shape->Save(outFile);
        }
        outFile.close();
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }

    ifstream inFile("shapes.txt");
    if (inFile.is_open()) {
        string shapeType;
        for (auto& shape : shapes) {
            shape->Load(inFile);
            shape->Show();
        }
        inFile.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }

    for (const auto& shape : shapes) {
        delete shape;
    }
}*/