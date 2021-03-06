#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

class node
{
	 public:
		int data;
		node *left;
		node *right;
};
class Queue
{
	node* a[30];
	public:
		int first,last;
		Queue()
		{
			first=last=-1;
		}
		~Queue()
		{  }
		void enqueue(node *t)
		{
			if(first==-1)
			{
				first=last=0;
				a[last++]=t;
			}
			else if(last==29)
			{
				cout<<"\n Queue full !!!";
				exit(1);
			}
			else
			{
				a[last++]=t;
			}
		}

		node* dequeue()
		{
			if(first==-1)
			{
				cout<<"\n Queue Empty !!!";
			}
			node *k;
			if(first==last)
			{
				k=a[first];
				first=last=-1;
			}
			else
			{
				k=a[first++];
			}
			return k;
		}
};

class BST
{
	public:
		node *temp,*temp1,*temp2,*root=NULL;
		int leaf,nonLeaf;
		BST()
		{
			leaf=nonLeaf=0;
		}
		void insert();
		void deleteCopying(node *,int);
		void deleteMerging(node *,int);
		void delmerge(node *&);
		void delcopy(node *&);
		void search(int);
		void searchMerging(int);
		void preorder(node *);
		void postorder(node *);
	    void inorder(node *);
	    void bfs_treversal(node *);
	    void leaf_nonLeaf(node *);
	    int height(node *);
	    void mirrorImage(node *);
};

void BST::insert()
{
	int i;
	cout<<"\n Enter the node value ( 0 to exit ) : ";
	cin>>i;
	while(i!=0)
	{
		temp=new node;
		temp->data=i;
		temp->left=temp->right=NULL;

		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			temp1=root;
			while(temp1!=NULL)
			{
				if(i<temp1->data)
				{
					temp2=temp1;
					temp1=temp1->left;
				}
				else
				{
					temp2=temp1;
					temp1=temp1->right;
				}
			}
			if(i<temp2->data)
			{
				temp2->left=temp;
			}
			else
			{
				temp2->right=temp;
			}
		}
		cout<<"\n Enter the node value ( 0 to exit ) : ";
	    cin>>i;
	}
}

void BST::postorder(node *t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		cout<<" "<<t->data;
	}
}

void BST::preorder(node *t)
{
	if(t!=NULL)
	{
		cout<<" "<<t->data;
		preorder(t->left);
		preorder(t->right);
	}
}

void BST::inorder(node *t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		cout<<" "<<t->data;
		inorder(t->right);
	}
}

void BST::bfs_treversal(node *t)
{
	Queue q;
	if(t!=NULL)
	{
		q.enqueue(t);
		while(q.first!=-1)
		{
			t=q.dequeue();
			cout<<" "<<t->data;
			if(t->left!=NULL)
			    q.enqueue(t->left);
			if(t->right!=NULL)
			    q.enqueue(t->right);
		}
	}
}

void BST::leaf_nonLeaf(node *t)
{
	if(t!=NULL)
	{
		if(t->left==0 && t->right==0)
		    leaf++;
		else
		    nonLeaf++;
		leaf_nonLeaf(t->left);
		leaf_nonLeaf(t->right);
	}
}

void BST::search(int el)
{
	int flag=0;
	temp=root;
	while(temp)
	{
		if(el==temp->data)
		{
			flag=1;
			break;
		}
		else if(el<temp->data)
		{
			temp=temp->left;
		}
		else
		{
			temp=temp->right;
		}
	}
	if(flag==1)
	{
		cout<<"\n Element found !";
	}
	else
	{
		cout<<"\n Element not found !!!";
	}
}


int BST::height(node *t)
{
	if(t==NULL)
	    return 0;
	int lheight=height(t->left);
	int rheight=height(t->right);
	if(lheight>rheight)
	    return lheight+1;
	else
	    return rheight+1;
}

void BST::mirrorImage(node *t)
{
	if(t==NULL)
	    return;
	else
	{
		mirrorImage(t->left);
		mirrorImage(t->right);

		temp=t->left;
		t->left=t->right;
		t->right=temp;
	}
}

