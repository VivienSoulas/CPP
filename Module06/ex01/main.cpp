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

	new_data_structure = Serializer::deserialize(pointer);
	
	std::cout << "Printing new_data_structures datas:\n";
	new_data_structure->whoAmI();

	std::cout	<<	"Printing address of data and new_data\n"
				<<	&data_structure << "\n" << &new_data_structure << "\n";

	delete(data_structure);
	return (0);
}