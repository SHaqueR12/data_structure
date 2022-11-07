#include<stdio.h>
#include<string.h>
int d=256;
void search(char pat[], char txt[], int q)
{
  int M = strlen(pat);
  int N = strlen(txt);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < M-1; i++)
    h = (h*d)%q;

  for (i = 0; i < M; i++)
  {
    p = (d*p + pat[i])%q;
    t = (d*t + txt[i])%q;
  }

  for (i = 0; i <= N - M; i++)
  {
    if ( p == t )
    {
      for (j = 0; j < M; j++)
      {
        if (txt[i+j] != pat[j])
          break;
      }
      if (j == M)
        printf("Pattern found at index %d \n", i);
    }
    if ( i < N-M )
    {
      t = (d*(t - txt[i]*h) + txt[i+M])%q;
      if (t < 0)
      t = (t + q);
    }
  }
}


int main()
{
  char txt[100];// = "acaabaab";
   char pat[100];// = "aab";
   freopen("sm.txt","r",stdin);
  gets(txt);
    gets(pat);
  int q = 3;
  search(pat, txt, q);
  return 0;
}

