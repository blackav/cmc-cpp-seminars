#include <iostream>
#include <list>

using namespace std;

class Parser
{
    static list<char> result; // результат
    // перевода исходной цепочки
    static char c; // текущий символ(лексема)
    static void gc() { cin >> c; }
    class S
    {
      public:
        S()
        {
            if (c == 'a') {
                gc();
                A();
                if (c == 'b') {
                    gc();
                    B();
                } else {
                    throw c;
                }
            } else {
                throw c;
            }
        }
        ~S() { result.push_front('S'); }
    };

    class A
    {
      public:
        A()
        {
            if (c == 'a') {
                gc();
                A();
            }
        }
        ~A() { result.push_front('A'); }
    };

    class B
    {
      public:
        B()
        {
            if (c == 'b') {
                gc();
            } else {
                throw c;
            }
        }
        ~B() { result.push_front('B'); }
    };

  public:
    void analyze()
    {
        try {
            result.clear();
            gc();
            S();
            if (c != '#') {
                throw c;
            }
            cout << "Результат перевода для входной цепочки: ";
	    for (auto c : result) {
                cout << c;
	    }
            cout << endl;
        } catch (char _) {
            cout << "Ошибочный символ - " << c << endl;
	}
    }
}; // end of Parser

char Parser::c;
list<char> Parser::result;

int main()
{
	Parser().analyze();
}
