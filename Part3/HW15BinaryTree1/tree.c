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

TreeNode* newNode = (int value)
{
  TreeNode * node = (TreeNode*)malloc(sizeof(Treenode));
  node -> value = value;
  node -> right = NULL;
  node -> left = node -> right;
  return (node);
}

int search (int * in, int first, int last, int value)
{
  int i;
  for (i = first; i <= last, i++)
  {
    if (in[i] == value)
      break;
  }
  return i;
}


TreeNode* buildHelper(int * in, int * post, int first, int last, int * postIndex)
{
  if (first > last)
    return NULL;
  TreeNode * node = newNode(post[*postIndex]);
  (*postIndex)--;

  if (first == last)
    return node;
  int indexVal = search(in, first, last, node->value);

  node->right = buildHelper(in, post, indexVal + 1, last, postIndex);
  node->left = buildHelper(in, post, first, indexVal - 1, postIndex);
  
  return node;

Tree * buildTree(int * inArray, int * postArray, int size)
{
  int postIndex = size - 1;
  return buildHelper(inArray, postArray, 0, size-1, &postIndex);

}
#endif
