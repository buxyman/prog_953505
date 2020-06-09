#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define DEF_STRUCT_CAP 4
#define MAX_INT 2147483647
#define id int
#define money int
#define DEF_LINE_LEN 16
#define DEF_LINE_NUM 4
#define SONGS_ON_THE_RECORD_UPPER_LIMIT 40
#define MAX_NUM_OF_LYR_LINES 120
typedef enum release_type
{
	Composition,
	Single,
	LP,
	EP,
	Mixtape,
} release_type;
typedef struct text
{
	int num_of_lines;
	char** lines;
} text;
typedef struct date
{
	int day, month, year;
} date;
typedef struct user
{
	id user_id;
	char* name;
	int num_of_releases;
	id* releases;
    int num_of_purchased_releases;
	id* purchased_releases;
	money revenue;
	money full_account;
} user;
typedef struct group
{
	int num_of_members;
	id* members;
	user* image;
} group;
typedef struct song
{
	char* name;
	text* lyrics;
} song;
typedef struct release
{
	id release_id;
	release_type type;
	date* dropped;
	char* name;
	int num_of_authors;
	id* authors;
	int num_of_songs;
	song* songs;
	money price;
} release;
typedef struct box
{
	user* u;
	group* g;
	release* r;
} box;
char* file_name;
size_t num_of_users;
size_t num_of_groups;
size_t num_of_releases;
size_t num_of_articles;

user** users;
group** groups;
release** releases;

void get_data_from_file();
void write_data_to_file();
int get_int();
char* get_string(FILE* file_or_con);
text* get_text(FILE* file_or_con, int (*condition_for_reading)(), int max_line_num);

void report_merror();
void report_uerror();
void report_werror();

box* new_box();
user* new_user(char* name);
group* new_group(char* name, int num_of_members, id* members);
release* new_release();

void delete_user(user* one);
void delete_group(group* one);
void delete_release(release* one);

int yes_function();
int length_of(char* str);
int substr(char* sub, char* str);
int are_strs_same(char* first, char* second);
int is_among(int* items, int num_of_items, int item);
void out_str_wo_nl(char* str);

void main_menu();
date* set_date();
void sign_up();
void sign_in();
void session(id you);

box* get_item_by_id(id tag);
id select_one(int among_users, int among_groups, int among_releases);
id* filtered(id* original, int* num_of_options, char* tag);
void add_money(id you);
void release_a_record(id you);
void buy_a_record(id you);
date* set_date();
song set_song();

char* get_string(FILE* file_or_con);
void write_string_to_file(char* str, FILE* file);

text* get_text(FILE* file_or_con, int (*condition_for_reading)(), int max_line_num);
void move_text_to_file(FILE* file, text* text);

void get_data_from_file();
void write_data_to_file();

user* get_user_from_file(FILE* file);
void write_user_to_file(user* one, FILE* file);

group* get_group_from_file(FILE* file);
void write_group_to_file(group* one, FILE* file);

release* get_release_from_file(FILE* file);
void write_release_to_file(release* one, FILE* file);

int* get_int_arr(FILE* file, int size);
void write_int_arr_to_file(FILE* file, int* arr, int size);

money get_money(FILE* file);
void write_money_to_file(FILE* file, money one);

date* get_date(FILE* file);
void write_date_to_file(FILE* file, date* one);

song get_song(FILE* file);
void write_song_to_file(FILE* file, song one);
