#include "classHeader.hpp"

Pointer::Pointer(AForm* object) : form(object), formRef(*object)
{	
}

AForm&	Pointer::obj()
{
	return (this->formRef);
}

Pointer::~Pointer()
{
	delete this->form;
}
