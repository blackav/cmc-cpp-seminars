#include <vector>
#include <stack>
#include <iostream>
#include <list>
#include <queue>
#include <flat_map>

using std::stack, std::vector, std::cout, std::endl;
using std::list;
using std::queue;
using std::priority_queue;

int main()
{
	std::stack<int> st;

	st.push(10);
	st.push(20);

	cout << st.top() << endl;

	stack<double, list<double>> st2;

	st2.push(1.2);
	st2.push(2.4);
	cout << st2.top() << endl;

	queue<int> q1;
	q1.push(10);

	cout << q1.front() << endl;	

	queue<double, list<double>> q2;

	priority_queue<int> pq1;
	pq1.push(100);
	pq1.push(120);
	pq1.push(110);

	cout << pq1.top() << endl;	

	priority_queue<int, vector<int>, std::greater<int>> pq2;
	pq2.push(120);
	pq2.push(100);
	pq2.push(110);
	cout << pq2.top() << endl;	
}
