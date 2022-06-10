#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char* argv[]) {
  int count = 0;
  int idx = 0;

  char str[20];
  FILE *fp7 = fopen("data.txt","r");
  FILE *fp8 = fopen("temp.txt","a");
  {
    while(!feof(fp7))
    {
      fgets(str,100,fp7);
      for(int i = 0; i<strlen(str); i++)
      {
        if(str[i] == '0')
          fprintf(fp8,"%s","~");
        else if(str[i] == '1')
          fprintf(fp8,"%s","!");
        else if(str[i] == '2')
          fprintf(fp8,"%s","@");
        else if(str[i] == '3')
          fprintf(fp8,"%s","#");
        else if(str[i] == '4')
          fprintf(fp8,"%s","$");
        else if(str[i] == '5')
          fprintf(fp8,"%s",")");
        else if(str[i] == '6')
          fprintf(fp8,"%s","^");
        else if(str[i] == '7')
          fprintf(fp8,"%s","&");
        else if(str[i] == '8')
          fprintf(fp8,"%s","*");
        else if(str[i] == '9')
          fprintf(fp8,"%s","(");
        else
          fprintf(fp8,"%c",str[i]);
        }
      }
  }
  fclose(fp7);
  fclose(fp8);

  FILE *fp1 = fopen("temp.txt","r");
  FILE *fp2 = fopen("temp2.txt","a");
 while(!feof(fp1)){
    char str[100] = "";
    char new[100] = "";
    fgets(str,100,fp1);
    for (int i = 0; i < strlen(str); i++) {
      char temp[50] = "";
      count++;
      if ((str[i] == str[i + 12]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]) && (str[i + 8] == str[i + 12]) && (str[i + 9] == str[i + 13]) && (str[i + 10] == str[i + 14]) && (str[i + 11] == str[i + 15]) && (str[i + 12] == str[i + 16]) && (str[i + 13] == str[i + 17]) && (str[i + 14] == str[i + 18]) && (str[i + 15] == str[i + 19]))
      {  //ex)abcd abcd abcd abcd abcd -> 5abcd, 20
        temp[0] = '5';
        temp[1] = str[i];
        temp[2] = str[i + 1];
        temp[3] = str[i + 2];
        temp[4] = str[i + 3];
        temp[5] = ',';
        strcat(new, temp);
        i = i + 19;
      }
      else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]) && (str[i + 10] == str[i + 12]) && (str[i + 11] == str[i + 13]) && (str[i + 12] == str[i + 14]) && (str[i + 13] == str[i + 15]) && (str[i + 14] == str[i + 16]) && (str[i + 15] == str[i + 17]))
      { //EX) AB AB AB AB AB AB AB AB -> 9AB, 18
        temp[0] = '9';
        temp[1] = str[i];
        temp[2] = str[i + 1];
        temp[3] = ',';
        strcat(new, temp);
        i = i + 17;
      }
 else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]) && (str[i + 10] == str[i + 12]) && (str[i + 11] == str[i + 13]) && (str[i + 12] == str[i + 14]) && (str[i + 13] == str[i + 15]))

      { //EX) AB AB AB AB AB AB AB AB -> 8AB, 16
        temp[0] = '8';
        temp[1] = str[i];
        temp[2] = str[i + 1];
 temp[3] = ',';
        strcat(new, temp);
        i = i + 15;
      }
    else if ((str[i] == str[i + 12]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]) && (str[i + 8] == str[i + 12]) && (str[i + 9] == str[i + 13]) && (str[i + 10] == str[i + 14]) && (str[i + 11] == str[i + 15]))
    {  //ex)abcd abcd abcd abcd -> 4abcd, 16
      temp[0] = '4';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = str[i + 3];
      temp[5] = ',';
      strcat(new, temp);
      i = i + 15;
    }
    else if ((str[i] == str[i + 9] ) && (str[i + 1] == str[i + 4] ) && (str[i + 2] == str[i + 5] ) && (str[i + 6] == str[i + 9] ) && (str[i + 7] == str[i + 10] ) && (str[i + 8] == str[i + 11] ) && (str[i + 9] == str[i + 12] ) && (str[i + 10] == str[i + 13] ) && (str[i + 11] == str[i + 14]))
    { //EX) ABC ABC ABC ABC ABC -> 5ABC, 15
      temp[0] = '5';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = ',';
      strcat(new, temp);
      i = i + 14;
    }
    else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]) && (str[i + 10] == str[i + 12]) && (str[i + 11] == str[i + 13]))
{ //EX) AB AB AB AB AB AB AB -> 7AB, 14
      temp[0] = '7';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = ',';
      strcat(new, temp);
      i = i + 13;
 }
    else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i + 4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i + 6] == str[i + 8]) && (str[i + 7] == str[i + 9]) && (str[i + 9] == str[i + 11]))

    { //EX) AB AB AB AB AB AB -> 6AB, 12
      temp[0] = '6';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = ',';
      strcat(new, temp);
      i = i + 11;
    }
    else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]) && (str[i + 4] == str[i + 8]) && (str[i + 5] == str[i + 9]) && (str[i + 6] == str[i + 10]) && (str[i + 7] == str[i + 11]))
    {  //ex)abcd abcd abcd -> 3abcd, 12
      temp[0] = '3';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = str[i + 3];
      temp[5] = ',';
      strcat(new, temp);
      i = i + 11;
    }

    else if ((str[i] == str[i + 9]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5]) && (str[i + 6] == str[i + 9]) && (str[i + 7] == str[i + 10]) && (str[i + 8] == str[i + 11]))
    { //EX) ABC ABC ABC ABC -> 4ABC, 12
      temp[0] = '4';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = ',';
      strcat(new, temp);
      i = i + 11;
 }
 else if ((str[i] == str[i + 8]) && (str[i + 1] == str[i + 3]) && (str[i+4] == str[i + 6]) && (str[i + 5] == str[i + 7]) && (str[i+6] == str[i + 8]) && (str[i+7] == str[i + 9]))

    { //EX) AB AB AB AB AB-> 5AB, 10
      temp[0] = '5';

      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = ',';
      strcat(new, temp);
      i = i + 9;
    }
    else if ((str[i] == str[i + 3]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5]) && (str[i] == str[i + 6]) && (str[i + 1] == str[i + 7]) && (str[i + 2] == str[i + 8]))
    { //EX) ABC ABC ABC -> 3ABC, 9
      temp[0] = '3';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = ',';
      strcat(new, temp);
      i = i + 8;
    }
    else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]) && (str[i + 3] == str[i + 4]) && (str[i + 4] == str[i + 5]) && (str[i + 5] == str[i + 6]) && (str[i + 6] == str[i + 7]))
    { //EX) AAAA AAAA -> 8A, 8

      temp[0] = '8';
      temp[1] = str[i];
      temp[2] = ',';
      strcat(new, temp);
      i = i + 7;
    }
    else if ((str[i] == str[i + 6]) && (str[i + 1] == str[i + 3]) && (str[i+4] == str[i + 6]) && (str[i + 5] == str[i + 7]))
    { //EX) AB AB AB AB-> 4AB, 8
      temp[0] = '4';
 temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = ',';
      strcat(new, temp);
      i = i + 7;
}

    else if ((str[i] == str[i + 4]) && (str[i + 1] == str[i + 5]) && (str[i + 2] == str[i + 6]) && (str[i + 3] == str[i + 7]))
    {  //ex)abcd abcd -> 2abcd, 8
      temp[0] = '2';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = str[i + 3];
      temp[5] = ',';
      strcat(new, temp);
      i = i + 7;
    }
    else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]) && (str[i + 3] == str[i + 4]) && (str[i + 4] == str[i + 5]) && (str[i + 5] == str[i + 6]))
    { //EX) AAAA AAA -> 7A, 7
      temp[0] = '7';
      temp[1] = str[i];
      temp[2] = ',';
      strcat(new, temp);
      i = i + 6;
    }
    else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]) && (str[i + 3] == str[i + 4]) && (str[i + 4] == str[i + 5]))
    { //EX) AAAA AA -> 6A, 6
      temp[0] = '6';
      temp[1] = str[i];
      temp[2] = ',';
      strcat(new, temp);
      i = i + 5;
    }
    else if ((str[i] == str[i + 2]) && (str[i + 1] == str[i + 3]) && (str[i ] == str[i + 4]) && (str[i + 1] == str[i + 5]))
    { //EX) AB AB AB -> 3AB, 6
      temp[0] = '3';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = ',';
strcat(new, temp);
      i = i + 5;
    }
 else if ((str[i] == str[i + 3]) && (str[i + 1] == str[i + 4]) && (str[i + 2] == str[i + 5]))
    { //EX) ABC ABC -> 2ABC, 6
      temp[0] = '2';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = str[i + 2];
      temp[4] = ',';
      strcat(new, temp);
      i = i + 5;
    }
    else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]) && (str[i + 3] == str[i + 4]))
    { //EX) AAAA A -> 5A, 5
      temp[0] = '5';
      temp[1] = str[i];
      temp[2] = ',';
      strcat(new, temp);
      i = i + 4;
    }
    else if ((str[i] == str[i + 1]) && (str[i + 1] == str[i + 2]) && (str[i + 2] == str[i + 3]))
    { //EX) AAAA -> 4A, 4
      temp[0] = '4';
      temp[1] = str[i];
      temp[2] = ',';
      strcat(new, temp);
      i = i + 3;
    }
      else if ((str[i] == str[i + 2]) && (str[i + 1] == str[i + 3]))
    { //EX) AB AB -> 2AB, 4
      temp[0] = '2';
      temp[1] = str[i];
      temp[2] = str[i + 1];
      temp[3] = ',';
      strcat(new, temp);
      i = i + 3;
    }
 else
    {
      temp[0] = str[i];
      strcat(new, temp);
    }
 }
  fprintf(fp2,"%s",new);
  }
  fclose(fp1);
  fclose(fp2);

  char arr[20];
  FILE *fp3 = fopen("temp2.txt","r");
  FILE *fp5 = fopen("final.txt","w");

  while(!feof(fp3))
  {
  fgets(arr,sizeof(arr),fp3);
  if(strstr(arr,"*DES") != NULL && !feof(fp3))
    idx = 1;
  if(idx == 1)
    fprintf(fp5,"%s",arr);
  }

  fclose(fp3);
  fclose(fp5);

  FILE *fp4 = fopen("result.bin","wb");
  FILE *fp6 = fopen("final.txt","r");

  while(!feof(fp6)){
    char *new_str = malloc(sizeof(char));
    fgets(new_str,100,fp6);
    int askinum;
    int len = 0;
    for(int i=0; i<100; i++)
    {
      len++;
      askinum = new_str[i] - 0;
      if(askinum == 0)
        break;
    }
  fwrite(new_str,sizeof(char) * len-1 , 1 ,fp4);
  }

  fclose(fp4);
  fclose(fp6);
  return 0;
}