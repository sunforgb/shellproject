#include "classes.h"
#include <stdio.h>
#include <stdlib.h>

			//Prororype functions from function.h
const char *generate_home();
char *generate_color();
char *generate_tail_shape();
char *generate_name();
char *generate_hobby();
char *generate_wing_shape();

				//Abstract class Cryak
Cryak::Cryak() : name(generate_name()), weight((rand()%5)+1), hunted_count(0) {
next = NULL;}

Cryak::~Cryak()
{
	if (name)
		delete [] name;
}

void Cryak::hunted_count_inc()
{
	this->hunted_count++;
}


				//Class Hohl_cryak methods

Hohl_cryak::Hohl_cryak() : swim(1), home("Great Slave Lake"), stamina(100), beak_color(generate_color()){}
Hohl_cryak::~Hohl_cryak()
{
	if (beak_color)
		delete [] beak_color;
}

void Hohl_cryak::Show_Info() const
{
	printf("Our Hohl_CRYAK\n");
	printf("Hunted_count is : %d\n",this->hunted_count);
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if ((this->swim)&&(this->hunted_count<2))
		printf("\t\tI can swim, I'm so happy!!\n");
	else
		printf("\t\tI can't swim,HELP ME!!!!\n");
	printf("\t\tMy Home is: %s\n \
		I have Stamina on level: %d\n \
		My Beak_color is: %s\n",this->home,this->stamina,this->beak_color);
}
int Hohl_cryak::get_fly() const
{
	return 0;
}
int Hohl_cryak::get_swim() const
{
	return (this->swim);
}
int Hohl_cryak::get_clev() const
{
	return 0;
}
int Hohl_cryak::get_run() const
{
	return 0;
}
int Hohl_cryak::get_home() const
{
	return 1;
}
int Hohl_cryak::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!(this->get_home()))&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}
int Hohl_cryak::get_unique_id() const {return 0;}
void Hohl_cryak::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const {}

				//Class Mram_chirk methods
Mram_chirk::Mram_chirk() : fly(1), tail_shape(generate_tail_shape()), \
height((rand()%60)+40){}

Mram_chirk::~Mram_chirk()
{
	if (tail_shape)
		delete [] tail_shape;
}

void Mram_chirk::Show_Info() const 
{
	printf("Our Mram_chirk_CRYAK\n");
	printf("Hunted count is : %d\n", this->hunted_count);
	printf("\t\tHello& my name is: %s\n \
		My Weight is: %d\n",this->name,this->weight);
	if ((this->fly)&&(this->hunted_count<2))
		printf("\t\tI can fly, I'm so happy cryakvva!!\n");
	else
		printf("\t\tI can't fly, help me kill all hunters,while they sleep!\n");
	printf("\t\tI don't know where I live\n");
	printf("\t\tMy Tail_Shape is: %s\n \
		My Height is: %d\n",this->tail_shape,this->height);
}
int Mram_chirk::get_fly() const
{
	return (this->fly);
}
int Mram_chirk::get_swim() const
{
	return 0;
}
int Mram_chirk::get_clev() const
{
	return 0;
}
int Mram_chirk::get_run() const
{
	return 0;
}
int Mram_chirk::get_home() const
{
	return 0;
}
int Mram_chirk::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!(this->get_home()))&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}
int Mram_chirk::get_unique_id() const {return 0;}
void Mram_chirk::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const {}

				//Class Kamen methods
Kamen::Kamen() : clev(1), wingspan((rand()%68)+30) {
	if (rand()%2==1)
		sex='M';
	else
		sex='F';
}

Kamen::~Kamen()
{
}

void Kamen::Show_Info() const
{
	printf("Our Kamen_Cryak\n");
	printf("Hunted_count is : %d\n",this->hunted_count);
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if ((this->clev)&&(this->hunted_count<2))
		printf("\t\tI can clev u, stupid hunters!!\n");
	else
		printf("\t\t I can't clev, I'm so useless, kill me, please!!\n");
	printf("\t\tI don't know where I live\n");
	printf("\t\tMy wingspan is: %d\n \
		My sex is: %c\n",this->wingspan,this->sex);
}
int Kamen::get_fly() const
{
	return 0;
}
int Kamen::get_swim() const
{
	return 0;
}
int Kamen::get_clev() const
{
	return (this->clev);
}
int Kamen::get_run() const
{
	return 0;
}
int Kamen::get_home() const
{
	return 0;
}
int Kamen::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!(this->get_home()))&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}

