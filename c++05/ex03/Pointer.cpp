#include "Pointer.hpp"

Pointer::Pointer(AForm* object)
{
	form = object;
}

Pointer::~Pointer()
{
	delete this->form;
}
