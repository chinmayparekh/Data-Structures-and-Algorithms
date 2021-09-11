#include <bits/stdc++.h>
using namespace std;

struct List
{
  long long int i;
  long long int w;
  struct List *next;
};



struct List *
newedge (struct List *node, long long int i, long long int w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}
void
MaxBottomupheapify (long long int H[], long long int A[],long long int B[],long long int i)
{
  long long int p = (i - 1) / 2, t;
  long long int temp;

  while (p > -1)
    {
      if (H[i] > H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  t = A[i];
	  A[i] = A[p];
	  A[p] = t;
	  B[A[p]] = p;
	  B[A[i]] = i;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
MaxTopdownheapify (long long int H[],long long int A[],long long int B[],long long int i, long long int n)
{
  long long int c, t;
  long long int temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] > H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] < H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = A[i];
	  A[i] = A[c];
	  A[c] = t;
	  B[A[i]] = i;
	  B[A[c]] = c;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] < H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[i]] = i;
      B[A[c]] = c;
      i = c;
    }

}

// void
// MaxAdd (long long int H[], long long int A[], long long int B[], long long int X, long long int *n)
// {

//   H[*n] = X;
//   A[*n] = *n;
//   B[A[*n]] = *n;
//   *n = *n + 1;

//   MaxBottomupheapify (H, A, B, *n - 1);
// }

void
DeleteMax (long long int H[], long long int A[], long long int B[], long long int *n)
{
  long long int t1;
  long long int  t;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = A[0];
  A[0] = A[*n];
  A[*n] = t1;
  B[A[0]] = 0;
  B[A[*n]] = *n;
  MaxTopdownheapify (H, A, B, 0, *n);
}

// void
// MaxBuildHeap (long long int H[], long long int A[], long long int B[], long long int n)
// {

//   long long int i = n / 2;
//   while (i > -1)
//     {
//       MaxTopdownheapify (H, A, B, A[i--], n);
//     }

// }

// void
// Bottomupheapify (long long int H[], long long int A[], long long int B[], long long int i)
// {
//   long long int p = (i - 1) / 2, t;
//   long long temp;

//   while (p > -1)
//     {
//       if (H[i] < H[p])
// 	{
// 	  temp = H[i];
// 	  H[i] = H[p];
// 	  H[p] = temp;
// 	  t = A[i];
// 	  A[i] = A[p];
// 	  A[p] = t;
// 	  B[A[i]] = i;
// 	  B[A[p]] = p;
// 	  i = p;
// 	  p = (i - 1) / 2;

// 	}

//       else
// 	p = -1;
//     }

// }

void
Topdownheapify (long long int H[], long long int A[], long long int B[], long long int i, long long int n)
{
  long long int c, t;
  long long int temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] < H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] > H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = A[i];
	  A[i] = A[c];
	  A[c] = t;
	  B[A[c]] = c;
	  B[A[i]] = i;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] > H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[c]] = c;
      B[A[i]] = i;
      i = c;
    }

}

// void
// Add (long long int H[], long long int A[], long long int B[], long long int X, long long int *n)
// {

//   H[*n] = X;
//   A[*n] = *n;
//   B[A[*n]] = *n;
//   *n = *n + 1;

//   Bottomupheapify (H, A, B, *n - 1);
// }

// void
// DeleteMin (long long int H[], long long int A[], long long int B[], long long int *n)
// {
//   long long int t;
//   long long int t1;
//   *n = *n - 1;
//   t = H[0];
//   H[0] = H[*n];
//   H[*n] = t;
//   t1 = A[0];
//   A[0] = A[*n];
//   A[*n] = t1;
//   B[A[0]] = 0;
//   B[A[*n]] = *n;
//   Topdownheapify (H, A, B, 0, *n);
// }

void
BuildHeap (long long int H[], long long int A[], long long int B[], long long int n)
{

  long long int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, A, B, i--, n);

    }

}

// void
// DecreaseKey (long long int H[], long long int A[], long long int B[], long long int i, long long int X)
// {

//   H[i] = X;

//   Bottomupheapify (H, A, B, i);


// }

void
IncreaseKey (long long int H[], long long int A[], long long int B[], long long int i, long long int X)
{

  H[i] = X;

  MaxBottomupheapify (H, A, B, i);


}
void
PrimsMax (struct List *list[], long long int s, long long int n)
{
  long long int A[200000], B[200000];
  struct List *node;
  long long int H[200000], mst = 0;
  long long int i, u, v, m = n;
  bool V[n];
  long long int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MIN;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
  Phi[s] = -1;
  A[0] = s;
  A[s] = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H[0] > INT_MIN; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMax (H, A, B, &m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H[B[v]] < node->w)
	    {
	      IncreaseKey (H, A, B, B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  for (i = 0; i < n; ++i)
    mst += H[B[i]];

  printf ("%lli\n", mst);
}
int main()
{
  long long int n,m,i,u,v,w;
  scanf("%lli %lli",&n,&m);
  struct List *list[n+1];
  for(i=0;i<m;i++)
  {
    scanf("%lli %lli %lli",&u,&v,&w);
    list[u-1]=newedge(list[u-1],v-1,w);
    list[v-1]=newedge(list[v-1],u-1,w);
  }
  PrimsMax(list,0,n);
  return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// struct graph{
//   long long int u;
//   long long int v;
//   long long int w;
// };

// bool compare(graph a,graph b)
// {
//   if(a.w>b.w)
//     return false;
//   else
//     return true;
// }

// long long int find(long long int a,long long int parent[])
// {
//   if(parent[a]==-1)
//     return a;
//   else
//     return parent[a]=find(parent[a],parent);
// }

// int main()
// {
//   long long int n,m,u,v;
//   cin>>n>>m;
//   graph arr[m];
//   long long int parent[n+1];
//   for(int i=0;i<=n;i++)
//   {
//     parent[i]=-1;
//   }
//   for(int i=0;i<m;i++)
//   {
//     long long int a,b,cost;
//     cin>>a>>b>>cost;
//     arr[i].u=a;
//     arr[i].v=b;
//     arr[i].w=-cost;
//   }
//   long long int sum=0;
//   sort(arr,arr+m,compare);

//   for(int i=0;i<m;i++)
//   {
//     u=find(arr[i].u,parent);
//     v=find(arr[i].v,parent);

//     if(u!=v)
//     {
//       sum+=arr[i].w;
//       parent[u]=v;
//     }
//   }
//   cout<<-sum<<endl;
//   return 0;

// }

