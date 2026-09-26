
#include <stdio.h>
#include <stdlib.h>



int main(void){
   FILE *file = fopen("node.id" , "w");
   char buffer[256];
   fgets(buffer, sizeof(buffer), stdin);
   fputs(buffer, file);
   fprintf(file, "%s", buffer);
   fclose(file);
   return 0;
}
