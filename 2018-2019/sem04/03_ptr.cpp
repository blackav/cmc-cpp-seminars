class Proxy
{
    struct Holder
    {
        int value;
    };

    Holder *data{};

public:
    const Holder *operator -> () const
    {
        return data;
    }
};

#include <iostream>

int main()
{
    Proxy p{};

    std::cout << p->value << std::endl;
}
