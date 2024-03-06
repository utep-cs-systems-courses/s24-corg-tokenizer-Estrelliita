#include "stdlib.h"
#include <stdlib.h>
#include <stdio.h>

/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').  

   Zero terminators are not printable (therefore false) */

int space_char(char c){

  return (c == '\t' || c == ' ');

}

/* Return true (non-zero) if c is a non-whitespace 

   character (not tab or space).  

   Zero terminators are not printable (therefore false) */

int non_space_char(char c){

  if(c == '\0') return 0;
  return !space_char(c);

}



/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str){

  while (*str) {
    if (non_space_char(*str)){ //*str is the value, while str is the pointer. If it encounters a space then retturn the next character after the space
      return str++;
    }
    str ++;
  }
  return NULL;
}


/* Returns a pointer terminator char following *token */

char *token_terminator(char *token){

  while(*token){
    if(space_char(*token)){ //if it encounters a space it returns the character before the space which should be the last char of the token
      return *token--;
    }
    token++;
  }
  return NULL;

}


/* Counts the number of tokens in the string argument. */

int count_tokens(char *str){

  int count  = 0;
  while(*str) {
    str = *token_terminator() 
  }
