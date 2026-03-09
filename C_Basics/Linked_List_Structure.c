#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct dog_type {
    int ID;
    int age; 
    struct dog_type* next;


}dog;

int main()
{
    dog dog1, dog2, * head;
    head = &dog1;
    dog1.ID = 1741;
    dog1.age = 8;

    //head->next = &dog2;
    dog1.next = &dog2;
    dog2.ID = 1891;
    dog2.age = 3;
    dog2.next = NULL;

    printf("Node 1 ID : %d \nNode 2 ID: %d\n", head->ID, head->next->ID);
    
    return 0;


}

