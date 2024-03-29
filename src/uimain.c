#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(int argc, char* argv[]){
  List * history = init_history();
  while(1){

    printf("Write 's' to input a sentence, 'h' to view history, or 'q' to exit\n> ");
    
    int c = getchar();
    getchar();

    if(c == 'q') {

      free_history(history);
	
      return 0;
    }

    else if (c == 's'){ //if user enters a string
      
      printf("Please enter a string\n> ");

      char str[25];
      fgets(str,25,stdin);
      
      if (*str == '\0'){
	printf("No text entered \n");
      }
      
      else{
	add_history(history, str);
	print_history(history);
	char *token = token_start(str);
	while (token){
	  char *end = token_terminator(token);
	  printf("%s\n", token);
	  token = token_start(end + 1);
	}
	return 1;
      }   
    }

    else if(c == 'h') { //if user wants to look at history

      print_history(history);

    }

  }

}
