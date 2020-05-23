#include <stdlib.h>
#include "list.h"


int main()
{
	FILE* file = fopen("test.txt", "r");

	struct Node* head = NULL;

	char buff[100];

	read_file(&head, file);

	char sign;

	struct info temp_info;

	scanf("%c", sign);

	while(sign != 'q')
	{
		switch(sign)
		{
			case 'a':
				push_back(&head, temp_info);
				break;
			case 's':
				find(&head, 1);
				break;
			case 'n':
				get_closes(&head, "Minsk");
				break;
			case 'o':
				order_ticket(&head, "Minsk");
				break;
			case 'p':
				get_places(&head, "Minsk");
				break;
			case 'pr':
				print_ticket(temp_info);
				break;
			case 'q':
				write_file(head, file);
				return 0;
			default:
				printf("Type appropriate sign");
				Print_interface(&head);
				break;
		}


	}

	fclose(file);

	freeList(head);

	return 0;
}