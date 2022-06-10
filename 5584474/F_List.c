#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEMBERS 100

typedef struct LIST {
    char* ID;
    char* NAME;
    char* GENDER;
    char* AGE;
    short count;
    short endpoint;
    struct LIST* link;
} LIST;

typedef struct TEMP {
    char* ID;
    char* NAME;
    char* GENDER;
    char* AGE;
    short count;
} TEMP;

LIST* init_LIST(LIST* T_List) {
    T_List = (LIST*)malloc(sizeof(LIST));
    T_List->ID = (char*)malloc(sizeof(LIST));    // temp 동적 메모리 선언
    T_List->NAME = (char*)malloc(sizeof(LIST));  // temp 동적 메모리 선언
    T_List->GENDER = (char*)malloc(sizeof(LIST));
    T_List->AGE = (char*)malloc(sizeof(LIST));
    T_List->count = 0;
    T_List->endpoint = 0;
    return T_List;
}

LIST* insert_LIST(LIST* head, LIST* T_List) {
    if (T_List->count - 1 == 0) {
        LIST* p = (LIST*)malloc(sizeof(LIST));
        p->ID = T_List->ID;
        p->NAME = T_List->NAME;
        p->GENDER = T_List->GENDER;
        p->AGE = T_List->AGE;
        p->count = T_List->count;
        p->endpoint = 0;
        p->link = head;
        head = p;
        return head;
    } else {
        LIST* p = (LIST*)malloc(sizeof(LIST));
        p = head;
        while (p->link != NULL)
            p = p->link;
        LIST* NewNode = (LIST*)malloc(sizeof(LIST));
        p->link = NewNode;
        NewNode->ID = T_List->ID;
        NewNode->NAME = T_List->NAME;
        NewNode->GENDER = T_List->GENDER;
        NewNode->AGE = T_List->AGE;
        NewNode->count = T_List->count;
        NewNode->endpoint = 0;
        NewNode->link = NULL;
        return head;
    }
}

LIST* save_temp(FILE* pFile_t, TEMP* temp, LIST* T_List) {
    temp = (TEMP*)malloc(sizeof(TEMP));

    int i = 0;
    int len = 0;
    short count = 0;
    char buf[255];
    if (T_List->count == 0) {
        temp->ID = fgets(buf, sizeof(buf), pFile_t);
        while (strcmp(temp->ID, "*FRIENDS LIST*\n"))
            temp->ID = fgets(buf, sizeof(buf), pFile_t);
    } else {
        count = T_List->count;
        T_List = T_List->link;

        if (T_List == NULL) {
            T_List = (LIST*)malloc(sizeof(LIST));
            T_List->ID = (char*)malloc(sizeof(LIST));    // temp 동적 메모리 선언
            T_List->NAME = (char*)malloc(sizeof(LIST));  // temp 동적 메모리 선언
            T_List->GENDER = (char*)malloc(sizeof(LIST));
            T_List->AGE = (char*)malloc(sizeof(LIST));
            T_List->count = count;
            T_List->endpoint = 0;
        }
    }
    temp->ID = fgets(buf, sizeof(buf), pFile_t);
    if (strcmp(temp->ID, "*DESCRIPTION*\n") == 0) {
        T_List->endpoint = 1;
        return T_List;
    }
    while (strcmp(temp->ID, "\n") == 0)
        temp->ID = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_ID = strtok(temp->ID, " ");
    while (strcmp(ptr_ID, "ID:"))
        ptr_ID = strtok(NULL, " ");
    ptr_ID = strtok(NULL, " ");
    temp->ID = ptr_ID;
    len = strlen(temp->ID);
    strncpy(T_List->ID, temp->ID, len);

    temp->NAME = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_NAME = strtok(temp->NAME, " ");
    while (strcmp(ptr_NAME, "NAME:"))
        ptr_NAME = strtok(NULL, " ");
    ptr_NAME = strtok(NULL, "");
    temp->NAME = ptr_NAME;
    len = strlen(temp->NAME);
    strncpy(T_List->NAME, temp->NAME, len);

    temp->GENDER = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_GENDER = strtok(temp->GENDER, " ");
    while (strcmp(ptr_GENDER, "GENDER:"))
        ptr_GENDER = strtok(NULL, " ");
    ptr_GENDER = strtok(NULL, "");
    temp->GENDER = ptr_GENDER;
    len = strlen(temp->GENDER);
    strncpy(T_List->GENDER, temp->GENDER, len);
    if (strcmp(T_List->GENDER, "MALE") == 0) {
        strcpy(T_List->GENDER, "M");
    } else if (strcmp(T_List->GENDER, "FEMALE") == 0) {
        strcpy(T_List->GENDER, "FM");
        strcat(T_List->GENDER, " ");
    }
    temp->AGE = fgets(buf, sizeof(buf), pFile_t);
    char* ptr_AGE = strtok(temp->AGE, " ");
    while (strcmp(ptr_AGE, "AGE:"))
        ptr_AGE = strtok(NULL, " ");
    ptr_AGE = strtok(NULL, " ");
    temp->AGE = ptr_AGE;
    len = strlen(temp->AGE);
    strncpy(T_List->AGE, temp->AGE, len);

    temp->count++;
    T_List->count++;
    T_List->link = NULL;
    temp->ID = fgets(buf, sizeof(buf), pFile_t);

    return T_List;
}

void print_list(LIST* head)  //리스트 프린트 함수
{
    for (LIST* p = head; p != NULL; p = p->link) {  //리스트를 차례로 읽어 가는 반복문
        printf("%s", p->ID);
        printf("%s", p->NAME);
        printf("%s", p->GENDER);
        printf("%s", p->AGE);
        printf("%hd",p->count);
        printf("%hd",p->endpoint);
        // printf("===============\n");
    }
}

void WriteFile(FILE* pFile_b, LIST* F_List) {
    pFile_b = fopen("data.bin", "wb");

    if (fwrite(F_List, sizeof(LIST), MAX_MEMBERS, pFile_b) != MAX_MEMBERS) {
        printf("print error\n");
        return;
    }

    fclose(pFile_b);
}

int main(int argc, char* argv[]) {
    FILE* pFile_t;
    FILE* pFile_b;
    LIST* head = NULL;
    LIST* p = (LIST*)malloc(sizeof(LIST));
    TEMP* temp;

    LIST* F_List = (LIST*)malloc(sizeof(LIST));

    pFile_t = fopen("/Users/KimDongHyeon/Desktop/2022 Computer Engineering/2-1/컴퓨터공학창의설계/Final_Project/data.txt", "r");
    p = init_LIST(p);

    if (pFile_t != NULL) {
        do {
            p = save_temp(pFile_t, temp, p);
            if (p->endpoint == 1)
                break;
            head = insert_LIST(head, p);
        } while (feof(pFile_t) == 0 && p != NULL);

        print_list(head);
        fclose(pFile_t);
        WriteFile(pFile_b, head);
    }

    return 0;
}