int Kamen::get_unique_id() const {return 0;}
void Kamen::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const {}

			//Class Blue_chirok methods

Blue_chirok::Blue_chirok() : swim(1), wing_shape(generate_wing_shape()), hobby(generate_hobby()) {}

Blue_chirok::~Blue_chirok()
{
	if (wing_shape)
		delete [] wing_shape;
	if (hobby)
		delete [] hobby;
}

void Blue_chirok::Show_Info() const
{
	printf ("Our Blue_Chirok_Cryak\n");
	printf("Hunted_count is : %d\n",this->hunted_count);
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if ((this->swim)&&(this->hunted_count<2))
		printf("\t\tI can swim, I'm lucky cryak!!\n");
	else
		printf("\t\tI can't swim, what should I do now???\n");
	printf("\t\tI don't know where I live\n");
	printf("\t\tMy wing shape is: %s\n \
		My hobby is: %s\n",this->wing_shape,this->hobby);
}
int Blue_chirok::get_fly() const
{
	return 0;
}
int Blue_chirok::get_swim() const
{
	return (this->swim);
}
int Blue_chirok::get_clev() const
{
	return 0;
}
int Blue_chirok::get_run() const
{
	return 0;
}
int Blue_chirok::get_home() const
{
	return 0;
}
int Blue_chirok::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!(this->get_home()))&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}
int Blue_chirok::get_unique_id() const {return 0;}
void Blue_chirok::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const {}

			//Class Mada_cryakva methods

Mada_cryakva::Mada_cryakva() : fly(1),width((rand()%40)+20), tail_shape(generate_tail_shape()) {}

Mada_cryakva::~Mada_cryakva()
{
	if (tail_shape)
		delete [] tail_shape;
}

void Mada_cryakva::Show_Info() const
{
	printf("Our Mada_cryakva_Cryak\n");
	printf("Hunted_count is : %d\n", this->hunted_count);
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if ((this->fly)&&(this->hunted_count<2))
		printf("\t\tI can fly, but I never asked for this!!!\n");
	else
		printf("\t\tOkay, I was wrong, I WANT TO FLY, BUT HUNTERS RUINED MY DREAM!!!\n");
	printf("\t\tI don't know where I live\n");
	printf("\t\tMy width is: %d\n \
		My tail shape is: %s\n",this->width,this->tail_shape);
}

int Mada_cryakva::get_fly() const
{
	return (this->fly);
}
int Mada_cryakva::get_swim() const
{
	return 0;
}
int Mada_cryakva::get_clev() const
{
	return 0;
}
int Mada_cryakva::get_run() const
{
	return 0;
}
int Mada_cryakva::get_home() const
{
	return 0;
}
int Mada_cryakva::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!(this->get_home()))&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}
int Mada_cryakva::get_unique_id() const {return 0;}
void Mada_cryakva::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const {}

			//class Krohali methods

Krohali::Krohali() : run(1), eye_color(generate_color()), tail_shape(generate_tail_shape()) {}

Krohali::~Krohali()
{
	if (eye_color)
		delete [] eye_color;
	if (tail_shape)
		delete [] tail_shape;
}

void Krohali::Show_Info() const
{
	printf("our Krohali_Cryak\n");
	printf("Hunted_count is : %d\n", this->hunted_count);
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if ((this->run)&&(this->hunted_count<2))
		printf("\t\tI can run very fast, faster than light!!!\n");
	else
		printf("\t\t THIS TEXT WILL NEVER SHOWN, BECAUSE A RUNNING CRYAKVA WILL NEVER ESCAPE FROM HUNTERS MYAHAHAHAHAHAHA\n");
	printf("\t\tI don't know where I live\n");
	printf("\t\tMy eye color is: %s\n \
		My tail shape is: %s\n",this->eye_color,this->tail_shape);
}
int Krohali::get_fly() const
{
	return 0;
}
int Krohali::get_swim() const
{
	return 0;
}
int Krohali::get_clev() const
{
	return 0;
}
int Krohali::get_run() const
{
	return (this->run);
}
int Krohali::get_home() const
{
	return 0;
}
int Krohali::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!(this->get_home()))&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}
int Krohali::get_unique_id() const {return 0;}
void Krohali::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const {}

			//class Creative_Cryak methods
