#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  FILE *fp1;
  FILE *fp2;
  FILE *fp3;
  FILE *fp4;
  fp1 = fopen("result.bin","rb");
  fp2 = fopen("dec.txt","wt");
  fp4 = fopen("recover.txt","wt");
  while(!feof(fp1)){
    char arr0[30] = "";
    fread(arr0,sizeof(arr0),1,fp1);
    printf("%s",arr0);
    fprintf(fp2,"%s",arr0);
  }
  fclose(fp1);
  fclose(fp2);
  fp3 = fopen("dec.txt","rt");
  while(!feof(fp3)){
    char arr[50] = "";
    fgets(arr,sizeof(arr),fp3);
    char new_arr[50] = "";
    for (int i = 0; i < strlen(arr); i++)
    {
      char re[50] = "";
      char temp[50] = "";
      char one_temp[50] = "";
      if (arr[i] == '2' || arr[i] == '3' || arr[i] == '4' || arr[i] == '5' || arr[i] == '6' || arr[i] == '7' || arr[i] == '8' || arr[i] == '9')
      {
        int k = arr[i] - 48;
        i++;
        while (arr[i] != ',')
        {
          int j = 0;
          re[j] = arr[i];
          strcat(temp, re);
          i++;
        }

        for (int j = 0; j < k; j++) {
          strcat(new_arr, temp);
        }
      }else
{
        one_temp[0] = arr[i];
        strcat(new_arr, one_temp);
      }
    }
    int len = strlen(new_arr);
     for (int i = 0; i < len; i++)
    {
      if(new_arr[i] == '~')
          new_arr[i] = '0';
      if(new_arr[i] == '!')
          new_arr[i] = '1';
      if(new_arr[i] == '@')
          new_arr[i] = '2';
      if(new_arr[i] == '#')
          new_arr[i] = '3';
      if(new_arr[i] == '$')
          new_arr[i] = '4';
      if(new_arr[i] == ')')
          new_arr[i] = '5';
      if(new_arr[i] == '^')
          new_arr[i] = '6';
      if(new_arr[i] == '&')
          new_arr[i] = '7';
      if(new_arr[i] == '*')
          new_arr[i] = '8';
      if(new_arr[i] == '(')
          new_arr[i] = '9';
    }
    fputs(new_arr,fp4);
  }