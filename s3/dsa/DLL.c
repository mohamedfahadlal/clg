#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct station{
    struct station* prev;
    char name[50];
    struct station*next;
};
struct station* head = NULL;
void insertAtFront(){
    struct station* new_station = (struct station*) malloc(sizeof(struct station));
    if(new_station == NULL){
        printf("MEMORY ALLOCATION FAILED!!!\n");
        return;
    }
    scanf("%s",new_station->name);
    
    if(head == NULL){
        head = new_station;
        new_station->prev = head;
        new_station->next = NULL;
    }
    else{
        new_station->next = head;
        new_station->prev = (struct station*)&head;
        head = new_station;
        new_station->next->prev = new_station;
    }
}

void insertAtEnd(){
    struct station* new_station = (struct station*) malloc(sizeof(struct station));
    if(new_station == NULL){
        printf("MEMORY ALLOCATION FAILED!!!\n");
        return;
    }
    scanf("%s",new_station->name);
    struct station* temp = head;
    if(head == NULL){
        head = new_station;
        new_station->prev = head;
        new_station->next = NULL;
    }
    else{
        while(temp->next != NULL){
            temp= temp->next;
        }
        
        new_station->prev = temp;
        temp->next = new_station;
        new_station->next = NULL;
    }
}

void insertAtAny(){
    struct station* new_station = (struct station*) malloc(sizeof(struct station));
    printf("Enter the new station name: ");
    scanf("%s",new_station->name);
    char key[50];
    printf("Enter postion(name):");
    scanf("%s",key);
    if (head == NULL){
        head = new_station;
        new_station->prev = head;
        new_station->next = NULL;
        return;
    }
    struct station* temp = head;
     while(temp!=NULL){
        if(strcmp(temp->name, key) == 0){
            new_station->next = temp->next;
            new_station->prev = temp;
            if(temp->next!=NULL){
                temp->next->prev = new_station;
            }
            
            temp->next = new_station;
            return;
        }
        else{
            temp = temp->next;
        }
    }
    printf("Key not found!\n");
    
 
}

void deleteStation(){
    char dlt_name[50];
    scanf("%s",dlt_name);
    if(head == NULL){
        printf("LIST IS EMPTY");
        return;
    }
    struct station* temp= head;
    while(temp!=NULL){
        if(strcmp(temp->name,dlt_name) == 0){
            if(temp ==head){
                head = temp->next;
                if(temp->next!=NULL){
                    temp->next->prev = head;
                }
                free(temp);
                return;
            }
            temp ->prev->next = temp->next;
            if(temp->next!=NULL){
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp=temp->next;
    }
    printf("Station not found!\n");
}

void traverseForward(){
    if(head == NULL){
        printf("LIST EMPTY!\n");
        return;
    }
    struct station* temp = head;
    while(temp!= NULL){
        printf("%s ",temp->name);
        temp = temp->next;
    }
    printf("\n");
}

void traverseBackward(){
    if(head == NULL){
        printf("LIST EMPTY!\n");
        return;
    }
    struct station* temp = head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    
    while(temp!=head){
        printf("%s ",temp->name);
        temp = temp->prev;
    }
    printf("%s ",temp->name);
    printf("\n");
}

void display(){
    if(head == NULL){
        printf("LIST EMPTY!\n");
        return;
    }
    struct station* temp = head;
    while(temp!= NULL){
        printf("%s ",temp->name);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int opt;
    while(1){
        printf("Choose an option\n1.Insert a new station at beginning\n2.Insert a new station at end\n3.Insert at any postion\n4.Delete a station\n5.travers forward\n6.traverse backward\n7.modify name of a station\n8.Display route between A and B stations\n9.Exit\nChoose: ");
        scanf("%d",&opt);

        if(opt == 1){
            insertAtFront();
        }
        else if(opt == 2){
            insertAtEnd();
        }
        else if(opt == 3){
            insertAtAny();
        }
        else if(opt == 4){
            deleteStation();
        }
        else if(opt == 5){
            traverseForward();
        }
        else if(opt == 6){
            traverseBackward();
        }
        else if(opt == 9){
            printf("EXIT!!\n");
            break;
        }
        else if(opt == 10){
            display();
        }
    }
    return 0;
}