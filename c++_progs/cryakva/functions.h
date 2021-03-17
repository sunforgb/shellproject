#include "class_methods.h"
#include <time.h>
#include <string.h>

char* get_string(int count, const char *file_name)  /* skip count '\n', example count=14 - we get 15 string*/
{
	FILE *fp;
	int i = 0;
	int j = 0;
	int c;
	char symbol;
	char *segment = NULL;
	char *tmp = NULL;
	if((fp=fopen(file_name,"rt"))==NULL)
	{
		printf("Can't open file %s\n", file_name);
		exit(1);
	}
	while (i!=count)
	{
		if ((c = fgetc(fp))=='\n')
			i++;
		else
			continue;
	}
	j = 0;
	i = 3;
	segment = new char[i]();
	while (((c=fgetc(fp))!='\n')&&(c!=EOF))
	{
		if (j>i-1)
		{
			i+=2;
			tmp = new char [i]();
			memcpy(tmp,segment,i-2);
			delete [] segment;
			segment = tmp;
		}
		segment[j++] = (char) c;
	}
	tmp = new char[i+1]();
	memcpy(tmp,segment,i);
	delete [] segment;
	segment = tmp;
	symbol = '\0';
	segment = strcat(segment,&symbol);
	if (j!=i)
	{
		tmp = new char [j+1]();
		strcpy(tmp, segment);
		delete [] segment;
		segment = tmp;
	}
	fclose(fp);
	return segment;
}

char *generate_name()
{
	char *adj, *name, *full_name;
	name = NULL;
	adj = NULL;
	full_name = NULL;
	adj = get_string((rand()%28),"data_adj.txt");
	name = get_string((rand()%29),"data_names.txt");
	full_name = new char[strlen(name)+strlen(adj)+strlen("Cryakva")+3];
	full_name = strcpy(full_name, adj);
	full_name = strcat(full_name, " ");
	full_name = strcat(full_name, name);
	full_name = strcat(full_name, " ");
	full_name = strcat(full_name, "Cryakva");
	delete [] adj;
	delete [] name;
	return full_name;
}

const char *generate_home()
{
	if ((rand()%2)==0)
		return "Big Rab Lake";
	else
		return "Small Rab Lake";
}

char *generate_color()
{
	return get_string((rand()%7),"data_color.txt");
}

char *generate_tail_shape()
{
	return get_string((rand()%8),"data_tail_shape.txt");
}	
	
char *generate_hobby()
{
	return get_string((rand()%8),"data_hobby.txt");
}

char *generate_wing_shape()
{
	return get_string((rand()%8),"data_tail_shape.txt");
}
void generate_world(Lake *first_lake, Lake *second_lake)
{
	int i;
	//i = rand()%32;
	//j = 32 - i;
	for (i = 0;i<27;i++)
	{
		first_lake->add_list(new Hohl_cryak);
		first_lake->add_list(new Mram_chirk);
		first_lake->add_list(new Kamen);
		second_lake->add_list(new Blue_chirok);
		second_lake->add_list(new Mada_cryakva);
		second_lake->add_list(new Krohali);
	}
	switch (rand()%3)
	{
		case 0:
			first_lake->add_list(new Hohl_cryak);
			second_lake->add_list(new Blue_chirok);
			break;
		case 1:
			first_lake->add_list(new Mram_chirk);
			second_lake->add_list(new Mada_cryakva);
			break;
		case 2:
			first_lake->add_list(new Kamen);
			second_lake->add_list(new Krohali);
			break;
		default:
			printf("Error in generate_world, extra_cryakvas not added\n");
			break;
	}
	printf("first lake contains cryakvas: %d\n",first_lake->get_size());
	printf("second lake constains cryakvas: %d\n",second_lake->get_size());	
}	
