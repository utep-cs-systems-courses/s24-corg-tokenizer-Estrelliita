
#include "history.h"
#include "tokenizer.h"
#include "tokenizer.c"

/* Initialize the linked list to keep the history. */

List* init_history(){
  List* list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}



/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  Item *item = malloc(sizeof(Item)); //allocates memory for a new Item structure and assigns its address to the item pointer.
  char * start = token_start(str);
  item->str = copy_str(start, token_terminator(str)-start);// Set the str field to the string passed in.
  item->next = NULL;// Set the next field to NULL.

  // Add the new item to the end of the list.
  if(list->root == NULL){
    item->id = 0;
    list->root = item;
  }
  else{
    // Search through the list for the last node
    Item *temp = list->root;
    while(temp->next != NULL){
      temp = temp->next;
    }
    //Add Item after temp
    item->id = temp->id + 1;
    temp->next = item;
  }
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *temp = list-> root;
  while(temp->next != NULL){
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next
  }
  
}



/*Print the entire contents of the list. */

void print_history(List *list){}



/*Free the history list and the strings it references. */

void free_history(List *list){}
