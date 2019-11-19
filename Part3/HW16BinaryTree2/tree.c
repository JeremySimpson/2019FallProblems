// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

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


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
TreeNode* buildHelper(int * inArray, int * postArray, int first, int last, int * postIndex)
{
  if (first > last)
    return NULL;

  int value = postArray[*postIndex];
  TreeNode * addedNode = (TreeNode*)malloc(sizeof(TreeNode));
  addedNode -> value = value;
  addedNode -> right = NULL;
  addedNode -> left = NULL;
  (*postIndex)--;

  if (first == last)
    return addedNode;

  int indexVal;
  int i;

  for (i = first; i <= last; i++)
  {
    if (inArray[i] == addedNode -> value)
      indexVal = i;
  }

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

#ifdef TEST_PRINTPATH
printPathHelper(TreeNode* node, int val, int tempArray[], int pathIndex)
{
  if (node == NULL)
    return;
  tempArray[pathIndex] = node -> value;
  if (node -> value == val)
  {
    int tempIndex;
    for (tempIndex = pathIndex; tempIndex >= 0; tempIndex--)
    {
      printf("%d\n",tempArray[tempIndex]);
      
    }
  }

  pathIndex++;

  else
  {
    printPathHelper(node->left, val, tempArray, pathIndex);
    printPathHelper(node->right, val, tempArray, pathIndex);
  } 
}

void printPath(Tree * tr, int val)
{
  int tempArray[1000];
  int pathIndex = 0;
  TreeNode* rootNode = tr -> root;
  printPathHelper(rootNode, val, tempArray, pathIndex);
}
#endif
