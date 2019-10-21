#include <stdio.h>
#include <stdlib.h>
typedef struct two_way_list
{
	int date;
	struct two_way_list *preview;
	struct two_way_list *next;
} two_way_list;

two_way_list *Link_Head(two_way_list *head, two_way_list *target)
{
	head->preview = target;
	target->next = head;
	target->preview = NULL;
	return target;
}
void showList(two_way_list *start, two_way_list *end)
{
	two_way_list *tmp = start;
	while (tmp != end->next)
	{
		printf("%d", tmp->date);
		tmp = tmp->next;
	}
	printf("\n");
}
int main(int argc, char *argv[])
{
	char str[7];
	two_way_list *header = NULL,
				 *end = NULL,
				 *tmp = NULL;
	while (fgets(str, sizeof(str), stdin))
	{
		if (atoi(str) == 0)
		{
			showList(header, end);
			continue;
		}
		
		tmp = (two_way_list *)malloc(sizeof(two_way_list));
		tmp->date = atoi(str);
		if (header == NULL)
		{
			header = tmp;
			end = tmp;
			tmp->next = NULL;
		}
		else
		{
			header = Link_Head(header, tmp);
		}
	}
	return 0;
}
