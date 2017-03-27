#include <iostream>
#include <stdexcept>
#include <unistd.h>

struct MyException : public std::exception
{
    int data[1024 * 1024 * 2]; 
    MyException()
    {
        std::cout << "MyException(default)" << std::endl;
    }
    MyException(const MyException &other)
        : std::exception(other)
    {
        std::cout << "MyException(copy constr)" << std::endl;
    }
    ~MyException()
    {
        std::cout << "~MyException" << std::endl;
    }
};

struct MyException2 : public MyException
{
    MyException2()
    {
        std::cout << "MyException2(default)" << std::endl;
    }
    MyException2(const MyException2 &other)
        : MyException(other)
    {
        std::cout << "MyException2(copy constr)" << std::endl;
    }
    ~MyException2()
    {
        std::cout << "~MyException2" << std::endl;
    }
};

struct Holder
{
    int x = 0;
    Holder(int x) : x(x) {}
    ~Holder() 
    {
         std::cout << ":" << x << std::endl;
    }
};

int dowork(int x)
{
    Holder h(x * 2);
    if (x < 0) throw MyException2();
    return (x+2) * dowork(x - 3);
}

int main() try 
{
    int x;
    std::cin >> x;
    try {
        std::cout << dowork(x) << std::endl;
    } catch (const MyException e) {
        std::cout << "catch:" << __LINE__ << std::endl;
        throw;
    } catch (char a) {
        std::cout << "char: " << __LINE__ << std::endl;
    }
} catch (...) {
    std::cerr << "Too bad" << std::endl;
    //abort();
    //exit(133);
}


