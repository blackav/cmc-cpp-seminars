#include <vector>

using std::vector;
struct NC
{
    NC() {}

    NC(const NC &other) = delete;
    NC(NC &&other) = default;
};

struct NCM
{
    NCM() {}

    NCM(const NCM &other) = delete;
};

struct NM
{
    NM() {}

    //NM(const NM &other) = default;
    NM(NM &&other) = delete;
};

int main()
{
   vector<NC> v; 

   v.push_back(NC());
}
