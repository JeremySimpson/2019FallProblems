// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/

TreeNode* newNode(int value)
{
  TreeNode * addedNode = (TreeNode*)malloc(sizeof(TreeNode));
  addedNode -> value = value;
  addedNode -> right = NULL;
  addedNode -> left = NULL;
  return (addedNode);
}

int search (int * inArray, int first, int last, int value)
{
  int i;
  int index;
  for (i = first; i <= last; i++)
  {
    if (inArray[i] == value)
      index = i;
  }
  return index;
}


TreeNode* buildHelper(int * inArray, int * postArray, int first, int last, int * postIndex)
{
  if (first > last)
    return NULL;

  TreeNode * addedNode = newNode(postArray[*postIndex]);
  (*postIndex)--;

  if (first == last)
    return addedNode;

  int indexVal = search(inArray, first, last, addedNode->value);

  addedNode->right = buildHelper(inArray, postArray, indexVal + 1, last, postIndex);
  addedNode->left = buildHelper(inArray, postArray, first, indexVal - 1, postIndex);
  
  return addedNode;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tr = malloc(sizeof(Tree));
  int postIndex = size - 1;
  tr -> root = buildHelper(inArray, postArray, 0, size-1, &postIndex);

  return tr;

}
#endif
