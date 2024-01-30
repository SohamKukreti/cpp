#include<bits/stdc++.h>
using namespace std;
class node{
  public:
  int data;
  node*right;
  node*left;
  int bf;
  node(int data)
  {
    this->data=data;
    this->left=NULL;
    this->right=NULL;
    this->bf=0;
  }
};
int height(node*root)
{
  if(root==NULL)
  return 0;
  return max(height(root->right),height(root->left))+1;
}
void LevelOrderTraversal(node*root)
{
  queue<node*>q;
  q.push(root);
  while(!q.empty())
  {
    int size=q.size();
    while(size--)
    {
node*temp=q.front();
q.pop();
if(temp==NULL)
cout<<"0  ";
else{
cout<<temp->data<<" ";
if(temp->left)
q.push(temp->left);
else
q.push(NULL);
if(temp->right)
q.push(temp->right);
else
q.push(NULL);
    }

  }
   cout<<endl;
}
  }
node* leftrotation(node*root)
{
  node*x=root->right;
   node*y=x->left;
   x->left=root;
   root->right=y;
  x->bf=height(x->left)-height(x->right);
    root->bf=height(root->left)-height(root->right);
   return x;
}
node*rightrotation(node*root)
{
node*x=root->left;
   node*y=x->right;
   x->right=root;
   root->left=y;
 x->bf=height(x->left)-height(x->right);
    root->bf=height(root->left)-height(root->right);
   return x;
}
node*LeftRight(node*root)
{
root->left=leftrotation(root->left);
return rightrotation(root);
}
node* RightLeft(node*root)
{
  root->right=rightrotation(root->right);
return leftrotation(root);

}
  void balance(node*& root, int data) {
    if (root->bf > 1 && data < root->left->data) {
        // LL case
        root = rightrotation(root);
    }
    else if (root->bf < -1 && data > root->right->data) {
        // RR case
        root = leftrotation(root);
    }
    else if (root->bf > 1 && data > root->left->data) {
        // LR case
        root = LeftRight(root);
    }
    else if (root->bf < -1 && data < root->right->data) {
        // RL case
        root = RightLeft(root);
    }
}

void insert(node*&root,int data)
{
  if(root==NULL)
  {
root=new node(data);
return ;
  }

if(root->data>data)
{
  if(root->left==NULL)
  {
 root->left=new node(data);

  }

  else insert(root->left,data);

}
else{
 if(root->right==NULL)
 {
  root->right=new node(data);

 }

  else insert(root->right,data);
}
root->bf=height(root->left)-height(root->right);
if(!(root->bf==1||root->bf==0||root->bf==-1))
{
 cout<<"node "<<root->data<<" got unbalanced ";
 balance(root,data);
}


}
int getleftmax(node*root)
{
  if(root->right==NULL)
  return root->data;
  else{
    while(root->right!=NULL)
    {
      root=root->right;
    }
    return root->data;
  }
}
node* deletenode(node*root,int data)
{
  if(root==NULL)
  return NULL;
  if(root->data<data)
  {
    root->right=deletenode(root->right,data);
    root->bf=height(root->left)-height(root->right);
    if(!(root->bf==1||root->bf==0||root->bf==-1))
{
 cout<<"node "<<root->data<<" got unbalanced ";
 balance(root,data);
}
  }
  else if(root->data>data)
  {
    root->left=deletenode(root->left,data);
    root->bf=height(root->left)-height(root->right);
    if(!(root->bf==1||root->bf==0||root->bf==-1))
{
 cout<<"node "<<root->data<<" got unbalanced ";
 balance(root,data);
}
  }
  else{
    if(root->left==NULL&&root->right==NULL)
    {
delete root;
return NULL;
    }

    else if(root->right==NULL)
    {
      node*temp=root->left;
      delete root;
      return temp;
    }
    else if(root->left==NULL)
    {
      node*temp=root->right;
      delete root;
      return temp;
    }else{
      int leftmax=getleftmax(root->left);
      root->data=leftmax;
      root->left=deletenode(root->left,leftmax);
      root->bf=height(root->left)-height(root->right);
      if(!(root->bf==1||root->bf==0||root->bf==-1))
{
 cout<<"node "<<root->data<<" got unbalanced ";
 balance(root,data);
}
    }
  }
  return root;
}
void inorder(node*root)
{
  if(root==NULL)
  return;
    inorder(root->left);
    cout<<root->data<<"->"<<root->bf<<" ";
    inorder(root->right);

}
int main()
{
int data;
bool del;
node*root=NULL;
for(int i=0;i<14;i++)
{
cin>>data;
insert(root,data);
inorder(root);
}
for(int i=0;i<7;i++)
{
  cin>>data;
  deletenode(root,data);
   root->bf=height(root->left)-height(root->right);
      if(!(root->bf==1||root->bf==0||root->bf==-1))
{
 cout<<"node "<<root->data<<" got unbalanced ";
 balance(root,data);
}

  inorder(root);
}
 //LevelOrderTraversal(root);
}
