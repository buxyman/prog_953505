#include <stdio.h>
#include <stdbool.h>

struct info
{
   int number;
   char* type;
   char* route;
   int stops;
   int time;
   int days;
   int places;
   bool is_ordered;
};

struct pair
{
   int time;
   struct info _info_;
};

struct Node
{ 
   struct info data; 
   struct Node* next; 
   struct Node* prev;
}; 

void reverse(struct Node** head_ref) 
{ 
   struct Node* prev = NULL; 
   struct Node* current = *head_ref; 
   struct Node* next = NULL; 
   while (current != NULL) 
   { 
      next = current->next; 
 
      current->next = prev; 

      prev = current; 
      current = next; 
   } 

   *head_ref = prev; 
} 

bool cmp(struct info left, struct info right)
{
   return (left.days == right.days) && (left.number == right.number) && (left.route && right.route) && (left.stops == right.stops) && (left.time == right.time) && (left.type == right.type) && (left.places == right.places);
}

bool cmpSc(struct info _info, char* val)
{
   return (_info.days==val) || (_info.number==val) || (_info.route==val) || (_info.stops==val) || (_info.time==atoi(val)) || (_info.type==val) || (_info.places == atoi(val));
}

void find_elem(struct Node* head, int val)
{
   struct Node* current = head;

   while(current != NULL)
   {
      if(current->data.time == val)
      {
         print(current->data);
      }
      current = current->next;
   }
}

struct pair get_closes(struct Node** head_ref, char* val)
{
   struct Node* current = *head_ref;
   struct Node* current_fin = *head_ref;
   struct pair _pair_;
   _pair_.time = current->data.time;

   while(current != NULL)
   {
      if(current->data.route == val)
      {
         if(current->data.time < _pair_.time)
         {
            _pair_.time = current->data.time;
            _pair_._info_ = current->data;
         }
      }
      current = current->next;
   }
   return _pair_;
}

void order_ticket(struct Node** head, char* route)
{
   struct Node* current = *head;

   while(current)
   {
      if(current->data.route == route)
      {
         current->data.is_ordered = true;
      }
      current = current->next;
   }
}

void print(struct info inf)
{
   if(inf.is_ordered)
   {
      printf("ticket is ordered\n");
   }

   printf("Number - %i, Type - %s, Route - %s, Stops - %i, Time - %i, Days - %i, Places - %i\n", inf.number, inf.type, inf.route, inf.stops, inf.time, inf.days, inf.places);
}

void read_file(struct Node** head, FILE* file)
{

	while(!feof(file))
   {
      struct info _info;
      		
      if (fscanf(file, "%i", &_info.is_ordered) == EOF) break; // доп проверка на конец файла

      _info.type = (char*)calloc(40, sizeof(char));
      _info.route = (char*)calloc(40, sizeof(char));

      fscanf(file, "%i", &_info.number);
   
      fscanf(file, "%s", _info.type);
   
      fscanf(file, "%s", _info.route);
   
      fscanf(file, "%d", &_info.stops);
   
      fscanf(file, "%d", &_info.time);
   
      fscanf(file, "%d", &_info.days);
   
      fscanf(file, "%d", &_info.places);
   
      fscanf(file, "%d", &_info.is_ordered);


      fgetc(file);

      push_back(head, _info);

      if(feof(file))
      {
         break;
      }
   
   }
}

void freeList(struct Node* head)
{
   struct Node* tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

void write_file(struct Node* head, FILE* file)
{
   struct Node* current = head;

   while(current)
   {
      fprintf(file, "%i", current->data.number);
   
      fprintf(file, "%s", current->data.type);
   
      fprintf(file, "%s", current->data.route);
   
      fprintf(file, "%d", current->data.stops);
   
      fprintf(file, "%d", current->data.time);
   
      fprintf(file, "%d", current->data.days);
   
      fprintf(file, "%d", current->data.places);
   
      fprintf(file, "%d", current->data.is_ordered);

      current = current->next;
   }
}

int get_places(struct Node* head, char* route)
{
   struct Node* current = NULL;
   current = head;

   while(current)
   {
      if(current->data.route == route)
      {
         return current->data.places;
      }
      current = current->next;
   }
}

void print_ticket(struct info _info)
{
   printf("Ticket number %d with a type %s to %s has been bought", _info.number, _info.type, _info.route);
}

void Print_interface(struct Node* list)
{
	print_list(list);

	puts("\n\n'a' - добавить");
	puts("'s' - поиск");
	puts("'n' - ближайший рейс");
	puts("'o' - заказать билет");
	puts("'p' - количество мест на рейсе");
	puts("'pr' - печатная ведомость");

	puts("'q' - выход");
}

struct info find(struct Node** head_ref, char* val )
{
   struct Node* next = NULL;
   struct Node* current = *head_ref;

   while(current != NULL)
   {
      if(cmpSc(current->data, val))
      {
         return current->data;
      }
      next = current->next;
      current = next;
   }
   return;
}

void push(struct Node** head_ref, struct info new_data) 
{ 
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
   new_node->data = new_data; 
   new_node->next = (*head_ref); 
   (*head_ref) = new_node; 
}


void push_back(struct Node** head_ref, struct info new_data)
{
   new_data.is_ordered = false;
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   struct Node* iterator = *head_ref;
   new_node->data = new_data;
   new_node->next = NULL;

   if(iterator == NULL)
   {
      *head_ref = new_node;
      return;
   }

   while(iterator->next != NULL)
   {
      iterator = iterator->next;
   }

   iterator->next = new_node;

} 

void print_list(struct Node* head) 
{ 
   struct Node* temp = head; 


   while (temp != NULL) 
   { 
      print(temp->data);
      temp = temp->next; 
   } 
} 