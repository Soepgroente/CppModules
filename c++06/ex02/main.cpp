#include "Base.hpp"

int main()
{
	Base*	randomClass;

	for (int i = 0; i < 10; i++)
	{
		randomClass = generate();
		identify(*randomClass);
		identify(randomClass);
		delete randomClass;
	}
}