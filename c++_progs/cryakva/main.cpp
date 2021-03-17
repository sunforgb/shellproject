#include "functions.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	/*Hohl_cryak *a;
	a = new Hohl_cryak;
	Mram_chirk *b;
	b = new Mram_chirk;
	Kamen *c = new Kamen;
	Blue_chirok *d = new Blue_chirok;
	Mada_cryakva *e = new Mada_cryakva;
	Krohali *f = new Krohali;
	a->Show_Info();
	b->Show_Info();
	c->Show_Info();
	d->Show_Info();
	e->Show_Info();
	f->Show_Info();*/
	Lake first_lake,second_lake;
	generate_world(&first_lake,&second_lake);
	//printf("Size of first lake: %d\n", first_lake.get_size());
	//printf("Size of second lake: %d\n",second_lake.get_size());
	
	first_lake.print_list();
	second_lake.print_list();
	/*while(1)
	{
		generate_name();
		printf("weight: %d\n",generate_weight());
		printf("Lake : %s\n", generate_home());
		printf("beak_color : %s\n", generate_beak_color());
	}*/
	return 0;
}	 
