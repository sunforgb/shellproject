#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node
{
	char* word;
	struct t_node* next;
}t_node;


t_node *add_list(t_node* node, char *string)
{
	struct t_node *prev, *emp;
	if ((node)==NULL)
	{
		emp = (struct t_node*)malloc(sizeof(struct t_node));
		(emp)->word = string;
		(emp)->next = NULL;
		node = emp;
	} 
	else
	{
		prev = (node);
		while ((prev->next)!=NULL)
		{
			prev=prev->next;
		}
		emp = (struct t_node*)malloc(sizeof(struct t_node));
		emp->word=string;
		emp->next = NULL;
		prev->next = (emp);
	}
	return (node);
}
void print_list(t_node* node)
{
	while ((node)!=NULL)
	{
		printf("String in node: %s\n",node->word);
		node=node->next;
	}
}

int main(int argc, char *argv[])
{
	char *segment;
	char *pointer;
	char symbol;
	t_node* t_list;
	t_list=NULL;
	int c;
	int i = 0;
	segment = (char*)malloc(sizeof(char));
	pointer = segment;
	printf("Enter string : \n");
	while (((c=getchar())!=EOF)&&(c!='\n'))
	{
		if (c == ' ')
		{
			*pointer = '\0';
			t_list = add_list(t_list, segment);
			i = 0;
			segment = (char*)malloc(sizeof(char));
			pointer = segment;
			continue;
		}
		symbol = (char)c;
		segment = (char*)realloc(segment,++i);
		*pointer++= symbol;
	}
	*pointer = '\0';
	t_list = add_list(t_list, segment);
	print_list(t_list);
	return 0;
}
