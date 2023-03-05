#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <stdlib.h>

#include <vector>

using std::cout, std::endl;
using std::vector;

class FD
{
    int fd;

public:
    FD(int fd_) : fd(fd_) {}
    ~FD() { if (close(fd) < 0) abort(); }
    FD(const FD &other) : fd(dup(other.fd)) {}

    void swap(FD &other)
    {
        std::swap(fd, other.fd);
    }

    FD &operator=(FD tmp)
    {
        swap(tmp);
        return *this;
    }
};

int main()
{
    vector<FD> fds;
    //fds.reserve(3); // заранее резервирует память, чтобы избежать копирований
    // при перевыделении памяти
    fds.push_back(FD(dup(0)));
    fds.push_back(FD(dup(1)));
    fds.push_back(FD(dup(2)));
}