void BST::deleteCopying(node *t,int el)
{
	node *prev=NULL;
	while(t!=NULL)
	{
		if(t->data==el)
		    break;
		prev=t;
		if(t->data<el)
		    t=t->right;
		else
		    t=t->left;
	}
	if(t!=NULL && t->data==el)
	{
		if(t==root)
		    delcopy(root);
		else if(prev->left==t)
		    delcopy(prev->left);
		else
		    delcopy(prev->right);
	}
	else if(root!=0)
	    cout<<"\n KEY "<<el<<" is not in the tree";
	else
	    cout<<"\n Tree is Empty";
}

void BST::delcopy(node *&t1)
{
	node *prev,*tmp=t1;
	if(t1->right==NULL)
	    t1=t1->left;
	else if(t1->left==NULL)
	    t1=t1->right;
	else
	{
		tmp=t1->left;
		prev=t1;
		while(tmp->right!=NULL)
		{
			prev=tmp;
			tmp=tmp->right;
		}
		t1->data=tmp->data;
		if(prev==t1)
		    prev->left=tmp->left;
		else
		    prev->right=tmp->left;
	}
	delete tmp;
}

void BST::deleteMerging(node *t,int el)
{
	node *prev=NULL;
	while(t!=NULL)
	{
		if(t->data==el)
		    break;
		prev=t;
		if(t->data<el)
		    t=t->right;
		else
		    t=t->left;
	}
	if(t!=NULL && t->data==el)
	{
		if(t==root)
		    delcopy(root);
		else if(prev->left==t)
		    delcopy(prev->left);
		else
		    delcopy(prev->right);
	}
	else if(root!=0)
	    cout<<"\n KEY "<<el<<" is not in the tree";
	else
	    cout<<"\n Tree is Empty";
}

void BST::delmerge(node *&t1)
{
	node *tmp=t1;
	if(t1!=NULL)
	{
		if(!t1->right)
	        t1=t1->left;
	    else if(!t1->left)
	        t1=t1->right;
	    else
	    {
	    	tmp=t1->left;
	    	while(tmp->right!=NULL)
	    	{
	    		tmp=tmp->right;
	    	}
	    	tmp->right=t1->right;
	    	tmp=t1;
	    	t1=t1->left;
    	}
	    delete tmp;
	}
}

int main()
{
	BST ob;
	int ch,n,el;
	do
	{
		cout<<"\n -------------MAIN MENU---------------";
		cout<<"\n 1. Insertion";
		cout<<"\n 2. Deletion by Copying";
		cout<<"\n 3. Deletion by Merging";
		cout<<"\n 4. Search";
		cout<<"\n 5. Inorder, preorder and postorder treversals";
		cout<<"\n 6. bfs Treversal";
		cout<<"\n 7. Leaf and Non-Leaf nodes";
		cout<<"\n 8. Height";
		cout<<"\n 9. Mirror Image";
		cout<<"\n Enter your choice ( 0 to exit ) : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				ob.insert();
				break;
			case 2:
			    cout<<"\n Enter the key to be deleted : ";
				cin>>el;
				ob.deleteCopying(ob.root,el);
				break;
			case 3:
			    cout<<"\n Enter the key to be deleted : ";
				cin>>el;
				ob.deleteMerging(ob.root,el);
				break;
			case 4:
			    cout<<"\n Enter the key to be serched : ";
				cin>>el;
				ob.search(el);
				break;
			case 5:
			    cout<<"\n Inorder :";
				ob.inorder(ob.root);
				cout<<"\n Preorder :";
				ob.preorder(ob.root);
				cout<<"\n Postorder :";
				ob.postorder(ob.root);
				break;
			case 6:
			    cout<<"\n BFS Treversal :";
			    ob.bfs_treversal(ob.root);
			    break;
			case 7:
			    ob.leaf_nonLeaf(ob.root);
				cout<<"\n LEAF : "<<ob.leaf;
				cout<<"\n NON-LEAF : "<<ob.nonLeaf;
				break;
			case 8:
			    el=ob.height(ob.root);
				cout<<"\n Height : "<<el;
				break;
			case 9:
			    ob.mirrorImage(ob.root);
				cout<<"\n Tree Inverted Successfully !";
				break;
			default :
			    break;
		}
	}while(ch!=0);
return 0;
}