Creative_cryak::Creative_cryak() : name(generate_name()), weight(random()%5+1), hunted_count(0), fly(1), swim(1) {}
Creative_cryak::~Creative_cryak() {}

void Creative_cryak::Show_Info() const
{
	printf("our creative cryak\n");
	printf("Hunted_count is : %d\n", this->hunted_count);
	printf("\t\tHello, my name is : %s\n \
		My weight is : %d\n", this->name, this->weight);
	if ((this->fly)&&(this->hunted_count<2))
		printf("\t\tI can fly, I'm so happy!!\n");
	else
		printf("\t\tI can't fly, my life is broken as me!!!\n");
	printf("\t\tI don't know where I live\n");
}
int Creative_cryak::get_fly() const {return (this->fly);}
int Creative_cryak::get_swim() const {return (this->swim);}
int Creative_cryak::get_clev() const {return 0;}
int Creative_cryak::get_run() const {return 0;}
int Creative_cryak::get_home() const {return 0;}
int Creative_cryak::escape(const int lake_id) const
{
	if ((lake_id==3)&&(this->get_swim())&&(this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	if ((lake_id==4)&&(this->get_swim())&&(!this->get_home())&&(this->hunted_count<2))
		return rand()%2;
	else
		return 0;
}
void Creative_cryak::Show_count_hunted_ducks(const int hunted_lake_1, const int hunted_lake_2) const
{
	printf("%d ducks were hunted on the Great slave Lake\n", hunted_lake_1);
	printf("%d ducks were hunted on the Small Slave Lake\n", hunted_lake_2);
}

int Creative_cryak::get_unique_id() const
{
	return 1;
}

			//class Lake methods
Lake::Lake(const char *tmp, const int id) : head(NULL), name(tmp), lake_id(id), size_list(0), count_fly(0), count_swim(0), count_clev(0), count_run(0), count_home(0) {};
Lake::~Lake()
{
	Cryak *prev = NULL;
	if (head)
	{
		while (head->next)
		{
			prev = head;
			head = head->next;
			delete (prev);
			prev = NULL;
		}
		delete head;
	}
};

int Lake::get_size() const
{
	return size_list;
}
int Lake::get_count_fly() const
{
	return count_fly;
}
int Lake::get_count_swim() const
{
	return count_swim;
}
int Lake::get_count_clev() const
{
	return count_clev;
}
int Lake::get_count_run() const
{
	return count_run;
}
int Lake::get_count_home() const
{
	return count_home;
}

void Lake::add_list(Cryak *node)
{
	Cryak *prev = NULL;
	if (head == NULL)
	{
		head = node;
		head->next = NULL;
		size_list++;
		count_fly+=(head->get_fly());
		count_swim+=(head->get_swim());
		count_clev+=(head->get_clev());
		count_run+=(head->get_run());
		count_home+=(head->get_home());
	}
	else
	{
		prev = head;
		while ((prev)&&(prev->next))
			prev=prev->next;
		if ((prev)&&((prev->next)==NULL))
			prev->next=node;
		size_list++;
		count_fly+=(node->get_fly());
		count_swim+=(node->get_swim());
		count_clev+=(node->get_clev());
		count_run+=(node->get_run());
		count_home+=(node->get_home());
	}
}

void Lake::print_list()
{
	Cryak *prev = head;
	while (prev)
	{
		prev->Show_Info();
		prev=prev->next;
	}
}
Cryak* Lake::del_node(int i)
{
	Cryak *prev, *tmp;
	tmp=head;
	if (!i)
	{
		head = head->next;
		tmp->next = NULL;
		size_list--;
		count_fly-=(tmp->get_fly());
		count_swim-=(tmp->get_swim());
		count_clev-=(tmp->get_clev());
		count_run-=(tmp->get_run());
		count_home-=(tmp->get_home());
		return tmp;
	}
	while (i!=1)
	{
		tmp=tmp->next;
		i--;
	}
	prev = tmp;
	tmp=tmp->next;
	prev->next = tmp->next;
	tmp->next = NULL;
	size_list--;
	count_fly-=(tmp->get_fly());
	count_swim-=(tmp->get_swim());
	count_clev-=(tmp->get_clev());
	count_run-=(tmp->get_run());
	count_home-=(tmp->get_home());
	return tmp;
}
void Lake::del_creative_cryak()
{
	Cryak *tmp;
	int count = 0;
	tmp = head;
	while ((tmp)&&(tmp->next)&&(tmp->get_unique_id()==0))
	{
		count++;
		tmp = tmp->next;
	}
	if ((tmp)&&(tmp->get_unique_id()))
	{
		tmp = del_node(count);
		delete tmp;
	}
}

void Lake::Show_Info() const
{
	printf("It's Our : %s\n", this->name);
	printf("\t\tCount of all ducks: %d\n", this->get_size());
	printf("\t\tCount of ducks that fly: %d\n \
		Count of ducks that swim: %d\n \
		Count of ducks that clev: %d\n \
		Count of ducks that run: %d\n \
		Count of ducks that know their home: %d\n", this->get_count_fly(), this->get_count_swim(), \
		this->get_count_clev(), this->get_count_run(), this->get_count_home());
}

int Lake::get_lake_id() const
{
	return (this->lake_id);
}

int Lake::ducks_escape_try(Lake *first_lake, Lake *second_lake)
{
	if (this->get_size()==0)
		return 0;
	Cryak *tmp = this->head;
	Cryak *some_duck;
	int i = 0;
	while (tmp)
	{
		if (tmp->escape(this->get_lake_id()))
		{
			switch (rand()%2)
			{
				case 0:
					some_duck = this->del_node(i);
					first_lake->add_list(some_duck);
					break;
				case 1:
					some_duck = this->del_node(i);
					second_lake->add_list(some_duck);
					break;
				default:
					printf("something went wrong in rand()\n");
					exit(1);
			}
		}
		i++;
		tmp = tmp->next;
	}
	return 0;
}

						//Class Hunters methods

Hunters::Hunters(const int id) : hunter_id(id) {}

Hunters::~Hunters(){}

int Hunters::hunt(Lake *first_lake, Lake *second_lake, Lake *farm ,int &hunted_ducks) const
{
	Cryak *some_duck;
	Lake *hunt_lake;
	int number_ducks_to_hunt;
	int i = rand()%2;
	switch (i)
	{
		case 0:
			hunt_lake = first_lake;
			break;
		case 1:
			hunt_lake = second_lake;
			break;
		default:
			printf("Something went wrong in hunting switch\n");
			exit(1);
	}
	if ((first_lake->get_size() == 0)&&(second_lake->get_size() == 0))
	{
		printf("All ducks were hunted!!!\n");
		exit(0);
	}
	if ((i == 0)&&(hunt_lake->get_size()==0))
		hunt_lake = second_lake;
	if ((i == 1)&&(hunt_lake->get_size()==0))
		hunt_lake = first_lake;
	switch (this->hunter_id)
	{
		case 1:
			if (hunt_lake->get_size()<=9)
				number_ducks_to_hunt = rand()%hunt_lake->get_size()+1;
			else
				number_ducks_to_hunt=(rand()%6)+4;
			break;
		case 2:
			if (hunt_lake->get_size()<=8)
				number_ducks_to_hunt = rand()%hunt_lake->get_size()+1;
			else
				number_ducks_to_hunt=(rand()%8) + 1;
			break;
		case 3:
			if (hunt_lake->get_size()<=10)
				number_ducks_to_hunt = rand()%hunt_lake->get_size()+1;
			else
				number_ducks_to_hunt=(rand()%10) + 1;
			break;
		case 4:
			if (hunt_lake->get_size()<=7)
				number_ducks_to_hunt = rand()%hunt_lake->get_size()+1;
			else
				number_ducks_to_hunt=(rand()%4) + 4;
			break;
		default:
			printf("Invalid hunter_number in hunt function\n");
			exit(1);
	}
	for (int j=0; j<number_ducks_to_hunt; j++)
	{
		some_duck = hunt_lake->del_node(rand()%hunt_lake->get_size());
		if ((some_duck->get_clev()==1)&&(rand()%2))
		{
			hunt_lake->add_list(some_duck);
		}
		else
		{
			some_duck->hunted_count_inc();
			farm->add_list(some_duck);
		}
	}
	hunted_ducks = number_ducks_to_hunt;
	return hunt_lake->get_lake_id();
}
