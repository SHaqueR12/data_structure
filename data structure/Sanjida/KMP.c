//10679
//12467
#include<stdio.h>
#include<string.h>
void pai_arr(int *a,char pat[])
{
  int i=1,j=0;
    a[0]=0;
    while(i<strlen(pat))
    {
        if(pat[j]==pat[i])
        {
            a[i]=j+1;
            j=j+1;
        }
        else
        {
           if(j!=0){
            j=a[j-1];
            i=i-1;}
           else{
            a[i]=0;
            }
        }
        i++;
    }
}
int main()
{
    char txt[100001];//char txt[]="abxabcabcabyaaabcaby";
    freopen("sm.txt","r",stdin);
    gets(txt);
    char pat[1001];
    gets(pat); //char pat[]="abcaby";
    int a[strlen(pat)+1],i,j=0;
    pai_arr(a,pat);
    ///print pi array
    printf("Pi array is:\n\t\t");
    for(i=0;i<strlen(pat);i++)
        printf("%d ",a[i]);
    i=0;
    while(i<strlen(txt))
    {
        if(txt[i]==pat[j])
        {
            j++;

        }
        else
        {
          if(j!=0){
            j=a[j-1];
            i=i-1;}
        }
        i++;
        if(j==strlen(pat))
            {
                printf("\npatan found at index %d",i-j);
                j=a[j-1];
            }

    }

}
