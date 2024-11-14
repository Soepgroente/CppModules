#include "Pointer.hpp"

Pointer::Pointer(AForm* object) : form(object), formRef(*object)
{	
}

AForm&	Pointer::obj()
{
	return (formRef);
}

Pointer::~Pointer()
{
	delete this->form;
}
