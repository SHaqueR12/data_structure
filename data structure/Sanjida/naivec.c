#include <stdio.h>
#include <string.h>
int main (){
    int i, j,M,N;
   char txt[100];// = "acaabaab";
   char pat[100];// = "aab";
   freopen("sm.txt","r",stdin);
  gets(txt);
    gets(pat);
    M = strlen (pat);
    N = strlen (txt);
   for ( i = 0; i <= N - M; i++){
      for (j = 0; j < M; j++){
         if (txt[i + j] != pat[j])
      break;}
      if (j == M)
         printf ("Pattern matches at index %d \n", i);
   }
   return 0;
}
