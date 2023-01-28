typedef struct posts post;
struct posts{
    char* text;
    int post_id;
    int likes;
    post* next;
};
typedef struct users user; 
struct users
{
char* user_name;
char* password;
post* posts;
user* next;
};
/*this function give characters before an space and return it as a pointer*/
char* get_string()
{
    char* string=(char*)malloc(5*sizeof(char));
    if(string==NULL)
    {
        printf("it's a problem 3 please try again");
        return 0;
    }
    char c=0;
    int i=0;
    c=getchar();
    while(c!=' '&& c!='\n')
    {
        string[i]=c;
        if(i%5==4)
        {
            string=realloc(string,(i+5)*sizeof(char));
            if(string==NULL)
            {
                printf("it's a problem 4 please try again");
                return 0;
            }
        }
        i++;
        c=getchar();
    }
    string[i]='\0';
    return string;
}
/*this function get the head of users list and the order of register then get 
username and compare it with usernames of other user and if it dosen't duplicate 
get pass word and add user to the list */
char* signup(user*head,char*order)
{
    char* string;
    user*current;
    user*last;
    current=head;
    while((current->next)!=NULL)
    {
        current=current->next;
    }
    last=current;
    if(order==NULL)
    {
    printf("signup username password:\n");
    order=get_string();
    }
    int returned=-1;
    returned=strcmp(order,"signup");
    //printf("%d",returned);
    current=head->next;
    if(returned==0)
    {
        char* user_name=get_string();
        returned=-1;
        while(current!=NULL)
        {
            //printf("dddd\n");
            returned=strcmp((current->user_name),user_name);
            if(returned==0)
            {
                printf("your user name was duplicated\n");
                //newuser->user_name=NULL;
                return NULL;
            }
            current=current->next;
        }
        user*newuser=(user*)malloc(sizeof(user));
        newuser->user_name=(char*)malloc(50*sizeof(char));
        newuser->password=(char*)malloc(10*sizeof(char));
        if(newuser==NULL)
        {
        printf("it's a problem 5 please try again\n");
        return NULL;
        }
        if(newuser->user_name==NULL)
        {
        printf("it's a problem 5 please try again\n");
        return NULL;
        }
        if(newuser->password==NULL)
        {
        printf("it's a problem 5 please try again\n");
        return NULL;
        }
        last->next=newuser;
        newuser->next=NULL;
        newuser->user_name=user_name;
        newuser->password=get_string();
        post* first=(post*)malloc(sizeof(post));
        newuser->posts=first;
        first->next=NULL;
        printf("you signed up\n");
        free(current);
        return user_name;
    }
    return NULL;
    /*scanf("%[^\n]%*c",user1);*/

}
/*this function get username and pass word and compare it whit available users and if it is 
correct save the username as an online_user*/
char* login(user* head,char* order,char* user_name1)
{
    char* password1;
    int returned=-1;
    //printf("eeee\n");
    //printf("%s",order);
    if(user_name1!=NULL)
    {
        printf("a regiter was logged in before you.\n");
        return user_name1;
    }
    if(order==NULL)
    {
        printf("login username password\n");
        fflush(stdin);
        order=get_string();
        returned=strcmp(order,"login");
       //printf("%d\n",returned);
        //printf("%s",order);
    }
    else
        returned=strcmp(order,"login");
    if(returned==0)
    {
    user*current;
    user*temp;
    user*last;
    current=head->next;
    user_name1=get_string();
    //printf("%s\n",user_name1);
    password1=get_string();
    //printf("%s\n",password1);
    while(current!= NULL)
    {
        int returned2;
        int retruned=-1;
        returned=strcmp((current->user_name),user_name1);
        //printf("%d\n",returned);
        if(returned==0)
        {
            temp=current;
            returned2=strcmp((temp->password),password1);
            //printf("%d\n",returned);
            //printf("%s\n",temp->password);
            if(returned2==0)
            {
                printf("you logged in\n");                
                return user_name1;
            }
            else
            {
                printf("your password was incorrect\n");
                return NULL;
            }
        }
        else
        {
            current=current->next;
        }
    }
    printf("your user name was incorrect\n");
    return NULL;
    }
}
/*this function get head of user list and head of post list of online user and then add a post 
to the list and save the text of list*/
int posting(user* head,char* order,post* first,char* user_name)
{
    char c;
    int i,ret,counter=0;
    char* new_post=(char*)malloc(20*sizeof(char));
    if(new_post==NULL)
    {
        printf("it's a problem 6 please try again");
        return 0;
    }
    // if(poster==NULL)
    // {
        // printf("we don't have this user in utitooti");
        // return 0;
    // }
   //printf("eeee\n");
    post*current;
    post*last;
    current=first;
   //printf("eeee\n");
    while((current->next)!=NULL)
    {
        counter++;
        current=current->next;
    }
    last=current;
    post*newpost=(post*)malloc(sizeof(post));
    newpost->text=(char*)malloc(100*sizeof(char));
    if(newpost==NULL)
    {
        printf("it's a problem 1 please try again");
        return 0;
    }
    if(newpost->text==NULL)
    {
        printf("it's a problem 1 please try again");
        return 0;
    }
    last->next=newpost;
    newpost->next=NULL;
    printf("write(post <your text>)then press enter:\n");
    order=get_string();
    int r;
    r=strcmp(order,"post");
    if(r!=0)
        return 0;
    i=0;
    c=getchar();
    while(c!='\n')
    {
        new_post[i]=c;
        if(i%20==19)
        {
            new_post=realloc(new_post,(20+i)*sizeof(char));
            if(new_post==NULL)
            {
                printf("it's a problem 2 please try again");
                return 0;
            }
        }
        c=getchar();
        i++;

    }
    new_post[i]='\0';
    strcpy(newpost->text ,new_post);
    newpost->post_id =(counter+1);
    newpost->likes =0;
    printf("your post has been posted!\n");
    free(new_post);

}
/*this function find the head of post list of online user and return it */
post* head_post(user* head,char* online_user)
{
    post* first;
    user*temp;
    user*poster=NULL;
    int ret=-1;
    temp=head->next;
    while(temp!=NULL)
    {
        ret=strcmp((temp->user_name),online_user);
        if(ret==0)
        {
            printf("%d\n",ret);
            poster=temp;
            break;
        }
        else
            temp=temp->next;
    }
    first=poster->posts;
    first->post_id=0;
    first->likes=0;
    return first;
}
/*whit this function you can like your favorite posts*/
int like(user* head)
{
    int ret;
    user*temp;
    user*poster=NULL;
    temp=head->next;
    printf("enter the username and post id of your favorite post:\n");
    char* username=get_string();
    char* string2=(char*)malloc(5*sizeof(char));
    char c;
    int post_id=0;
    int j=0;
    c=getchar();
    while(c!='\n')
    {
        string2[j]=c;
        if(j==0)
            post_id=string2[j]-'0';
        if(j==1)
            post_id=post_id*10+(string2[j]-'0');
        j++;
        c=getchar();
    }
    //printf("%d\n",post_id);
    while(temp!=NULL)
    {
        ret=strcmp((temp->user_name),username);
        if(ret==0)
        {
            poster=temp;
            break;
        }
        else
            temp=temp->next;
    }
    //if(poster==NULL)
    //{
      //  printf("we don't have this user in utitooti");
        //return 0;
    //}
    post* current;
    current=poster->posts->next;
    while(current!=NULL)
    {
        if(current->post_id==post_id)
        {
            (current->likes)++;
            return 1;
        }
        current=current->next;
    }
    printf("this user dosent have this postID");
    return 0;
}
/*this function print your information whit your posts*/
int info(user* head,post* first,char* online_user)
{
    user*temp;
    user*user1=NULL;
    temp=head->next;
    int ret=-1;
    while(temp!=NULL)
    {
        ret=strcmp((temp->user_name),online_user);
        if(ret==0)
        {
            user1=temp;
            break;
        }
        else
            temp=temp->next;
    }
    post* current;
    printf("user name:%s\npassword:%s\n",online_user,user1->password);
    printf("*-----------------------------------------*\n");
    for(current=first->next;current!=NULL;current=current->next)
    {
        printf("post%d:%s\n",(current->post_id),(current->text));
        printf("postID:%d\nlikes:%d\n",(current->post_id),(current->likes));
        printf("*-----------------------------------------*\n");
    }
    return 1;
}
/*this function print all users whit their informations*/
int print_users(user* head)
{
    FILE* input;
    input=fopen("input.txt","w");
    user*temp;
    post* current;
    for(temp=head->next;temp!=NULL;temp=temp->next)
    {
    fprintf(input,"user name:%s\npassword:%s\n",temp->user_name,temp->password);
    fprintf(input,"*-----------------------------------------*\n");
    for(current=temp->posts->next;current!=NULL;current=current->next)
    {
        fprintf(input,"post%d:%s\n",(current->post_id),(current->text));
        fprintf(input,"postID:%d\nlikes:%d\n",(current->post_id),(current->likes));
        fprintf(input,"*-----------------------------------------*\n");
    }
    }
    fclose(input);

}
/*whit this function you can logout and it returns null as an online user */
char* logout(user*head,char* online_username)
{
   if(online_username==NULL)
   {
    printf("we don't have any logged in user\n");
   } 
   else
   {
    online_username=NULL;
    printf("you logged out\n");
    return online_username;
   }
}
/*this function find your post that you want to delete it whit its postid and then delete it from
post list*/
int delete_post(user* head,post* first,char* online_user)
{
    int postID=-1;
    user*temp;
    user*poster=NULL;
    temp=head->next;
    int ret=-1;
    while(temp!=NULL)
    {
        ret=strcmp((temp->user_name),online_user);
        if(ret==0)
        {
            poster=temp;
            break;
        }
        else
            temp=temp->next;
    }
    printf("please enter the ID of the post that you want to delete:\n");
    scanf("%d",&postID);
    int flag=0;
    post* current;
    post* post1;
    post* prev_post;
    current=first->next;
    while(current!=NULL)
    {
       if((current->post_id)==postID)
        {
            //printf("ddd\n");
            post1=current;
            flag=1;
            break;
        }
        else
            current=current->next;
    }
    //printf("ddd\n");
    current=first;
    while(current!=NULL)
    {
        if((current->post_id)==(postID-1))
        {
            prev_post=current;
            break;
        }
        else
            current=current->next;
    }
    //printf("ddd\n");
    if(flag==0)
    {
        printf("you don't have this postID");
        return 0;
    }
    //printf("ddd\n");
    //ret=0;
    // for(current=post1->next;current->next!=NULL;current=current->next)
    // {
        // ret=current->post_id;
        // 
        // current->post_id=(ret-1);
    // }
    prev_post->next=post1->next;
    free(post1);

    printf("your post has been deleted.\n");
    return 1;
}
/*this function find the user that you want whit his or her user name and then print information
and posts*/
int find_user(user* head)
{
    char* order;
    char* username;
    printf("finduser username\n");
    order=get_string();
    if(strcmp(order,"finduser")!=0)
        return 0;
    username=get_string();
    user*temp;
    user*user1=NULL;
    temp=head->next;
    int ret=-1;
    while(temp!=NULL)
    {
        ret=strcmp((temp->user_name),username);
        if(ret==0)
        {
            user1=temp;
            break;
        }
        else
            temp=temp->next;
    }
    post* current;
    printf("the posts of %s:\n",username);
        for(current=user1->posts->next;current!=NULL;current=current->next)
    {
        printf("post%d:%s\n",(current->post_id),(current->text));
        printf("postID:%d\nlikes:%d\n",(current->post_id),(current->likes));
        printf("*-----------------------------------------*\n");
    }
    return 1;
}
/*its our menu*/
int start(user* head,int natije,post* first,char*order,char*online_user,char* signedup_user)
{

    int action=-1;
    int r=0;
    while(online_user==NULL)
    {
        printf("plese enter:\n 1:sign up\n 2:log in\n 0:exit\n");
        scanf("%d",&action);
        switch(action)
        {
            case 1:
                fflush(stdin);
                signedup_user=signup(head,order);
                if(signedup_user!=NULL)
                    break;
            case 2:
                online_user=login(head,order,online_user);
               if(online_user!=NULL)
                    break;
                else
                    action=2;
            case 0:
                return 0;
        }
    }
    while(online_user!=NULL)
    {
    printf("what do you want to do?\n 1:posting\n 2: liking\n 3: see you info\n 4: delete post\n 5: finding user\n 6: log out\n 7:print users\n 0: exit\n");
    scanf("%d",&action);
    int r2=0;
    switch(action)
{
    case 1:
    fflush(stdin);
    while(r2!=1)
    {
        first=head_post(head,signedup_user);
        r2=posting(head,order,first,online_user);
    }
        break;
    case 2:
    fflush(stdin);
    while(r2!=1)
        r2=like(head);
        break;
    case 3:
    fflush(stdin);
    while(r2!=1)
        r2=info(head,first,online_user);
    case 4:
    fflush(stdin);
    while(r2!=1)
        r2=delete_post(head,first,online_user);
        break;
    case 5:
    fflush(stdin);
    while(r2!=1)
        r2=find_user(head);
        break;
    case 6:
    fflush(stdin);
    while(online_user!=NULL)
        online_user=logout(head,online_user);
        break;
    case 7:
    fflush(stdin);
    print_users(head);
        break;
    case 0:
        return -1;
}
    }
}