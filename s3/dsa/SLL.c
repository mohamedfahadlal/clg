#include <stdio.h>
#include <stdlib.h>
struct patient{
    int patientID;
    char name[50];
    int priority;
    struct patient* next;
};
struct patient* head = NULL;


void insertPatient(){
    printf("---------------------------Patient Input--------------------------\n");
    struct patient* new_patient = (struct patient*)malloc(sizeof(struct patient));
    if(new_patient == NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter patient ID number:");
    scanf("%d",&new_patient->patientID);
    printf("Enter patient name:");
    scanf("%s",new_patient->name);
    printf("Enter priority:");
    scanf("%d",&new_patient->priority);
    new_patient->next = NULL;
    if(head == NULL){
        head = new_patient;
    }
    else{
        struct patient* temp = head;
        while(temp->next!= NULL){
            temp = temp->next;
        }
        temp->next = new_patient;
    }

}

void deletePatientByID(){
    printf("---------------------------Patient Deletion--------------------------\n");
    struct patient* temp = head;
    if(temp == NULL){
        printf("LIST IS EMPTY!\n");
        return;
    }

    int id;
    printf("Enter patient ID:");
    scanf("%d",&id);

    struct patient* temp1=temp;;
    while(temp->next!=NULL){
        if(id!=temp->patientID){
            temp1 = temp;
            temp = temp->next;
        }
        else{
            temp1->next = temp->next;
            free(temp);
            printf("DELETED SUCCESSFULLY!");
            return;
        }
    }
    printf("ID NOT FOUND!\n");

}

void displayPatient(){
    printf("---------------------------Patient Display--------------------------\n");
    struct patient* temp = head;
    if(temp == NULL){
        printf("LIST IS EMPTY\n");
        return;
    }
    while(temp!=NULL){
        printf("%d %s %d\n",temp->patientID,temp->name,temp->priority);
        temp = temp->next;
    }
}

void swapWithFront(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct patient* prev = NULL;
    struct patient* minprev = NULL;
    struct patient* minnode = head;
    struct patient* curr = head;
    while(curr != NULL){
        if(curr->priority<minnode->priority){
            minprev = prev;
            minnode = curr;
        }
        prev = curr;
        curr = curr->next;
    }

    if (minnode == head){
        printf("Already at correct positon");
    }
    else{
        minprev ->next = minnode->next;
        minnode -> next = head;
        head = minnode;
        printf("Successfully swapped\n");
    }
}

int main(){
    int opt;
    
    while(1){
        printf("---------------------------------------------------------------\n");
        printf("Choose an option:\n1.Insert a new patient\n2.Delete a patient\n3.Display\n4.Emergency case management\n5.Exit\n");
        printf("---------------------------------------------------------------\n");
        printf("Enter option:");
        scanf("%d",&opt);
        
        if(opt == 1){
            insertPatient();
        }
        else if(opt == 2){
            deletePatientByID();
        }
        else if(opt == 3){
            displayPatient();
        }
        else if(opt == 4){
            swapWithFront();
        }
        else if(opt == 5){
            printf("Exit!\n");
            break;
        }
    }
    return 0;
}