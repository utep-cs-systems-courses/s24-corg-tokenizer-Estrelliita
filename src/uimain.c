#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(int argc, char* argv[]){
  List * history = init_history();
  while(1){
    //fputs("Write 's' to input a sentence, 'h' to view history, or 'q' to exit\n>", stdout);
    char str[25];

    printf("Write 's' to input a sentence, 'h' to view history, or 'q' to exit\n>");
    
    printf("$");

    fgets(str,25,stdin);

    if(*str == 'q') {

      free_history(history);
	
      return 0;
    }

    else if (*str == 's'){ //if user enters a string
	
      while(*str && (*str != 's') && (space_char(*str) || *str == '\n')){
	str++;
      }
      if (*str == '\0'){
	printf("No text entered \n");
      }
      else{
	add_history(history, str);
	char *text = str;
	char *token = token_start(text);
	while (token){
	  char *end = token_terminator(token);
	  printf("%s\n", token);
	  token = token_start(end + 1);
	}
      }   
    }

    else if(*str == 'h') { //if user wants to look at history

	print_history(history);

      }
    }

  }

}
