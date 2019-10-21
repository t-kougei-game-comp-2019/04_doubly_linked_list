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
	if (head == NULL)
	{
		target->preview = NULL;
		target->next = NULL;
		return target;
	}
	head->preview = target;
	target->next = head;
	target->preview = NULL;
	return target;
}
two_way_list *Link_End(two_way_list *end, two_way_list *target)
{

	end->next = target;
	target->next = NULL;
	target->preview = end;
	return target;
}
void showList(two_way_list *start, two_way_list *end)
{
	if (start == NULL)
	{
		printf("\n");
		return;
	}
	two_way_list *tmp = start;
	while (tmp != end->next)
	{
		if (tmp != start)
			printf(",");
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
		int tmpi = atoi(str);
		if (tmpi == 0)
		{
			showList(header, end);
			continue;
		}
		if (tmpi == 100)
		{
			tmp = header;
			header = tmp->next;
			printf("%d\n", tmp->date);
			free(tmp);
			continue;
		}
		if (tmpi == -100)
		{
			tmp = end;
			end = tmp->preview;
			printf("%d\n", tmp->date);
			free(tmp);
			continue;
		}
		tmp = (two_way_list *)malloc(sizeof(two_way_list));
		tmp->date = tmpi;
		if (header == NULL && end == NULL)
		{
			tmp->preview = NULL;
			tmp->next = NULL;
			header = tmp;
			end = tmp;
			continue;
		}
		if (tmpi < 0)
		{
			tmp->date *= -1;
			end = Link_End(end, tmp);
		}
		else
		{
			header = Link_Head(header, tmp);
		}
	}
	return 0;
}
