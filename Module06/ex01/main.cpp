#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	uintptr_t pointer;
	Data *data_structure = new Data("name1", 666);
	Data *new_data_structure;

	std::cout << "Printing data_structures datas:\n";
	data_structure->whoAmI();

	pointer = Serializer::serialize(data_structure);
	std::cout << pointer << "\n";

	new_data_structure = Serializer::deserialize(pointer);
	new_data_structure->whoAmI();

	delete(data_structure);
}