#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;


	MutantStack<int> mstack2 = mstack;

	std::list<int> test;
	test.push_back(5);
	test.push_back(17);
	std::cout << test.back() << std::endl;
	test.pop_back();
	std::cout << test.size() << std::endl;
	test.push_back(3);
	test.push_back(5);
	test.push_back(737);
	//[...]
	test.push_back(0);

	std::list<int>::iterator it1 = test.begin();
	std::list<int>::iterator ite1 = test.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}

	return 0;
}