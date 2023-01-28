#include<stdio.h>  
#include<stdlib.h>  
#include<conio.h>
#include<string.h>
struct Message{
	char* m;
	int message_id;//message 
};

struct node  
{  
    struct node *prev;  
    struct node *next;//creating linked list
    int data;
    char* firstname;
    char* lastname;
	char* user_name;
	int* user_id;
	struct Message mes;
};  
struct node *head;  
void insertion_beginning();//creating node at first location of linked list 
void insertion_last();//creating node at the end of linked list
void insertion_specified();//creating node at any position you want
void deletion_beginning();//deleting node at first location of linked list 
void deletion_last();//deleting node at the end of linked list  
void deletion_specified();//deleting node at any position you want  
void show();  
void search();//searching users
void signup();//creating user pass
void create();
void messages();//posting  
void main ()  
{  
//struct node *firstname = malloc(sizeof(struct node));
int choice =0;  
    while(choice != 9)  
    {  
        printf("\n*********Main Menu*********\n");  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n===============================================\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n10.Signup\n11.Create\n12.Message");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)//getting order with switch case  
        {  
            case 1:  
            insertion_beginning();  
            break;  
            case 2:  
            insertion_last();  
            break;  
            case 3:  
            insertion_specified();  
            break;  
            case 4:  
            deletion_beginning();  
            break;  
            case 5:  
            deletion_last();  
            break;  
            case 6:  
            deletion_specified();  
            break;  
            case 7:  
            search();  
            break;  
            case 8:  
            show();  
            break;  
            case 9:  
            exit(0);  
            break;  
            case 10:
            signup();
            break;
            case 11:
			create();
			break;
			case 12:
			messages();
			break;		
            default:  
            printf("Please enter valid choice..");  
        }  
    }  
}  //typing functions
void insertion_beginning()  //creating node at first location of linked list
{  
   struct node *ptr;   
   int item;  
   ptr = (struct node *)malloc(sizeof(struct node)); //using malloc 
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
    printf("\nEnter Item value");  
    scanf("%d",&item); //getting value with number 
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=item;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=item;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
void insertion_last() //creating node at the end of linked list 
{  
   struct node *ptr,*temp;  
   int item;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nOVERFLOW");  
   }  
   else  
   {  
       printf("\nEnter value");  
       scanf("%d",&item);  
        ptr->data=item;  
       if(head == NULL)  
       {  //how to create node at end:
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  
void insertion_specified()  //creating node at any position you want
{  
   struct node *ptr,*temp;  
   int item,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n OVERFLOW");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the location");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter value");  
       scanf("%d",&item);  
       ptr->data = item;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("\nnode inserted\n");  
   }  
}  
void deletion_beginning()  //deleting node from linked list
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr); //memory leak 
        printf("\nnode deleted\n");  
    }  
  
}  
void deletion_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  
void deletion_specified()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the data after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}  
void show()  //showing the accounts has been made 
{  
    struct node *ptr;  
    printf("\n printing values...\n");  
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d\n",ptr->data);  
        ptr=ptr->next;  
    }  
}   
void search()  //finding member you want
{  //showing location 
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  //moghavem sazi
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
} 
void signup(){
	struct node *ptr;  
    int i=0,flag;
	char item;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item username\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);
				
				char *username;
				char *password;

				printf("Enter the username: ");
				gets(username);

				printf("\nEnter the password: ");
				gets(password);

				if(strcmp(username, "user") == 0){
					//username verification sucessful
					//next step is to verify the password
					if(strcmp(password, "default") == 0){
						//password verification also successful
						printf("\nUser successfully logged in...");
					}else{
						//invalid password. Report it
						printf("\nPassword entered is invalid");
					}
			}else{
				//invalid username. Report it
				printf("\nUsername entered is invalid");
			}
				  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nUser not found\n");  
        }  
    }
	
}
void create(){
	struct node* userData = malloc(sizeof *userData);
	userData[0].user_name=(char*)malloc(sizeof(char*));
	
       
    printf("Enter username :");
    scanf("%s",userData[0].user_name);


	printf("Enter firstname  :");
    scanf("%s",userData[0].firstname);
    
    printf("Enter lastname  :");
    scanf("%s",userData[0].lastname);
    
	printf("Enter user_id  :");
    scanf("%d",&userData[0].user_id);
    
    
    free(userData); //memory leak
}
void messages(){
	struct Message* messageData=malloc(sizeof *messageData);
	int counter=0;
	
	messageData[0].m=(char*)malloc(sizeof(char*));
	printf("Enter Message	:");
	scanf("%s",messageData[0].m);
	
	messageData[0].message_id=counter++;
	printf("Message_id :\t",messageData[0].message_id);
}
