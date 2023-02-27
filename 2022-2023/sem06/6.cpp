#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <stdlib.h>

using std::cout, std::endl;

class FD
{
    int fd;

public:
    FD(int fd_) : fd(fd_) {}
    ~FD() { if (close(fd) < 0) abort(); }
    FD(const FD &other) : fd(dup(other.fd)) {}

    FD &operator=(const FD &other)
    {
        if (this == &other) return *this;

        close(fd);

        fd = dup(other.fd);

        return *this;
    }
};

int main()
{
    //FD f1;
    FD f2(dup(0));

    FD f3{f2};
    FD f4{dup(1)};

    f4 = f3;

    f4 = f4;
}
