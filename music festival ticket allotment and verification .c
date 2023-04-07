#include<stdio.h>
#include<string.h>

struct info{
    int tkt_id;
    char Name[50];
    int Phno;
    int conf;
};

struct info database[200];
int count = 0;

void reg(){
    int i;
    for(i=0; i<200; i++){
        if(database[i].tkt_id == 0){
            printf("Enter Name: ");
            scanf("%s", database[i].Name);
            printf("Enter Phone Number: ");
            scanf("%d", &database[i].Phno);
            database[i].tkt_id = 1001 + i;
            database[i].conf = 0;
            printf("Ticket ID: %d\n", database[i].tkt_id);
            break;
        }
    }
}

void display(){
    int id, i;
    printf("Enter Ticket ID: ");
    scanf("%d", &id);
    for(i=0; i<200; i++){
        if(database[i].tkt_id == id){
            printf("Name: %s\n", database[i].Name);
            printf("Phone Number: %d\n", database[i].Phno);
            printf("Confirmation Status: %d\n", database[i].conf);
            break;
        }
    }
}

void entry(){
    int id, i;
    printf("Enter Ticket ID: ");
    scanf("%d", &id);
    for(i=0; i<200; i++){
        if(database[i].tkt_id == id){
            database[i].conf = 1;
            printf("Confirmation Status Updated\n");
            break;
        }
    }
}

void count_conf(){
    int i;
    count = 0;
    for(i=0; i<200; i++){
        if(database[i].conf == 1){
            count++;
        }
    }
    printf("Confirmed Entries: %d\n", count);
}

void check(){
    int id, i;
    printf("Enter Ticket ID: ");
    scanf("%d", &id);
    for(i=0; i<200; i++){
        if(database[i].tkt_id == id){
            if(database[i].conf == 1){
                printf("It is a valid ticket and the entry has been done\n");
            }
            else{
                printf("It is a valid ticket but the entry is not done\n");
            }
            break;
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\n1. Register\n2. Display\n3. Entry\n4. Count Confirmed Entries\n5. Check\n6. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                reg();
                break;
            case 2:
                display();
                break;
            case 3:
                entry();
                break;
            case 4:
                count_conf();
                break;
            case 5:
                check();
                break;
            case 6:
                printf("Exiting Program\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}