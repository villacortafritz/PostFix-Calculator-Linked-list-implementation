#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "postfix.h"

nodeptr create(listItem item){
	nodeptr p;
	p = (nodeptr)malloc(sizeof(struct node));
	p->item = item;
	p->next = NULL;
	return p;
}
Post newFix(){
	Post m = create(0);
	return m;
}
void push(Post p, listItem string){
	nodeptr temp = create(string);
	temp->next= p->next;
	p->next = temp;
}
void pop(Post p){
	nodeptr d= p->next;
	if(p!=NULL){
		p->next= d->next;
		free(d);
	}
}
void display(Post p){
	nodeptr d = p->next;
	printf("[");
	while(d!=NULL){
		printf("%c ", d->item);
		d = d->next;
	}
	printf("]");
}
void clear (Post p){
	while(p->next!=NULL){
		nodeptr d = p->next;
		if(d!=NULL){
			p->next = d->next;
			free(d);
		}
	}
}
void destroyStack(Post *p){
	free(*p);
	*p = NULL;
}
boolean isEmpty(Post p){
	boolean flag = true;
	if(p->next!=NULL){
		flag = false;
	}
	return flag;
}
double peek(Post p){
	float item=0.0;
	if(!isEmpty(p)){
		nodeptr d=p->next;
		item=d->item;
	}
	return item;
}
double check(char st[], int *errorcode){
	Post p = newFix();
	const char delim[2]=" ";
	float temp1=0.0, temp2=0.0;
	char* token;
	
	token=strtok(st, delim);
	while(token!=NULL){
		switch(*token){
			case'+':
				if(!isEmpty(p)){
					temp1=peek(p);
					pop(p);
					if(!isEmpty(p)){
						temp2=peek(p);
						pop(p);
						push(p, temp1+temp2);
					}
					else{
						*errorcode=2;
					
					}
				}
				else{
					*errorcode=2;

				}
				break;
			case'-':
				if(!isEmpty(p)){
					temp1=peek(p);
					pop(p);
					if(!isEmpty(p)){
						temp2=peek(p);
						pop(p);
						push(p, temp2-temp1);
					}
					else{
						*errorcode=2;
					
					}
				}
				else{
					*errorcode=2;

				}
				break;
				
			case'/':
				if(!isEmpty(p)){
					temp1=peek(p);
					pop(p);
					if(!isEmpty(p)){
						temp2=peek(p);
						pop(p);
						push(p, temp2/temp1);
					}
					else{
						*errorcode=2;
					
					}
				}
				else{
					*errorcode=2;

				}
				break;
			case'*':
				if(!isEmpty(p)){
					temp1=peek(p);
					pop(p);
					if(!isEmpty(p)){
						temp2=peek(p);
						pop(p);
						push(p, temp1*temp2);
					}
					else{
						*errorcode=2;
			
					}
				}
				else{
					*errorcode=2;

				}
				break;
			default:
				push(p, atof(token));
			
		}
		token = strtok(NULL,delim);
	}
	if(peek(p)!=0){
		temp1=peek(p);
		pop(p);		
	}
	
	if(!isEmpty(p)){
		*errorcode =3;
	}
	
	destroyStack(&p);
	return temp1;
}
