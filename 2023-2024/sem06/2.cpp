#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <stdexcept>
#include <stdio.h>

class out_of_fd : public std::runtime_error
{
public:
	out_of_fd() : std::runtime_error("out")
	{
	}
};

class Fd
{
private:
	int fd_{-1};

public:
	Fd() = default;
	explicit Fd(int fd) noexcept : fd_(fd) {}
	~Fd() noexcept
	{
		if (fd_ >= 0) {
			close(fd_);
		}
	}
	Fd(const Fd &other)
	{
		if (other.fd_ >= 0) {
			fd_ = dup(other.fd_);
			if (fd_ < 0) {
				throw out_of_fd{};
			}
		}
	}
	/*
	const Fd &operator = (const Fd &other)
	{
		if (this == &other) {
			return *this;
		}

		if (fd_ >= 0) {
			close(fd_);
		}
		if (other.fd_ >= 0) {
			fd_ = dup(other.fd_);
			if (fd_ < 0) {
				throw out_of_fd{};
			}
		}
		return *this;
	}
	*/
	void swap(Fd &other) noexcept
	{
		auto t = fd_;
		fd_ = other.fd_;
		other.fd_ = t;

		// std::swap(fd_, other.fd_);
	}

	// copy-and-swap
	const Fd &operator =(Fd other) noexcept
	{
		swap(other);
		return *this;
	}

	/*
	const Fd &operator =(const Fd &other)
	{
		if (this == &other) return *this;

		Fd tmp{other};
		swap(tmp);
		return *this;
	}
	*/
};

void f(Fd ff)
{
	getchar();
}

int main()
{
	Fd f1(0);	
	Fd f2 = f1;

	f(f2);

	Fd f3(1);

	f2 = f3;

	// Fd tmp = Fd(f3);
	// f2.swap(tmp);
	// tmp.~Fd();

	f3 = f3;

	//f3.~Fd();
}
