#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define NODESIZE 100
struct node_t{
	struct node_t * left;
	struct node_t * right;
	int value;
};

struct node_t *string2tree(char *string)
{
   int i=0;
   int len = strlen(string);
   struct node_t *root;
   root=(struct node_t *)malloc(len * sizeof(struct node_t));
   for (i = 0; i<len; i++) {
       root[i].value = string[i]-'0';
	   if( 2*i + 2 <= len){
           root[i].left = &root[2*i+1];
           root[i].right = &root[2*i+2];
	   }else{
           root[i].left = NULL;
           root[i].right = NULL;
	   }
   }
   return root;
}

char *tree2string(struct node_t *root)
{
    int i=0; 
	char *string=malloc(sizeof(char));
	queue value_queue;
	init_queue(&value_queue);
	enqueue(&value_queue, root->value);
	while(!empty(&value_queue)){
		int value = dequeue(&value_queue);
	    *(string+i) = value +'0';
		if (root[i].left != NULL)
	        enqueue(&value_queue, root[i].left->value);
		if (root[i].right != NULL)
	        enqueue(&value_queue, root[i].right->value);
		i++;
	}
    return string;
}

int main(int argc, char* argv[])
{
    char* string;
    struct node_t *root=string2tree("9235412");	
    string = tree2string(root);	
    printf("%s\n", string);
}
