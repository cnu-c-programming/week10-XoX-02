#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
    char name[5];
    int score;
    struct student *next;
};

int main() {
    char inst[10], arg1[10];
    int arg2;
    struct student *s = NULL;
    struct student *p;
    
    while(1){
        scanf("%s",inst);
        if(strcmp(inst, "add") == 0){
            scanf("%s %d",arg1,&arg2);
            p = s;
            if(p == NULL){
                p = malloc(sizeof(struct student));
                strcpy(p->name, arg1);
                p->score = arg2;
                p->next = NULL;
                s = p;
            }else{
                while(p->next != NULL){ p = p->next;}
                struct student *a = malloc(sizeof(struct student));
                strcpy(a->name, arg1);
                a->score = arg2;
                a->next = NULL;
                p -> next = a; 
            } 
        }
        else if(strcmp(inst, "print") == 0){
            p = s;
            while(p != NULL){
                printf("%s %d\n",p->name,p->score);
                p = p->next;
            }
        }
        else if(strcmp(inst, "delete") == 0){
            scanf("%s",arg1);
            p = s;
            struct student *d;
            if(strcmp(p->name,arg1) == 0){
                d = s;
                s = s->next;
                free(d);
            }
            while(strcmp(p->next->name,arg1)){p = p->next;}
            d = p->next;
            p->next = d->next;
            free(d);
        }
        else if(strcmp(inst, "quit") == 0){
            struct student *d;
            p = s;
            while(p != NULL){
                d = p;
                p = p->next;
                free(d);
            }
            break;
        }
    }
    return 0;
} 
