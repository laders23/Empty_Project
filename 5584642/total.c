#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decoding(char*argv0, char*argv1){
	int count=0;
	int num=0;
	FILE* fp1 = fopen(argv0, "rb");
	FILE* fp3 = fopen("copy.txt","w");
	char *str=(char*)malloc(sizeof(char));
	char*temp=(char*)malloc(sizeof(char));
	char*ptr=(char*)malloc(sizeof(char));
	while(!feof(fp1)){
		fread(str,2*sizeof(char),1,fp1);
		if(strstr(str,"<<")!=NULL){
			num=1;
			fread(str,2*sizeof(char),1,fp1);
		}
		if(strstr(str,"<<<")!=NULL){
			num=0;
		}
		if(num==1){
			fprintf(fp3,"%s",str);
			if(strchr(str,'\n')){
				count++;
			}
		}
	}
	count=count/4;
	fclose(fp1);
	fclose(fp3);
	int i=0;
	FILE* fp2 = fopen(argv1, "a");
	FILE*fp4=fopen("copy.txt","r");
	while(!feof(fp4)){
		fgets(temp,count*sizeof(temp),fp4);
		if(temp[0]=='\n'){
			fprintf(fp2,"%s\n","*FRIEND LIST*");
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d ID: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d NAME: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
		}
		else{
			fprintf(fp2,"FRIEND%d ID: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
			fprintf(fp2,"FRIEND%d NAME: %s",i+1,temp);
			fgets(temp,count*sizeof(temp),fp4);
		}
		char*p=strstr(temp,"FM");
		char*k=strstr(temp,"M");
		if(p){
			strcpy(temp,"FEMALE\n");
		}
		else if(k){
			strcpy(temp,"MALE\n");
		}
		fprintf(fp2,"FRIEND%d GENDER: %s",i+1,temp);
		fgets(temp,count*sizeof(temp),fp4);
		fprintf(fp2,"FRIEND%d AGE: %s\n",i+1,temp);
		i++;
		if(i==count){
			exit(1);
		}
	}
	fclose(fp2);
	fclose(fp4);

}

int GetStrLen(const char *ap_info)

{
     const char *p_start = ap_info;
     while(*ap_info)
     {
         ap_info++;
     }
     return ap_info - p_start;
}

int ChangeString(char *ap_info, int a_find_len, char *ap_change_info)
{
     char *p_end_pos = ap_info + a_find_len;
     int replace_size = GetStrLen(ap_change_info);
     if(replace_size > a_find_len)
     {
         char *p_src = ap_info + GetStrLen(ap_info);
         char *p_dest = p_src + replace_size - a_find_len;
         while(p_src != (p_end_pos -1)) *p_dest-- = *p_src--;
         while(*ap_change_info) *ap_info++ = *ap_change_info++;
     }
     else
     {
         while(*ap_change_info) *ap_info++ =*ap_change_info++;
         if(a_find_len != replace_size)
         {
             while(*p_end_pos) *ap_info++ = *p_end_pos++;
             *ap_info = 0;
         }
     }
     return replace_size;
}

void ReplaceString(char *ap_info, char *ap_find_info, char *ap_change_info)
{

    int len;
    while(*ap_info)

    {
        if(*ap_info == *ap_find_info)
        {
            for(len = 1; *(ap_find_info + len); len++)
            {

                if(*(ap_info + len) != *(ap_find_info + len))break;
            }
            if(*(ap_find_info + len)==0)
            {
                ap_info = ap_info + ChangeString(ap_info, len, ap_change_info);
            }else ap_info++;
        }else ap_info++;
    }
}

void status_read(char*argv1,char*argv2) {

	char*str=(char*)malloc(sizeof(char));
      	  FILE* fp = fopen(argv1, "rb");
            if(fp == NULL) {
                        printf("FILE OPEN FAIL...\n");
                        exit(0);
            }
            int count = 0;
            
            FILE* fp0 = fopen(argv2, "w");
            FILE* fp1 = fopen("com.txt","w");

            while(1) {
                        fgets(str, sizeof(str), fp);
                        if(feof(fp))
                                    break;
                        fprintf(fp1, "%s", str);
            }

            fclose(fp1);

            FILE* fp2 = fopen("com.txt","r");

            char* temp=(char*)malloc(sizeof(char));

            while(1) {
                        fgets(temp, sizeof(str), fp2);
                        if(feof(fp2))
                                    break;
                        
            //printf("%s",temp);
            
            ReplaceString(temp, "<", "*USER STATUS*");
            
            ReplaceString(temp, ">", "*ITEMS*");
            ReplaceString(temp, "#", "BOOM: ");
            ReplaceString(temp, "&", "POTION: ");
            ReplaceString(temp, "%", "SHIELD: ");
            ReplaceString(temp, "$", "CURE: ");
            ReplaceString(temp, "!", "BOOK: ");
            ReplaceString(temp, "@", "CANNON: ");

            if(count == 1)
            fprintf(fp0, "ID : %s", temp);

            if(count == 2)
        fprintf(fp0, "NAME : %s", temp);

            if(count == 3)
        fprintf(fp0, "GENDER : %s", temp);

            if(count == 4)
        fprintf(fp0, "나이: %s", temp);

            if(count == 5)
        fprintf(fp0, "HP: %s", temp);

            if(count == 6)
        fprintf(fp0, "MP: %s", temp);

            if(count == 7)
            fprintf(fp0, "Coin: %s", temp);
            
            else if(count < 1 || count > 7)
            fprintf(fp0,"%s", temp);
            count++;

            }
            
            fclose(fp);
            fclose(fp0);
           fclose(fp2);
}

int main(int argc, char*argv[]){

	decoding(argv[1],argv[2]);
/*	FILE*fp=fopen(argv[1],"rb");
	char*str=(char*)malloc(sizeof(char));
	int count=0;
	while(!feof(fp)){
		fread(str,sizeof(str),1,fp);
		if(strstr(str,"<<")!=NULL){
			count=1;
		}
		else if(strstr(str,"<<<")!=NULL){
			count=2;
		}
		if(count==0){
			status_read(argv[1],argv[2]);
		}
		if(count==1){
			decoding(argv[1],argv[2]);
		}
		/f(count==2){
			descrtion;
		}
	}
	fclose(fp);*/
	return 0;
}
