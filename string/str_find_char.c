#include <stdio.h>
/** Searches a character in a string**/
int str_find_char(char *str, char *ch)
{
  if((str == NULL) || (ch == NULL)){
    printf("Error getting the data from calling function\n");
    return -1;
  }
  int i = 0, freq = 0, first_position;
  char c = (*ch);
  while(str[i] != '\0'){
    if(c == str[i]){
      ++freq;
      /* if a character is present more than once */
      if(freq == 1){
        first_position = i+1;
      }
    }
    i++;
  }
  if(freq > 0){
    printf("%c is present %d times in the string\n", *ch, freq);
    return first_position;
    }
  else
    return -1;
}
