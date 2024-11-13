#include "Serializer.hpp"

int main()
{
	Data*	data = new Data();

	data->dummy = 'c';
	uintptr_t	pointer = Serializer::serialize(data);

	std::cout << "original: " << data << std::endl;
	std::cout << "serialized: " << pointer << std::endl;
	std::cout << "serialized in hex: " << std::hex << pointer << std::dec << std::endl;
	std::cout << "deserialized: " << Serializer::deserialize(pointer) << std::endl;
	delete data;
}