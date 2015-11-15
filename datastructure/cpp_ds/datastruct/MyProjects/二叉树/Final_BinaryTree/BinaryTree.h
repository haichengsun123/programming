#include <iostream.h>
#include <stdlib.h>
class BinaryTree;
class BinTreeNode {
friend class BinaryTree;
public:
    BinTreeNode ( ) : leftChild (NULL),rightChild (NULL) { }
    BinTreeNode (int item, BinTreeNode *left = NULL,BinTreeNode *right = NULL ) :data(item),leftChild (left), 
    rightChild(right) { }
private:
    BinTreeNode *leftChild, *rightChild;   //������Ů   
    int data;   //������
};
class BinaryTree {
public:
    BinaryTree ( ) : root (NULL) { }//���캯��
    BinaryTree ( int value ) : RefValue (value), root (NULL) { }
    ~BinaryTree ( ) { destroy ( root ); }//��������
    void Insert(BinTreeNode *&current,int &item);//���뺯��	
	void remove();//���ɾ��
	void destroy(BinTreeNode *current);
	void output(){Traverse(root);}//�������
	void input();
	void Traverse(BinTreeNode *current);
	void inorder(){inorder(root);}//�������
	void preorder(){preorder(root);}//ǰ�����
	void postorder(){postorder(root);}//�������
	void find();//���ҽ����ڴ��ַ
	void size(){ cout<<"the number of nodes of the  binarytree��"<<size(root)<<endl;}//���ܵĽ����
	void height(){cout<<"the height of the binary tree��"<<height(root)<<endl;}//�����ĸ߶�
	void LeafNode(){cout<<"the number of the leafnodes of the binary tree��"<<LeafNode(root)<<endl;}//������Ҷ���
	int min(){return min(root)->data;}//��С��
	int Max(int a,int b){return a>b?a:b;}//�����Žϴ���
	void Sum();
	int Sum(BinTreeNode *current);
private:
    BinTreeNode  *root;//�������ĸ�ָ��
    int RefValue;//��������ֹͣ��־������������
	void inorder(BinTreeNode *current);
	void preorder(BinTreeNode *current);
	void postorder(BinTreeNode *current);
	int size(BinTreeNode *current);
	int height(BinTreeNode *current);
	int LeafNode(BinTreeNode *current);
	BinTreeNode *find(int item,BinTreeNode *current);
	BinTreeNode *min(BinTreeNode *current);
	void remove(int item,BinTreeNode *&current);  	
};
void BinaryTree:: destroy ( BinTreeNode *current ) {
    if ( current != NULL ) {
       destroy ( current->leftChild );
       destroy ( current->rightChild );
       delete current;
    }
}
void BinaryTree::inorder(BinTreeNode *current)
{
	if(current!=NULL)
	{
		inorder(current->leftChild);
		cout<<current->data<<" ";
		inorder(current->rightChild);
	}
}
void BinaryTree::preorder(BinTreeNode *current)
{
	if(current!=NULL)
	{
		cout<<current->data<<" ";
		inorder(current->leftChild);
		inorder(current->rightChild);
	}
}
void BinaryTree::postorder(BinTreeNode *current)
{
	if(current!=NULL)
	{
		inorder(current->leftChild);
		inorder(current->rightChild);
		cout<<current->data<<" ";
	}
}

void BinaryTree:: Traverse (BinTreeNode *current )  {
    if ( current != NULL ) {					       
         cout << current->data << ' ';//���current������
        Traverse ( current->leftChild);//�����������������
        Traverse ( current->rightChild); //�����������������
    }
}
void BinaryTree::Insert(BinTreeNode *&current,int &item)
{	
	if(current==NULL)
	{
		current=new BinTreeNode(item);
		if(current==NULL)
		{
			cout<<"out of space!"<<endl;
			exit(1);
		}
	}
	else if(item<current->data) Insert(current->leftChild,item);
	else if(item>current->data) Insert(current->rightChild,item);
}
void BinaryTree::remove(int x,BinTreeNode *&current)
{
	BinTreeNode *temp;
	if(current!=NULL)
		if(x<current->data) remove(x,current->leftChild);
		else if(x>current->data) remove(x,current->rightChild);
		else if(current->leftChild!=NULL&&current->rightChild!=NULL)
		{
			temp=min(current->rightChild);
			current->data=temp->data;
			remove(current->data,current->rightChild);
		}
		else
		{
			temp=current;
			if(current->leftChild==NULL) current=current->rightChild;
			else if(current->rightChild==NULL) current=current->leftChild;
			delete temp;
		}
}
void BinaryTree::remove()
{
	int item;
	cout<<"the node you want to remove��";
	cin>>item;
	remove (item,root);
	cout<<endl;
}
void BinaryTree::find()
{
	int item;
	cout<<"the number you want to find :";
	cin>>item;
	cout<<"the address of the node��"<<find(item,root)<<endl;
	if(find(item,root)!=NULL) cout<<"search success��"<<endl;
	   else cout<<"search failing��"<<endl;
}
BinTreeNode * BinaryTree::find(int item,BinTreeNode *current)
{
	if(current==NULL)
		return NULL;
	else if(item<current->data) return find(item,current->leftChild);
	else if(item>current->data) return find(item,current->rightChild);
	else return current;
}
int BinaryTree::size(BinTreeNode *current)
{
	if(current==NULL)
		return 0;
	else
		return 1+size(current->leftChild)+size(current->rightChild);
}
int BinaryTree::height(BinTreeNode *current)
{
    if(current==NULL)return -1;
	else return 1+Max(height(current->leftChild),height(current->rightChild));
}
int BinaryTree::LeafNode(BinTreeNode *current)
{
	if(current==NULL) return 0;
	if(current->leftChild!=NULL||current->rightChild!=NULL) 
     return LeafNode(current->leftChild )+LeafNode(current->rightChild);
    else return 1;
}
void BinaryTree::input()
{
	cout<<"input the flag for quiting��"<<endl;
	cout<<"RefValue=";
	cin>>RefValue;
	int item;
	cout<<"please input the node��";
	cin>>item;
	while(item!=RefValue)
		{
		   Insert(root,item);
		   cout<<"please input the node��";
		   cin>>item;
		}
}
BinTreeNode *BinaryTree::min(BinTreeNode *current)
{
	for(;current->leftChild!=NULL;)
		current=current->leftChild;
	return current;
}
int BinaryTree::Sum(BinTreeNode *current){
	int sum=0;
	 if ( current!= NULL ) {					       
        sum=sum+current->data;//���current������
        sum=Sum( current->leftChild)+sum;//�����������������
        sum=Sum( current->rightChild)+sum; //�����������������
	 }	 
	 return sum;

}
void BinaryTree::Sum(){
	cout<<Sum(root)<<endl;
}