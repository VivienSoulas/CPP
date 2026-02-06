#include "Serializer.hpp"
#include "Serialize.hpp"
#include "Deserializer.hpp"
#include "Data.hpp"

int main()
{
	uintptr_t pointer;
	Data *data_structure = new Data("name1", 666);
	Serialize serialize;
	Deserializer deserializer;
	Data *new_data_structure;

	std::cout << "Printing data_structures datas:\n";
	data_structure->whoAmI();

	pointer = serialize.serialize(data_structure);
	std::cout << pointer << "\n";

	new_data_structure = deserializer.deserialize(pointer);
	new_data_structure->whoAmI();

	delete(data_structure);
}