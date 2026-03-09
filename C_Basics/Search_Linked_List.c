
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct dog_type {
    int ID;
    int age; 
    struct dog_type* next;


}dog;
void searchDog(dog* head,int searchID);
int main()
{
    
    
    return 0;


}
void searchDog(dog* head,int searchID) {
    dog* current = head;
    int found = 0;
    while (current) {
        if (current->ID == searchID) {
            printf("Found ID:%d\nAge:%d\n", current->ID, current->age);
            found = 1;
            break;
        }
        current = current->next;

    }
    if (!found) printf("Dog with ID %d not found.\n", searchID);

}
   
    


   
    

}
