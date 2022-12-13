//
//  main.c
//  dslk
//
//  Created by Nguyễn Trung on 13/12/2022.
//

#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
 
struct node
{
    char s[100];
    int cnt;
    struct node *next;
};
typedef struct node node;
node *makeNode(char a[])
{
    node *newNode=(node*)malloc(sizeof(node));
    strcpy(newNode->s, a);
    newNode->cnt=1;
    newNode->next=NULL;
    return newNode;
}
void pushBack(node**head,char a[])
{
    node* newNode=makeNode(a);
    if(*head==NULL)
    {
        *head=newNode;
        return;
    }
    node*temp=*head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    
}
int dem(node *head)
{
    int cnt=0;
    while(head!=NULL)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
}
void duyet(node *head)
{
    while(head!=NULL)
    {
        printf("%s %d\n",head->s,head->cnt);
        head=head->next;
        
    }
}
int main()
{
    char s[100];
    node *head=NULL;
    
    while(scanf("%s",s)==1)
    {
        
        int check=1;
        for(node *temp=head;temp!=NULL;temp=temp->next)
        {
            if(strcmp(temp->s, s)==0)
            {
                (temp->cnt)++;
                check=0;
                break;
            }
        }
        if(check)
        {
            pushBack(&head, s);
        }
    }
    duyet(head);
    return 0;
    
}
