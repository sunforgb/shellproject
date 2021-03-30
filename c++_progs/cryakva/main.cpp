#include "functions.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	Lake first_lake, second_lake, first_farm, second_farm;
	generate_world(&first_lake,&second_lake);
	//first_lake.print_list();
	//second_lake.print_list();
	Cryak * some_duck;
	printf("Size of first lake: %d\n", first_lake.get_size());
	printf("Size of second lake: %d\n",second_lake.get_size());
	some_duck=first_lake.del_node(rand()%(first_lake.get_size()));
	some_duck->Show_Info();
	first_farm.add_list(some_duck);
	printf("Size of first farm: %d\n", first_farm.get_size());
	printf("Size of first lake: %d\n", first_lake.get_size());
	some_duck=first_lake.del_node(rand()%(first_lake.get_size()));
	first_farm.add_list(some_duck);
	printf("Size of first farm: %d\n", first_farm.get_size());
	printf("Size of first lake: %d\n", first_lake.get_size());
	//first_farm.print_list();
	//first_lake.print_list();
	return 0;
}	 
