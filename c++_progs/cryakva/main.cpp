#include "functions.h"
#define HUNT_DAYS 7
int main(int argc, char **argv)
{
	srand(time(NULL));
	int days = HUNT_DAYS;
	int input;
	int tmp;
	int creative_effect = 0;
	int creative_cryak_days = 3;
	int hunted_ducks_somewhere = 0;
	int hunted_ducks_on_first_lake = 0;
	int hunted_ducks_on_second_lake = 0;
	Cryak *creative_cryak = NULL;
	// the name of the second Lake - Small Slave Lake, because in the task the names of the lakes are the same
	Lake first_lake("Great Slave Lake", 1), second_lake("Small Slave Lake", 2), first_farm("YUNUSY", 3), second_farm("QYLAQA", 4);
	generate_world(&first_lake,&second_lake);
	Hunters hunter_1(1,"Max"), hunter_2(2,"Oleg"), hunter_3(3,"Egor"), hunter_4(4,"Yaroslav");
	printf("\e[1;1H\e[2J");
	printf("Welcome to our duck life simulator on the lake \"Big Hunt\"\n");
	while (days!=0)
	{
		if ((creative_effect==0)&&(rand()%2))
		{
			creative_effect++;
			switch (rand()%4)
			{
				case 0:
					creative_cryak = new Creative_cryak;
					first_lake.add_list(creative_cryak);
					break;
				case 1:
					creative_cryak = new Creative_cryak;
					second_lake.add_list(creative_cryak);
					break;
				case 2: 
					creative_cryak = new Creative_cryak;
					first_farm.add_list(creative_cryak);
					break;
				case 3:
					creative_cryak = new Creative_cryak;
					second_farm.add_list(creative_cryak);
					break;
				default:
					printf("Something went wrong with add Creative_cryak?\n");
					break;
			}
		}
		printf("Number of day : %d\n", HUNT_DAYS-days+1);
		printf("Menu:\n");
		printf("Enter 1 to see how many ducks on the lake:\n");
		printf("Enter 2 to see which ducks are on the lake or farm:\n");
		printf("Enter 3 to start a new hunt day:\n");
		fseek(stdin,0,SEEK_END);
		input = getchar();
		input = input - (int)'0';
		if ((tmp=getchar())!='\n')
			input^=input;
		printf("\e[1;1H\e[2J");
		switch (input)
		{
			case 1:
				printf("Select lake:\n \
					Enter 1 - Great Slave Lake\n \
					Enter 2 - Small Slave lake\n \
					Enter 3 - YUNUSY farm\n \
					Enter 4 - QYLAQA farm\n");
				scanf("%d", &input);
				switch (input)
				{
					case 1:
						first_lake.Show_Info();
						break;
					case 2:
						second_lake.Show_Info();
						break;
					case 3:
						first_farm.Show_Info();
						break;
					case 4:
						second_farm.Show_Info();
						break;
					default:
						printf("You entered wrong value, back to menu\n");
						break;
				}
				break;
			case 2:
				printf("Select lake/farm:\n \
					Enter 1 - Great Slave Lake\n \
					Enter 2 - Small Slave Lake\n \
					Enter 3 - YUNUSY farm\n \
					Enter 4 - QYLAQA farm\n");
				scanf ("%d", &input);
				switch (input)
				{
					case 1:
						first_lake.print_list();
						break;
					case 2:
						second_lake.print_list();
						break;
					case 3:
						first_farm.print_list();
						break;
					case 4:
						second_farm.print_list();
						break;
					default:
						printf("You entered wrong value, back to menu\n");
						break;
				}
				break;
			case 3:
				if (hunter_1.hunt(&first_lake,&second_lake,&first_farm, hunted_ducks_somewhere)==1)
					hunted_ducks_on_first_lake+=hunted_ducks_somewhere;
				else
					hunted_ducks_on_second_lake+=hunted_ducks_somewhere;;
				if (hunter_2.hunt(&first_lake,&second_lake,&first_farm, hunted_ducks_somewhere)==1)
					hunted_ducks_on_first_lake+=hunted_ducks_somewhere;
				else
					hunted_ducks_on_first_lake+=hunted_ducks_somewhere;
				if (hunter_3.hunt(&first_lake,&second_lake,&second_farm, hunted_ducks_somewhere)==1)
					hunted_ducks_on_first_lake+=hunted_ducks_somewhere;
				else
					hunted_ducks_on_second_lake+=hunted_ducks_somewhere;
				if (hunter_3.hunt(&first_lake,&second_lake,&second_farm, hunted_ducks_somewhere)==1)
					hunted_ducks_on_first_lake+=hunted_ducks_somewhere;
				else
					hunted_ducks_on_second_lake+=hunted_ducks_somewhere;
				days--;
				if (creative_cryak)
					creative_cryak->Show_count_hunted_ducks (hunted_ducks_on_first_lake, hunted_ducks_on_second_lake);
				first_farm.ducks_escape_try(&first_lake,&second_lake);
				second_farm.ducks_escape_try(&first_lake,&second_lake);
				hunted_ducks_somewhere = 0;
				hunted_ducks_on_first_lake = 0;
				hunted_ducks_on_second_lake = 0;
				if ((creative_effect)&&(creative_cryak_days!=0))
				{
					creative_cryak_days--;
				}
				if ((creative_cryak_days == 0)&&(creative_effect))
				{
					first_lake.del_creative_cryak();
					second_lake.del_creative_cryak();
					first_farm.del_creative_cryak();
					second_farm.del_creative_cryak();
					creative_cryak = NULL;
				}
				break;
			default:
				printf("You entered wrong value, back to menu\n");
				break;
		}
	}
	printf("Big Hunt was ended, what to do((\n");
	return 0;
}	 
