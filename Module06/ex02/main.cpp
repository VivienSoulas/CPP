#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);

// It prints the actual type of the object pointed to by p: "A", "B", or "C".
void identify(Base *p);

// It prints the actual type of the object referenced by p: "A", "B", or "C".
void identify(Base &p);

int main()
{
	Base *new_base = generate();
	std::cout << "Printing actual type via * pointer\n";
	identify(new_base);
	std::cout << "Printing actual type via & reference\n";
	identify(*new_base);

	delete new_base;
	return (0);
}

Base *generate(void)
{
	Base *New_Base;

	time_t now = time(NULL);

	if (now % 2 == 0)
	{
		std::cout << "Generating A object\n";
		New_Base = new A;
	}
	else if (now % 3 == 0)
	{
		std::cout << "Generating B object\n";
		New_Base = new B;
	}
	else
	{
		std::cout << "Generating C object\n";
		New_Base = new C;
	}
	return (New_Base);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else
		std::cout << "C\n";
}

void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return ;
	}
	catch (const std::bad_cast&)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return ;
	}
	catch (const std::bad_cast&)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return ;
	}
	catch (const std::bad_cast&)
	{}
}