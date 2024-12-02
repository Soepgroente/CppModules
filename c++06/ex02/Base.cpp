#include "Base.hpp"
#include <random>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/*	Dynamic cast is specifically for downcasting in abstract classes to ensure you get the right derived class	*/

static Base*	classA()
{
	Base*	random = new A;
	return (random);
}

static Base*	classB()
{
	Base*	random = new B;
	return (random);
}

static Base*	classC()
{
	Base*	random = new C;
	return (random);
}

Base*	generate(void)
{
    const char	classes[] = "abc";
	Base*		(*func[3])(void) = {&classA, &classB, &classC};

	static	std::mt19937	generator{std::random_device{}()};
	static	std::uniform_int_distribution<int> randomClass(0, sizeof(classes) - 2);

    return (func[randomClass(generator)]());
}

void	identify(Base* p)
{
	if (A* tmp = dynamic_cast<A*> (p))
	{
		std::cout << "class A" << std::endl;
	}
	else if (B* tmp = dynamic_cast<B*> (p))
	{
		std::cout << "class B" << std::endl;
	}
	else if (C* tmp = dynamic_cast<C*> (p))
	{
		std::cout << "class C" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		A& classA = dynamic_cast<A&> (p);
		std::cout << "class A" << std::endl;
		(void)classA;
	}
	catch (std::bad_cast ex){}
	try
	{
		B& classB = dynamic_cast<B&> (p);
		std::cout << "class B" << std::endl;
		(void)classB;
	}
	catch (std::bad_cast ex){}
	try
	{
		C& classC = dynamic_cast<C&> (p);
		std::cout << "class C" << std::endl;
		(void)classC;
	}
	catch (std::bad_cast ex){}
}
