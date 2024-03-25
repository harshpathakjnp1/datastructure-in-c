#include<stdio.h>
#include<stdlib.h>
typedef struct mynode{
    int data;
    struct mynode* next;
} node;
void addLast(node** head, int data);
void addFirst(node** head, int data);
void addSorted(node** head, int data);
void addAt(node** head, int val, int pos);
int getLength(node* head);
void traverse(node* head);
void search(node* head,int data);
void deleter(node** head,int data);
void reverse(node** head);
void search2(node* head,int data);
void position(node* head,int data);
int main()
{
    node *head=NULL;
    int x,pos;
    while(1)
    {
    printf("\n 0-exit  1-AddFirst  2-AddLast  3-AddSorted  4-AddAt 5-Length  6-Search \n 7-Delete  8-Traverse  9-Reverse  10-SEARCH & COUNT   11- Find Position \nChoose the option :");
    int opt;
    scanf("%d",&opt);
    switch (opt)
    {
    case 0:
        return 0;
        break;
    case 1:
        printf("Enter the number :");

        scanf("%d",&x);
        addFirst(&head,x);
        //printf("Hi\n");
        break;
    case 2:
        printf("Enter the number :");
        scanf("%d",&x);
        addLast(&head,x);
        break;
    case 3:
        printf("Enter the number :");
        scanf("%d",&x);
        addSorted(&head,x);
        break;
    case 4:
        printf("Enter the number :");
        scanf("%d",&x);
        printf("Enter the position :");
        scanf("%d",&pos);
        addAt(&head,x,pos);
        break;
    case 5:
        printf("Length of LinkedList %d\n",getLength(head));
        break;
    case 6:
        printf("Enter the number to Search :");
        scanf("%d",&x);
        search(head,x);
        break;

    case 7:
        printf("Enter the number to Delete :");
        scanf("%d",&x);
        deleter(&head,x);
        break;

    case 8:
        traverse(head);
        break;
    case 9:
        reverse(&head);
        break;
    case 10:
        printf("Enter the number to Search :");
        scanf("%d",&x);
        search2(head,x);
        break;
    case 11:
        printf("Enter the number to know last position :");
        scanf("%d",&x);
        position(head,x);

    default:
        break;
    }
    }
    return 0;
}
void addFirst(node **head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->data=val;
    p->next=NULL;


    p->next=*head;
    *head=p;


}
void addLast(node **head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->data=val;
    p->next=NULL;
    if (*head ==NULL)
    {
        *head=p;
        return;
    }

    node *temp;
    temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;

}
void addSorted(node **head, int val)
{
    node *p = (node*)malloc(sizeof(node));
    p->data=val;
    p->next=NULL;
    if (*head==NULL)
    {
        *head=p;
        return;
    }
    node * temp1;
    temp1=*head;
    node* temp2;
    temp2=(*head)->next;
    if ((*head)->data > val)
    {
        p->next= (*head);
        *head=p;
        return;
    }


    while(temp2 !=NULL && temp2->data < val)

    {
        printf("hi");
        temp1=temp1->next;
        temp2=temp2->next;

    }
    temp1->next=p;
    p->next=temp2;


}
void traverse(node *head)
{
    while(head!=NULL)
    {
        printf("%d  ",head->data);
        head=head->next;
    }
    printf("\n");
}
int getLength(node* head)
{
    int length =0;

    while(head !=NULL)
    {
        length++;
        head=head->next;
    }
    return length;
}
void addAt(node ** head,int val, int pos)
{
    node *p = (node*)malloc(sizeof(node));
    p->data=val;
    p->next=NULL;
    int length=getLength((*head));
    printf("%d lenght",length);
    if (length<pos)
    {
        printf("Can't add to linked lisnt");
        return;
    }
    if(pos == 0)
    {
        p->next=*head;
        *head=p;
        return;
    }
    node *temp1;
    temp1=*head;
    node * temp2;
    temp2 =(*head)->next;
    int count=1;
    while(count < pos)
    {
        count++;
        temp1=temp1->next;
        temp2=temp2->next;

    }
    temp1->next=p;
    p->next=temp2;


}

void search(node* head,int data)
{
 while ((head)!=NULL)
 {
     if(head->data==data)
     {
         printf("Found the Number \n");
         return;
     }
     head=head->next;
 }
 printf("not found");
}


void deleter(node** head,int data)
{
    node* p;
    node* q;
if((*head)==NULL)//Zero nodes
    return;
if((*head)->data==data)//Data at first node
{
    p=*head;
    (*head)=(*head)->next;
    free(p);
    return;

}
p=(*head);
if(p->next==NULL)
    return;
//At least 2 nodes
q=p->next;
while(q->data!=data && q->next!=NULL)
{
    p=q;
    q=q->next;

}
if(q->data==data)
{
    p->next=q->next;
    free(q);

}




{


}
}

void reverse(node** head)
{
    node* p;
    node* q;
    node* r;
  if((*head)==NULL)//Zero nodes
    return;
   if((*head)->next==NULL)
    return;
    p=*head;
    q=p->next;
    if(q->next==NULL)
    {
        *head=q;
        q->next=p;
        p->next=NULL;
        return;
    }
    r=q->next;
    while(r->next!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }
        q->next=p;
        r->next=q;
        (*head)->next=NULL;
        *head=r;
}


void search2(node* head,int data)
{
    int count=0;
   while (head !=NULL)
 {
     if(head->data==data)
     {

        count++;
     }
     head=head->next;
 }
printf(" - %d times",count);
}


int position(node* head,int data)
{

    int pos=0;
 while ((head)!=NULL)
 {
     if(head->data==data)
     {

         return pos;
     }
     pos++;
     head=head->next;
 }
 return -1;

}
