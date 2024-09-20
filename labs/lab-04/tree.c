#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TNode{
  char* val;
  struct TNode* left;
  struct TNode* right;
} TNode;

TNode* makeEmptyTree()
{
   return NULL;
}

TNode* insertIntoTree(TNode* root,char* string)
{
  if(root == NULL) {
    TNode* newNode = (TNode*)malloc(sizeof(TNode)); // allocate for newnode size
    newNode->val = strdup(string);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
  }

  int compare = strcmp(string, root->val);
  if (compare < 0) {
    root->left = insertIntoTree(root->left, string);
  } else if (compare > 0) {
    root->right = insertIntoTree(root->right, string);
  }

  return root;

}

TNode* searchTree(TNode* root, char* string)
{
  if(root == NULL){
    return NULL; // this is our base case
  }

  int compare = strcmp(string, root->val);
  if(compare == 0) {
    return root;
  } else if( compare < 0) {
    return searchTree(root->left, string);
  } else {
    return searchTree(root->right, string);
  }
}

void printTree(TNode* root)
{
   if (root == NULL)
      return;
   else {
      printf("(");
      printTree(root->left);
      printf(" %s ",root->val);
      printTree(root->right);
      printf(")");      
   }
}

void destroyTree(TNode* root)
{
  if(root == NULL) {
    return;
  }

    destroyTree(root->left);
    destroyTree(root->right);
    free(root->val);
    free(root);
}




int main(int argc, char* argv[])
{
  if(argc != 2){
    printf("Usage: ./tree wordList\n");
    return 1;
  }
  TNode* tree = makeEmptyTree();
  FILE* file = fopen(argv[1], "r");
  if(file == NULL) {
    // error opening file
    return 1;
  }
  char word[200];
  size_t length;
  
  while(fscanf(file, "%199s", word) == 1) {
    tree = insertIntoTree(tree, word);
  }

  fclose(file);

  while(1){
    printf("word: ");
    int r = scanf("%s", word);
    if(r != 1)
      break;
    length = strlen(word);
    if(length < 1)
      break;
    TNode* node = searchTree(tree, word);
    if(node){
      printf("PRESENT\n");
    }else{
      printf("ABSENT\n");
    }    
  }
  destroyTree(tree);
  return 0;
}
