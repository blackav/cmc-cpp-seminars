#include <iostream>
#include <cctype>
#include <string>

using namespace std;

enum class Token
{
    EEOF,
    NUM,
    ID,
    LBR,  // (
    RBR,  // )
    PLUS, // +
    MINUS, // -
    MUL,   // *
    DIV    // /
};

class Scanner
{
    istream &in;
    string value;

public:
    Scanner(istream &in) : in(in) {}
    Token get()
    {
        if (!in) return Token::EEOF;
        char c;
        if (!in.get(c)) return Token::EEOF;
        while (isspace(c))
            if (!in.get(c)) return Token::EEOF;
        if (c == '+') {
            return Token::PLUS;
        } else if (c == '-') {
            return Token::MINUS;
        } else if (c == '*') {
            return Token::MUL;
        } else if (c == '/') {
            return Token::DIV;
        } else if (c == '(') {
            return Token::LBR;
        } else if (c == ')') {
            return Token::RBR;
        } else if (isdigit(c)) {
            value.clear();
            while (isdigit(c)) {
                value.append(1, c);
                if (!in.get(c)) break;
            }
            if (in) in.putback(c);
            return Token::NUM;
        } else if (isalpha(c)) {
            throw string("invalid char: ") + c;
        } else {
            throw string("invalid char: ") + c;
        }
    }
    const string &get_value() const { return value; }
};

class Parser
{
    Scanner &scan;
    Token t;

public:
    Parser(Scanner &scan) : scan(scan) {}
    void parse_P(int &r)
    {
        if (t == Token::ID) {
            // FIXME: handle id
            t = scan.get();
        } else if (t == Token::NUM) {
            r = stol(scan.get_value());
            t = scan.get();
        } else if (t == Token::LBR) {
            t = scan.get();
            parse_E(r);
            if (t != Token::RBR) {
                throw string(") expected");
            }
            t = scan.get();
        } else {
            throw string("parse error before: ") + to_string(int(t));
        }
    }
    void parse_T(int &r)
    {
        parse_P(r);
        while (t == Token::MUL || t == Token::DIV) {
            Token op = t;
            t = scan.get();
            int rr = 0;
            parse_P(rr);
            if (op == Token::MUL) {
                r *= rr;
            } else if (op == Token::DIV) {
                r /= rr;
            }
        }
    }
    void parse_E(int &r)
    {
        parse_T(r);
        while (t == Token::PLUS || t == Token::MINUS) {
            Token op = t;
            t = scan.get();
            int rr = 0;
            parse_T(rr);
            if (op == Token::PLUS) {
                r += rr;
            } else if (op == Token::MINUS) {
                r -= rr;
            }
        }
    }
    void parse(int &r)
    {
        t = scan.get();
        parse_E(r); 
        if (t != Token::EEOF) {
            throw string("garbage");
        }
    }
};

int main()
{
    Scanner scan(cin);
    Parser parser(scan);

    try {
        int result = 0;
        parser.parse(result);
        cout << "result: " << result << endl;
    } catch (const string &s) {
        cout << "error: " << s << endl;
    }
/*
    Token t;
    try {
        while ((t = scan.get()) != Token::EEOF) {
            cout << int(t) << endl;
        }
    } catch (const string &s) {
        cout << "error: " << s << endl;
    }
*/
}

/*
 A -> xA | xB

if (t == 'x') {
   t = scan.get();
   parse_A();
} else if (t == 'x') {
   t = scan.get();
   parse_B();
} else {
// error
}

 */


