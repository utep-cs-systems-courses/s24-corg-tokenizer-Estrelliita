#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(int argc, char* argv[]){
  List * history = init_history();
  while(1){
    //fputs("Write 's' to input a sentence, 'h' to view history, or 'q' to exit\n>", stdout);
    //int input = getchar();
    char str[25];

    printf("$");

    fgets(str,25,stdin);

    if(*str == '!') {

      if(*(str+1) == 'q') {

	free_history(history);
	
	return 0;
      }

      else if (*str == 's'){ //if user enters a string
	
	char *text = str + 2;
	
	add_history(history, text);

	print_history(history);
      }

      else { //default
	add_history(history,str);

	print_history(history);

      }
    }

    else add_history(history,str);
  }

}
