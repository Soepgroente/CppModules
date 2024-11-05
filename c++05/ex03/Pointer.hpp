#pragma once

#include "AForm.hpp"

class Pointer
{
	public:

	Pointer() = delete;
	~Pointer();
	Pointer(AForm* object);
	Pointer(const Pointer& original) = delete;
	Pointer&	operator=(const Pointer& original) = delete;

	AForm*	form;
};
