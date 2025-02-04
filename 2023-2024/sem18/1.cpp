#include <iostream>
#include <typeinfo>
using namespace std;

class Scanner
{
    class State
    {
    public:
	State()
	{
		++st_count;
	}
        virtual State *operator()(char c) const = 0;
	virtual ~State() = default;
	static int st_count;
    };

    class A : public State
    {
    public:
        State *operator()(char c) const override
        {
            if (c == 'b') {
                return new B;
            } else if (c == 'a') {
                return new A;
            } else {
                return new ERR;
            }
        }
    };
    class B : public State
    {
        State *operator()(char c) const override
	{
		if (c == 'a') {
			return new A;
		} else if (c == 'b') {
			return new B;
		} else {
			return new ERR;
		}
		return nullptr;
	}
    };
    class ERR : public State
    {
        State *
        operator()(char c) const
        {
            return new ERR;
        }
    };
    char c;
    State *temp, *next;

public:
    void analyze()
    {
        for (temp = new A, cin >> c; c != '#' && !(dynamic_cast<ERR *>(temp)); cin >> c) {
            next = (*temp)(c);
            delete temp;
            temp = next;
        }
        if (c != '#' || typeid(*temp) != typeid(B)) {
            cout << "ERROR" << endl;
        } else {
            cout << "OK =" << State::st_count << endl;
        }
        delete temp;
    }
};

int Scanner::State::st_count = 0;

int
main()
{
	Scanner().analyze();
}
