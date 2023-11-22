#include "Span.hpp"

int main()
{
	try
	{
		Span list1 = Span(1009);
		//Span list1 = Span(10010);
		std::list<int>	list2;
		Span list4(1000);
		Span list_testmax(4);

		
		list_testmax.addNumber(6);
		list_testmax.addNumber(3);
		std::cout << list_testmax.shortestSpan() << std::endl;

		list4.addNumber(6);
		list4.addNumber(3);
		list4.addNumber(17);
		list4.addNumber(9);
		list4.addNumber(11);
		list1.addManyNumber(list4.getList());
		list2.push_back(6);
		list2.push_back(3);
		list2.push_back(17);
		list2.push_back(9);
		list2.push_back(11);
		list1.addManyNumber(list2);
		std::cout << "finish to fill list2 in list1" << std::endl;
		srand(time(NULL));
		/*std::list<int>	list3;

		for (int i = 0; i < 10000; i++)
			list3.push_back(rand() % 50000);
		list1.addManyNumber(list3);
		std::cout << list1.shortestSpan() << std::endl;
		std::cout << list1.longestSpan() << std::endl;*/
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}