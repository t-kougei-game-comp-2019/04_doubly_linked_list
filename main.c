#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	char str[7];
	int array[100] = { 0 };

	while (fgets(str, sizeof(str), stdin)) {

		int input = atoi(str);

		if (input == 100)
		{
			printf("%d\n", array[0]);
			for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
			{
				if (i + 1 < sizeof(array) / sizeof(array[0]) && array[i] != 0)
					array[i] = array[i + 1];
				else
					break;
			}
		}
		else if (input == -100)
		{

			for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
			{
				if (array[sizeof(array) / sizeof(array[0]) - 1 - i] != 0)
				{ 
					printf("%d\n", array[sizeof(array) / sizeof(array[0]) - 1 - i]);
					array[sizeof(array) / sizeof(array[0]) - 1 - i] = 0;
					break;
				}					
			}
		}
		else if (input == 0)
		{
				for (int i = 0; i < sizeof(array) / sizeof(array[0]) && array[i] != 0; i++)
				{
					if (i == 0)
						printf("%d", array[i]);
					else
						printf(",%d", array[i]);
				}
			printf("\n");
		}
		else
		{
			if (input > 0)
			{
				for (int i = 0; i < sizeof(array) / sizeof(array[0]) - 1; i++)
					array[sizeof(array) / sizeof(array[0]) - 1 - i] = array[sizeof(array) / sizeof(array[0]) - 2 - i];

				array[0] = input;
			}
			else
			{
				for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
				{
					if (array[i] == 0)
					{
						array[i] = -input;
						break;
					}
				}
			}

		}
	}
	return 0;
}
