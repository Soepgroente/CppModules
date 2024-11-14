#pragma once

#include "AForm.hpp"
#include <iostream>

class AForm;

class Pointer
{
	public:

	Pointer() = delete;
	~Pointer();
	Pointer(AForm* object);
	Pointer(const Pointer& original) = delete;
	Pointer&	operator=(const Pointer& original) = delete;

	AForm&	obj();

	private:
	AForm*	form;
	AForm&	formRef;
};
