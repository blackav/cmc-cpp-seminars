#include <cstdio>
#include <memory>

struct FileDeleter
{
	void operator()(FILE *f)
	{
		fclose(f);
	}
};

int main()
{
	{
		std::unique_ptr<FILE,FileDeleter> f(fopen("a.txt", "r"));
	}
	getchar();
}
