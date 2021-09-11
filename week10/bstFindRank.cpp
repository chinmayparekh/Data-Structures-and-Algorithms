#include <bits/stdc++.h>
using namespace std;

struct BST
{
  long long int key;
  int height;
  long long int count;
  struct BST *left, *right, *parent;
};

struct BST * newNode (long long int key)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = key;
  temp->left = temp->right = temp->parent = NULL;
  temp->height = 0;
  temp->count = 1;
  return temp;
}

int Max (int x, int y)
{
  if (x < y)
    return y;
  else
    return x;
}

int Height (struct BST *node)
{
  if (node)
    {
      if (node->left && node->right)
	return 1 + Max (node->left->height, node->right->height);

      else if (node->left)
	return 1 + node->left->height;
      else if (node->right)
	return 1 + node->right->height;
      else
	return 0;

    }

  else
    return -1;
}

long long int Count (struct BST *node)
{
  if (node)
    {
      if (node->left && node->right)
	return 1 + node->left->count + node->right->count;

      else if (node->left)
	return 1 + node->left->count;
      else if (node->right)
	return 1 + node->right->count;
      else
	return 1;

    }

  else
    return 0;
}

bool AVL (struct BST * node)
{
  if (abs (Height (node->left) - Height (node->right)) < 2)
    return true;
  else
    return false;
}
struct BST * Search (struct BST *node, long long int X)
{

  while (node)
    {
      if (X == node->key)
	return node;
      else if (X < node->key)
	node = node->left;
      else
	node = node->right;
    }
  return NULL;
}

struct BST * FindRank (struct BST *node, long long int rank)
{
  long long int r;
  if (node && rank > 0 && rank < node->count + 1)
    {
      while (node)
	{
	  if (node->right)
	    r = node->right->count + 1;
	  else
	    r = 1;
	  if (r == rank)
	    return node;
	  else if (rank > r)
	    {
	      node = node->left;
	      rank = rank - r;
	    }
	  else
	    node = node->right;
	}
    }
  return NULL;
}

long long int Rank (struct BST *node, long long int X)
{
  long long int rank = 1;

  while (node)
    {
      if (X == node->key)
	{
	  if (node->right)
	    rank += node->right->count;
	  return rank;
	}
      else if (X < node->key)
	{
	  rank++;
	  if (node->right)
	    rank += node->right->count;
	  node = node->left;
	}
      else
	node = node->right;
    }
  return rank;
}


void Rotate (struct BST **node, struct BST *Z)
{
  struct BST *X, *Y, *T1, *T2, *T3, *T4;
  int c = 0;
  if (Height (Z->left) + 1 == Z->height)
    Y = Z->left;
  else
    {
      Y = Z->right;
      c++;
    }
  c = c * 2;
  if (Height (Y->left) + 1 == Y->height)
    X = Y->left;
  else
    {
      X = Y->right;
      c++;
    }

  if (c == 0)
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = Y;
	  else
	    Z->parent->right = Y;
	}
      else
	{
	  *node = Y;
	}
      T3 = Y->right;
      Y->right = Z;
      Z->left = T3;
      Y->parent = Z->parent;
      Z->parent = Y;
      if (T3)
	T3->parent = Z;

      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Z->count = Count (Z);
      X->count = Count (X);
      Y->count = Count (Y);
    }
  else if (c == 3)
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = Y;
	  else
	    Z->parent->right = Y;
	}
      else
	{
	  *node = Y;
	}

      T2 = Y->left;
      Y->left = Z;
      Z->right = T2;
      Y->parent = Z->parent;
      Z->parent = Y;
      if (T2)
	T2->parent = Z;
      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Z->count = Count (Z);
      X->count = Count (X);
      Y->count = Count (Y);

    }
  else if (c == 1)
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = X;
	  else
	    Z->parent->right = X;
	}
      else
	{
	  *node = X;
	}
      T2 = X->left;
      T3 = X->right;
      Y->right = T2;
      Z->left = T3;
      X->parent = Z->parent;
      Z->parent = X;
      Y->parent = X;
      if (T2)
	T2->parent = Y;
      if (T3)
	T3->parent = Z;
      X->left = Y;
      X->right = Z;

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Z->count = Count (Z);
      Y->count = Count (Y);
      X->count = Count (X);
    }
  else
    {
      if (Z->parent)
	{
	  if (Z->parent->left == Z)
	    Z->parent->left = X;
	  else
	    Z->parent->right = X;
	}
      else
	{
	  *node = X;
	}

      T2 = X->left;
      T3 = X->right;
      Y->left = T3;
      Z->right = T2;
      X->parent = Z->parent;
      Z->parent = X;
      Y->parent = X;
      if (T2)
	T2->parent = Z;
      if (T3)
	T3->parent = Y;
      X->left = Z;
      X->right = Y;
      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Z->count = Count (Z);
      Y->count = Count (Y);
      X->count = Count (X);

    }


}
void Insert (struct BST **node, long long int key)
{
  if (!Search (*node, key))
    {
        struct BST *temp = *node;
        // If the BST is empty, create a  new BST
        if (!*node)
          *node = newNode (key);

        else
        {
          bool flag = true;
          // struct BST *temp = *node;

          while (flag)
          {
            temp->count++;
            if (key < temp->key)

            if (temp->left)
              temp = temp->left;
            else
              {
                temp->left = newNode (key);
                temp->left->parent = temp;
                flag = false;
              }
            else if (key > temp->key)
            {
              if (temp->right)
                temp = temp->right;
              else
                {
                  temp->right = newNode (key);
                  temp->right->parent = temp;
                  flag = false;
                }

            }
            else
              flag = false;

          }			
      flag = true;
      int h;

      while (flag)
        {
          h = Height (temp);
          if (h > temp->height)
        {
          temp->height = h;
          if (!AVL (temp))
            {
              Rotate (&*node, temp);
              flag = false;
            }
          else if (temp->parent)
            temp = temp->parent;
          else
          {
            flag = false;
          }
        }
          else
            flag = false;
        }


        } 			//end of else
    }				//end of Insert
}

int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];
    struct BST *root=NULL;
    for(int i=0;i<n;i++)
    {
        Insert(&root,a[i]);
        int x=(i+1)-(Rank(root,a[i])+b[i]);
        if(x<0)
            cout<<"-1 ";
        else   
        {
            int k=Rank(root,a[i]);
            int finalrank=k+b[i];
            cout<<FindRank(root,finalrank)->key<<" ";
        }
    } 
            
    cout<<endl;
    return 0;
}