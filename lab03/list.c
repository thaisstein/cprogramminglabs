#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

/* The following lab was made to count the number of words that are present
in a given text, using the linked lists data structure. Its main function has two
arguments: the input file and the output file. The last one contais the results 
of the word counting dictionary. */

/* Defines the node */
typedef struct Node {
    char *word;
    int count;
    struct Node *next; // Pointer to struct Node
} Node;
typedef Node * p_node; 

/* Creates an empty list */
p_node create () {
    return NULL;
}

/* Destroys list */
void destroy (p_node list) {
    if (list != NULL) {
        destroy(list->next);
        free(list);
    }
}

/* Adds non repeated word into list */
p_node add(p_node wordlist, char *word) {
    p_node current;
    int exists = 0;
    /* Goes though the words and sees if the word being added exists */
    for (current = wordlist; current != NULL; current = current->next) {
        if(strcmp(current->word, word) == 0) {
            current->count +=1;
            exists = 1;
        }
    }
    if(exists == 0) {
        p_node new;
        new = malloc(sizeof(Node));
        new->word = word;
        new->count = 1;
        new->next = wordlist;
        return new;
    }
        return wordlist;
    }

/* Prints list */
void print(p_node list) {
    p_node current;
    for(current = list; current != NULL; current = current->next) {
        printf("%s: ", current -> word);
        printf("%d\n", current -> count);
    }
}

/* Transforms the text into all lowercase */
char* to_lower(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}

int main (int argc, char *argv[]) {
    p_node list;
    list = create(); 

    FILE *myFile;
    FILE *myOutput;

    /* Transforms input file into a char */
    char *filename = argv[1];
    char *outputfile = argv[2];
    myFile = fopen (filename, "r");    
    assert(myFile);
    fseek(myFile,0,SEEK_END);
    long lenght = ftell(myFile);
    fseek(myFile, 0, SEEK_SET);
    char *wordchar = (char*) malloc(lenght + 1);
    wordchar[lenght] = '\0';
    fread(wordchar,1,lenght, myFile);
    fclose(myFile);
    to_lower(wordchar);

    /* Iterates though the characters of the char*/
    char delimiter[] = ",;:. \n!\"'"; 
    char *token = strtok(wordchar, delimiter);
    while (token != NULL) {
      list = add(list, token);
      token = strtok(NULL, delimiter);
    }
    print(list);
    
    /* Writes output file */
    myOutput = fopen(outputfile, "w");
    p_node current;
    for(current = list; current != NULL; current = current->next) {
        fprintf(myOutput, "%s: ", current -> word);
        fprintf(myOutput, "%d\n", current -> count);
    }
    fclose(myOutput);
    
    /* Freeing memory */
    destroy(list);
    free(wordchar);
    return 0;
}
