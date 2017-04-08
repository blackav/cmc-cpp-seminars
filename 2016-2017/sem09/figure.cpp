#include <iostream>

class Figure
{
public:
    enum class Type { RECTANGLE, CIRCLE };
protected:
    Type type;
protected:
    Figure(Type type) : type(type) {}
public:
    virtual double area() const = 0;
    virtual ~Figure() {};
    virtual bool equals(const Figure *other) const = 0;
};

class Rectangle : public Figure
{
    double x = 0, y = 0;
public:
    Rectangle(double x = 0.0, double y = 0.0) : Figure(Type::RECTANGLE), x(x), y(y) {}
    double area() const override { return x * y; }
    bool equals(const Figure *other) const override
    {
/*
        if (const Rectangle *pr = dynamic_cast<const Rectangle*>(other)) {
            return x == pr->x && y == pr->y;
        } else {
            return false;
        }
*/
        if (type == Type::RECTANGLE) {
            const Rectangle *pr = static_cast<const Rectangle*>(other);
            return x == pr->x && y == pr->y;
        } else {
            return false;
        }
    }
};
