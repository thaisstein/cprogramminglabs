#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

typedef struct Node {
    char *word;
    int count;
    struct Node *next; // pointer to struct Node
} Node;

typedef Node * p_node; 

p_node create () {
    return NULL;
}

void destroy (p_node list) {
    if (list != NULL) {
        destroy(list->next);
        free(list);
    }
}

p_node add(p_node wordlist, char *word) {
    p_node temp = *wordlist;
    while (temp->next != NULL) { //goes through the list
        if(strcmp (temp->word, word) == 0) {
            temp->count +=1;
            return *wordlist;
        }
        else {
            temp = temp->next;
        }
    }
        p_node new = create();
        if(NULL != new) {
            temp->next = new;
        }
        return new;
}

void print(p_node list) {
    if(list != NULL) {
        printf("%c", "%d", list->word, list->count);
        print(list->next);
    }
}

int main (int argc, char *argv[]) {

    p_node list;
    list = create(); //creates an empty list

    FILE *myFile;
    FILE *myOutput;

    /* transforms input file into a char */
    char *filename = argv[1];
    char *outputfile = argv[2];
    if (argc != 3) {
        fprintf (stderr, "error: insufficient input. usage: %s ifile ofile\n",
                argv[0]);
        return 1;
    }
    else {
        printf("file opened \n")
    }
    myFile = fopen (filename, "r");    
    assert(myFile);
    fseek(myFile,0,SEEK_END);
    long lenght = ftell(myFile);
    fseek(myFile, 0, SEEK_SET);
    char *wordchar = (char*) malloc(lenght + 1);
    wordchar[lenght] = '\0';
    fread(wordchar,1,lenght, myFile);
    fclose(myFile);
    printf("%s", wordchar);
      /* finished */
    char currword[100];
      while(*wordchar) {
          currword[k] = *wordchar;
          if(*wordchar == ' ' || *str == '\n' || *str == '\t') {
              state = OUT;
          }
          else if (state == OUT) {
              state = IN;
              list = add(list, word)

          }

      }

    

    return 0;
}
