/*6.2.21 
mp3All.com. Интернет-магазин mp3-композиций. Программа
хранит список музыкальных направлений и статьи о них, список
исполнителей (одиночные исполнители и группы). Каждый
исполнитель имеет свой список альбомов и композиций, а также
тексты композиций и информацию о себе. Поиск композиции и
исполнителя по всем полям. Помещение выбранных композиций в
«корзину», функция оплаты. Отчеты: количество композиций,
дисков и т.д., количество проданных композиций и выручка
магазина.*/
#include "functions.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	file_name = "clean.txt";  
	get_data_from_file();
	main_menu();
	write_data_to_file();
	int i;
	for (i = 0; i < num_of_groups; i++)
	{
		delete_group(groups[i]);
	}
	free(groups);
	for (i = 0; i < num_of_releases; i++)
	{
		delete_release(releases[i]);
	}
	free(releases);
	for (i = 0; i < num_of_users; i++)
	{
		delete_user(users[i]);
	}
	free(users);
}
