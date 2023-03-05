#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <stdlib.h>

#include <vector>

using std::cout, std::endl;
using std::vector;

class FD
{
    int fd{-1};

public:
    FD(int fd_ = -1) : fd(fd_) {}
    ~FD() { if (fd >= 0) close(fd); }
    FD(const FD &other) : fd(other.fd)
    {
        if (fd >= 0) fd = dup(fd);
    }
    FD(FD &&other) noexcept : fd(other.fd)
    {
        other.fd = -1;
    }

    void swap(FD &other) noexcept
    {
        std::swap(fd, other.fd);
    }

    FD &operator=(FD tmp) noexcept
    {
        swap(tmp);
        return *this;
    }
    /*
    FD &operator=(const FD &t) noexcept
    {
        FD tmp{t};
        swap(tmp);
        return *this;
    }
    FD &operator=(FD &&tmp) noexcept
    {
        swap(tmp);
        return *this;
    }
    */
};

int main()
{
    vector<FD> fds;
    fds.push_back(FD(dup(0)));
    fds.push_back(FD(dup(1)));
    fds.push_back(FD(dup(2)));

    FD f1(dup(0));
    fds.push_back(std::move(f1));

    fds.emplace_back(dup(1));

    f1 = FD(dup(2));
    f1 = std::move(fds[0]);
}
