#include <stdio.h>
#include <stdlib.h>
#inlcude "history.h"
#include "history.c"

int main(int argc, char* argv[]){
  List * history = init_history();
  while(1){
    //fputs("Write 's' to input a sentence, 'h' to view history, or 'q' to exit\n>", stdout);
    //int input = getchar();
    char str[25];

    printf("$");

    fgets(str,25,stdin);

    if(*str == '!') {

      if(*(str+1) == 'q') return 0;

      add_history(history,str);

      printf("%s",get_history(history,atoi(str+1)));

    }

    else add_history(hist,str);
  }

}
