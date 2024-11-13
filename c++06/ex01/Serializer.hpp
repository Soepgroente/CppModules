#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
	
	Serializer() = delete;
	Serializer(const Serializer& original) = delete;
	Serializer& operator=(const Serializer& original) = delete;
	~Serializer() = delete;

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
