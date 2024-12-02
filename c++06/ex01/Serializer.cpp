#include "Serializer.hpp"

/*	Reinterpret_cast interprets the raw bits as the new data type, preserving the value	*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*> (raw));
}