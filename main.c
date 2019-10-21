#include <stdio.h>
typedef struct 
{
	int date;
	Bidirectional_list *preview;
	Bidirectional_list *next;
}Bidirectional_list;


int main(int argc, char *argv[]) 
{
    char str[7];
	Bidirectional_list *header, *end;
	while (fgets(str, sizeof(str), stdin))
	{
		printf("%s", str);
    }

    return 0;
}
