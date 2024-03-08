
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
  Item *item = malloc(sizeof(Item));
  item->id = item->count++;// Create a new item and set the id field to the next available id.
  item->str = strdup(str);// Set the str field to the string passed in.
  item->next = NULL;// Set the next field to NULL.

  // Add the new item to the end of the list.
  if(list->root == NULL){
    list->root - item;
  }
  else{
    // Search through the list for the last node
    Item *ptr = list->root:
    while(ptr->next != NULL){
      ptr = ptr->next;
    }
    //Add Item after ptr
    ptr->next = item;
  }
}



/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){}



/*Print the entire contents of the list. */

void print_history(List *list){}



/*Free the history list and the strings it references. */

void free_history(List *list){}
