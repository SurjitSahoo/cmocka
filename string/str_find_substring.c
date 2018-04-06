#include <assert.h>
#include <stdlib.h>

//#ifdef UNIT_TESTING
extern void mock_assert(const int result, const char* const expression,
                        const char * const file, const int line);
#undef assert
#define assert(expression) \
    mock_assert(((expression) ? 1 : 0), #expression, __FILE__, __LINE__);
//#endif /* UNIT_TESTING */

int str_find_substring(char *str1, char *str2)
{
  assert((str1 != NULL) && (str2 != NULL));  
  int count1 = 0, count2 = 0, i, j, flag, c;
  while (str1[count1] != '\0')
    count1++;
  while (str2[count2] != '\0')
    count2++;
  for(i = 0; i <= count1 - count2; i++){
    for(j = i; j < i + count2; j++){
      flag = 1;
      if(str1[j] != str2[j - i]){
        flag = 0;
        break;
      }
    }
    if(flag == 1){
      c = i;
      break;
    }
  }
  if(flag == 0)
    return -1;
  else
    return c;
}
