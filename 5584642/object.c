#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct status {
				char ID;
				char NAME;
				char GENDER;
				int AGE;
				int HP;
				int MP;
				int Coin;
} status;

void fileread() {
				char filename[100];

				printf("FILENAME : ");

				scanf("%s", filename);

				FILE *fp;
				fp = fopen(filename, "r");

				if(fp == NULL) {
								printf("FILEOPEN FAIL...\n");
								exit(0);
				}

				while(!feof(fp)) {
								printf("%c", fgetc(fp));
				}

				fclose(fp);
}

/* void opendata() {
				char buffer[300];

				FILE *fp = fopen("data.txt", "r");

				while(!feof(fp)) {
								if(fgets(buffer, 300, fp) == NULL)
												break;
								printf("%s", buffer);
				}
				fclose(fp);
				exit(1);
} */



int main() {
				fileread();

				return 0;
}

