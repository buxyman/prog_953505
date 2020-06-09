#include "Delete.h"
void Delete_main(int number, int block_number)
{
	struct Blocks* h;
	for (h = Q2.first; h != NULL; h = h->next)
	{
		if (h->block_numer == block_number)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					if (h->floors_array[i][j].num == number)
					{
						h->floors_array[i][j].status = 0;
						return;
					}
				}
			}
		}
	}
}
