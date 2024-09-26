#include <stdio.h>
#include "copy.h"

char line[MAXLINE]; //incert line
char longest[MAXLINE]; //longest line
/* printing line if you chat longest*/

main(){
  int len;
  int max;
  max = 0;

  while(gets(line) != NULL) {
    len = strlen(line);

    if(len > max) {
       max = len;
       copy(line, longest);
      }
    }

  if(max > 0) //if you chat the line
    printf("%s \n", longest);

  return 0;
}
