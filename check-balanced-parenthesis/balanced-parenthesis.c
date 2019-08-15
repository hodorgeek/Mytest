

#include <stdio.h>
#include <stdlib.h>


struct sNode 
{ 
    char data; 
    struct sNode* next; 
}; 


void push(struct sNode** top_ref, char data);

void pop(struct sNode** top_ref);

char peek(struct sNode** top_ref);

int isEmpty(struct sNode* top_ref);

void display(struct sNode** top_ref);


int main(int argc, char ** argv)
{
    
    if(argc != 2) 
    {
        printf("Wrong number of command line arguments passed\n");
        exit(-1);
    }

    FILE *fp = NULL;
    char ch;
    // at 1st location will be filePath which we want to read
    char *filePath = argv[1];
    
    fp = fopen(filePath, "r");

    if(fp == NULL)
    {
        printf("Could not open file %s\n", filePath);
        exit(-1);
    }

    // created 4 separate stack of character for storing different types of parenthesis
    struct sNode *round_bracket_stack = NULL; // '('
    struct sNode *curly_bracket_stack = NULL; // '{' 
    struct sNode *square_bracket_stack = NULL; // "["
    struct sNode *angular_bracket_stack = NULL;  // '<' 

    while((ch = fgetc(fp)) !=EOF)
    {

        if (ch == '(') {
            push(&round_bracket_stack, ch);
        } else if(ch == '{') {
            push(&curly_bracket_stack, ch);
        } else if(ch == '[') {
            push(&square_bracket_stack, ch);
        } else if(ch == '<') {
            push(&angular_bracket_stack, ch);
        }

        if(ch == ')') {
            pop(&round_bracket_stack);
        } else if(ch == '}') {
            pop(&curly_bracket_stack);
        } else if(ch == ']') {
            pop(&square_bracket_stack);
        } else if(ch == '>') {
            pop(&angular_bracket_stack);
        }
    }

    // printf("round bracket stack : ");
    // display(&round_bracket_stack);
    
    // printf("\ncurly bracket stack : ");
    // display(&curly_bracket_stack);

    // printf("\nsquare bracket stack : ");
    // display(&square_bracket_stack);

    // printf("\nangular bracket stack : ");
    // display(&angular_bracket_stack);

    if(isEmpty(round_bracket_stack) && isEmpty(curly_bracket_stack) && isEmpty(square_bracket_stack) && isEmpty(angular_bracket_stack))
    {
        printf("\n Balance --> Given file have balanced parenthesis\n\n");
    } 
    else 
    {
        printf("\n Not Balanced --> Given file does not have balanced parenthesis\n\n");
    }

    // remember to close the file after performing operation.
    fclose(fp);
    return 0;
}


// Utility function to add an element data in the stack insert at the beginning 
void push(struct sNode** top_ref, char ch) 
{ 

    // struct sNode *new_node = (struct sNode*) calloc(1, sizeof(struct sNode)); // allocates 1 unit memory of size of structure
     struct sNode* new_node = (struct sNode*) malloc(sizeof(struct sNode));
    
    if (new_node == NULL)
    {
        printf("Stack overflow n");
        getchar();
        exit(-1);
    }
    
    new_node->data = ch;
    new_node->next = (*top_ref);
    (*top_ref) = new_node;
} 
  
// Utility function to check if the stack is empty or not 
int isEmpty(struct sNode* top) 
{ 
    return top == NULL; 
} 
  

// Utility function to pop top element from the stack 
void pop(struct sNode** top_ref) 
{ 
    struct sNode* top = (*top_ref);
  
    if (isEmpty(top)) 
    { 
        printf("\nStack Underflow\n"); 
        exit(1); 
    } 
    else 
    { 
        struct sNode* temp = top;
        top = top->next;
        (*top_ref) = top;
        temp->next = NULL; 
        free(temp);
    } 
} 
  
// Function to print all the  
// elements of the stack  
void display(struct sNode** top_ref)  
{ 
    struct sNode* temp = (*top_ref); 
  
    // check for stack underflow 
    if (isEmpty(temp)) 
    { 
        printf("\nStack Underflow"); 
        // exit(1); 
    } 
    else 
    { 
        while (temp != NULL) 
        { 
            // print sNode data 
            printf("%c ",temp->data); 

            // assign temp next to temp 
            temp = temp->next; 
        } 
    } 
 }

 // Utility function to return/examine top element in a stack 
char peek(struct sNode** top_ref) 
{ 
    // check for empty stack 
    struct sNode *top = (*top_ref);
    if (!isEmpty(top)) 
    {
        return top->data; 
    } else{
        printf("\nStack Underflow\n"); 
        exit(1); 
    }
    
} 
