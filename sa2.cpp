#include <iostream>
#include <cctype>

using namespace std;

enum class Token
{
    EEOF,
    NUM,
    ID,
    PLUS,
    MINUS,
    MUL,
    DIV,
    LBR,
    RBR,
    SEMICOLON,
    LBRC,
    RBRC,
    IF,
    ELSE
};

class Scanner
{
    istream &in;
    int c;
    string value;

public:
    Scanner(istream &in) : in(in) { c = in.get(); }
    Token get()
    {
        while (isspace(c)) c = in.get();
        if (c == EOF) return Token::EEOF;
        if (c == '+') {
            c = in.get();
            return Token::PLUS;
        } else if (c == '-') {
            c = in.get();
            return Token::MINUS;
        } else if (c == '/') {
            c = in.get();
            return Token::DIV;
        } else if (c == '*') {
            c = in.get();
            return Token::MUL;
        } else if (c == '(') {
            c = in.get();
            return Token::LBR;
        } else if (c == ')') {
            c = in.get();
            return Token::RBR;
        } else if (c == '{') {
            c = in.get();
            return Token::LBRC;
        } else if (c == '}') {
            c = in.get();
            return Token::RBRC;
        } else if (c == ';') {
            c = in.get();
            return Token::SEMICOLON;
        } else if (isdigit(c)) {
            value.clear();
            while (isdigit(c)) {
                value.append(1, char(c));
                c = in.get();
            }
            return Token::NUM;
        } else if (isalpha(c)) {
            value.clear();
            while (isalnum(c)) {
                value.append(1, char(c));
                c = in.get();
            }
            if (value == "if") return Token::IF;
            if (value == "else") return Token::ELSE;
            throw string("ident not supported");
        } else {
            throw string("invalid char: ") + char(c);
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
        if (t == Token::NUM) {
            r = stoi(scan.get_value());
            t = scan.get();
        } else if (t == Token::ID) {
            t = scan.get();
        } else if (t == Token::LBR) {
            t = scan.get();
            parse_E(r);
            if (t != Token::RBR) {
                throw string(") expected");
            }
            t = scan.get();
        } else {
            throw string("parse error before ") + to_string(int(t));
        }
    }
    void parse_F(int &r)
    {
        if (t == Token::PLUS) {
            t = scan.get();
            parse_F(r);
        } else if (t == Token::MINUS) {
            t = scan.get();
            parse_F(r);
            r = -r;
        } else {
            parse_P(r);
        }
    }
    void parse_T(int &r)
    {
        parse_F(r);
        while (t == Token::MUL || t == Token::DIV) {
            auto op = t;
            t = scan.get();
            int rr = 0;
            parse_F(rr);
            if (op == Token::MUL) {
                r *= rr;
            } else if (op == Token::DIV) {
                r /= rr;
            } else {
                abort();
            }
        }
    }
    void parse_E(int &r)
    {
        parse_T(r);
        while (t == Token::PLUS || t == Token::MINUS) {
            auto op = t;
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
    void parse_Z(int &r)
    {
        if (t == Token::LBRC) {
            t = scan.get();
            while (t != Token::RBRC && t != Token::EEOF) {
                parse_Z(r);
                cout << "Res: " << r << endl;
            }
            if (t != Token::RBRC)
                throw string("} expected");
            t = scan.get();
        } else if (t == Token::IF) {
        } else {
            parse_E(r);
            if (t != Token::SEMICOLON) 
                throw string("; expected");
            t = scan.get();
        }
    }
    void parse(int &r)
    {
        t = scan.get();
        parse_Z(r);
        if (t != Token::EEOF) {
            throw string("EOF expected");
        }
    }
};

int main()
{
    Scanner scan(cin);
    Parser parser(scan);

    try {
        int r = 0;
        parser.parse(r);
        cout << "Result: " << r << endl;
    } catch (const string &s) {
        cerr << "error: " << s << endl;
    }

/*
    Token t;

    try {
        while ((t = scan.get()) != Token::EEOF) {
            cout << int(t) << endl;
        }
    } catch (const string &s) {
        cerr << "error: " << s << endl;
    }
*/
}
