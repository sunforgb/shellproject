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



				//Class Hohl_cryak methods

Hohl_cryak::Hohl_cryak() : swim(1), home(generate_home()), stamina(100), beak_color(generate_color()){}
Hohl_cryak::~Hohl_cryak()
{
	if (beak_color)
		delete [] beak_color;
}

void Hohl_cryak::Show_Info() const
{
	printf("Our Hohl_CRYAK\n");
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if (this->swim)
		printf("\t\tI can swim, I'm so happy!!\n");
	else
		printf("\t\tI can't swim,HELP ME!!!!\n");
	printf("\t\tMy Home is: %s\n \
		I have Stamina on level: %d\n \
		My Beak_color is: %s\n",this->home,this->stamina,this->beak_color);
}

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
	printf("\t\tHello& my name is: %s\n \
		My Weight is: %d\n",this->name,this->weight);
	if(this->fly)
		printf("\t\tI can fly, I'm so happy cryakvva!!\n");
	else
		printf("\t\tI can't fly, help me kill all hunters,while they sleep!\n");
	printf("\t\tMy Tail_Shape is: %s\n \
		My Height is: %d\n",this->tail_shape,this->height);
}

				//Class Kamen methods
Kamen::Kamen() : clev(1), wingspan((rand()%68)+30), sex('M') {}

Kamen::~Kamen()
{
}

void Kamen::Show_Info() const
{
	printf("Our Kamen_Cryak\n");
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if (this->clev)
		printf("\t\tI can clev u, stupid hunters!!\n");
	else
		printf("\t\t I can't clev, I'm so useless, kill me, please!!\n");
	printf("\t\tMy wingspan is: %d\n \
		My sex is: %c\n",this->wingspan,this->sex);
}

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
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if (this->swim)
		printf("\t\tI can swim, I'm lucky cryak!!\n");
	else
		printf("\t\tI can't swim, what should I do now???\n");
	printf("\t\tMy wing shape is: %s\n \
		My hobby is: %s\n",this->wing_shape,this->hobby);
}


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
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if (this->fly)
		printf("\t\tI can fly, but I never asked for this!!!\n");
	else
		printf("\t\tOkay, I was wrong, I WANT TO FLY, BUT HUNTERS RUINED MY DREAM!!!\n");
	printf("\t\tMy width is: %d\n \
		My tail shape is: %s\n",this->width,this->tail_shape);
}



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
	printf("\t\tHello, my name is: %s\n \
		My weight is: %d\n",this->name,this->weight);
	if (this->run)
		printf("\t\tI can run very fast, faster than light!!!\n");
	else
		printf("\t\t THIS TEXT WILL NEVER SHOWN, BECAUSE A RUNNING CRYAKVA WILL NEVER ESCAPE FROM HUNTERS MYAHAHAHAHAHAHA\n");
	printf("\t\tMy eye color is: %s\n \
		My tail shape is: %s\n",this->eye_color,this->tail_shape);
}

			//class Lake methods
Lake::Lake() : head(NULL), size_list(0) {};
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

void Lake::add_list(Cryak *node)
{
	Cryak *prev = NULL;
	if (head == NULL)
	{
		head = node;
		head->next = NULL;
		size_list++;
	}
	else
	{
		prev = head;
		while ((prev)&&(prev->next))
			prev=prev->next;
		if ((prev)&&((prev->next)==NULL))
			prev->next=node;
		size_list++;
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
