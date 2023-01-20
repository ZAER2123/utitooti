#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "project3.h"
int main()
{
   user*head=(user*)malloc(sizeof(user));
   user* user1=(user*)malloc(sizeof(user));
    user1->user_name=(char*)malloc(sizeof(char)*sizeof("hasti"));
    user1->password=(char*)malloc(sizeof(char)*sizeof("123eer"));
    post* first=(post*)malloc(sizeof(post));
   char* online_user=NULL;
   char* order=NULL;
   head->user_name=NULL;
   head->next=NULL;
   //user1->next=NULL;
   //strcpy(user1->user_name,"hasti");
   //strcpy(user1->password,"123eer");
    int natije=0;
    while(natije!=-1)
    {
        natije=start(head,natije,first,order,online_user);
        if(natije==-1)
        {
            printf("goodbye!");
        }
    }
    
}