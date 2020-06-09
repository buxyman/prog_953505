#include "Output.h"
void Output_main()
{
	struct Blocks* h;
	int block1 = 0; 
	int block2 = 0;
	int general1_block1 = 0;
	int general1_block2 = 0;
	int general2_block1 = 0;
	int general2_block2 = 0;
	for (h = Q2.first; h != NULL; h = h->next)
	{
		printf("Блок №%d:\n", h->block_numer);
		for (int i = 0; i < 5; i++)
		{
			switch (i)
			{
			case 0:
			{
				printf("ФКП:\n");
				break;
			}
			case 1:
			{
				printf("КСИС:\n");
				break;
			}
			case 2:
			{
				printf("ФИ:\n");
				break;
			}
			case 3:
			{
				printf("ИИТ:\n");
				break;
			}
			case 4:
			{
				printf("ФРЭ:\n");
				break;
			}
			}
			printf("Номера свободных мест:\n");
			for (int j = 0; j < 20; j++)
			{
				if (h->floors_array[i][j].status == 1)
				{
					block1++;
					general1_block1++;
					general2_block1++;
				}
				else
				{
					block2++;
					general1_block2++;
					general2_block2++;
					printf("%d, ", h->floors_array[i][j].num);
				}
			}
			printf("\nКоличество свободных комнат:%d\n", block2);
			printf("Количество жильцов:%d\n", block1);
			block1 = 0;
			block2 = 0;
		}
		printf("Количество свободных комнат в блоке:%d\n", general1_block2);
		printf("Количество жильцов в блоке:%d\n", general1_block1);
		general1_block1 = 0;
		general1_block2 = 0;
		printf("--------------------------------------\n");
	}
	printf("Общее количество совободных комнат:%d\n", general2_block2);
	printf("Общее количество жилицов:%d\n", general2_block1);
}
