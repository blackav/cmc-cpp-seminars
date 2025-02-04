//     [0, 1, 2, 3, 4, 5 ]
//  UB  ^* ^* ^* ^* ^* ^* ^  UB
//      begin()           end()
//  rend()             rbegin()
//
// reverse iterator???
// reverse_iterator rbegin() noexcept { &data[len]; }
// reverse_iterator rend() noexcept { &data[0]; }
//
// class reverse_iterator
// {
// 	T *ptr;
//
// 	constexpr reverse_iterator & operator++() noexcept { --ptr; }
// 	constexpr reverse_iterator & operator--() noexcept { ++ptr; }
// 	T & operator *() noexcept { return ptr[-1]; }
// };

// iterator invalidation

struct stack
{
vector<T> st;
auto pop() -> T
{
	T tmp = st.back(); // *(st.end() - 1)
	st.pop_back();
	return T;
}
};

// why not?
// T pop_back();
