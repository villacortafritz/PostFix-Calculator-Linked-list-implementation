#ifndef POSTFIX_H
#define POSTFIX_H

typedef enum{false, true} boolean;
typedef float listItem;
typedef struct node *nodeptr;
struct node {
	listItem item;
	nodeptr next;
};
typedef nodeptr Post;

Post newFix();
void destroyStack(Post *p);
void display(Post p);
void clear (Post p);
void push(Post p, listItem string);
void pop(Post p);
boolean isEmpty(Post p);
double peek(Post p);
double check(char data[], int *errorcode);


#endif
