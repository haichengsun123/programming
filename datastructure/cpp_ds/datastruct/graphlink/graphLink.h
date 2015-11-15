#include"Queue.h"
const int DefaultSize=10;

template <class NameType, class DistType> class Graph;				//ͼ��ǰ���ඨ��

template <class DistType> class Edge {				//�ߵĶ���
public:
   friend class Graph<class NameType,class DistType>;	
   int dest;							//�ߵ���һ����λ��, ��һ������λ������ʽ��
   DistType cost;						//���ϵ�Ȩֵ
   Edge<DistType> *link;						//��һ������ָ��
   Edge ( ) {link=NULL; }								//���캯��
   Edge ( int D, DistType C ) : dest (D), cost (C), link (NULL) { }	//���캯��
   int operator != ( const Edge &E ) const { return dest != E.dest; }
};

template <class NameType, class DistType> class Vertex {		//����Ķ���
public:
   friend class Graph<NameType,DistType>;
   friend class Edge <class DistType>;	
   NameType data;							//���������
   Edge<DistType> *adj;							//���߱��ͷָ��
};
#ifndef SetMaxVertices
#define SetMaxVertices
const int MaxNumVertices=10;
#endif
////const DefaultSize = 20;
template <class NameType, class DistType> class Graph
{		//ͼ���ඨ��
//friend class Vertex <NameType, DistType>;
//friend class Edge<DistType>;
private:
   Vertex<NameType, DistType> *NodeTable;			//����� (���������ͷ���)
   int NumVertices;							//��ǰ�������
   int MaxNumVertices;							//��󶥵����
   int NumEdges;								//��ǰ����
   int GetVertexPos ( const NameType & vertex );				//��������vertex��ͼ�е�λ��
public:
   Graph (const int sz=DefaultSize );								//���캯��
   ~Graph ( );								//��������
   int GraphEmpty ( ) const { return NumVertices == 0; }		//����ͼ�շ�
   int GraphFull ( ) const							//����ͼ����
	  { return NumVertices == MaxNumVertices||NumEdges ==MaxNumEdges; }
   int NumberOfVertices ( ) { return NumVertices; }			//����ͼ�Ķ�����
   int NumberOfEdges ( ) { return NumEdges; }			//����ͼ�ı���
   NameType GetValue ( const int i )					//ȡλ��Ϊi�Ķ����е�ֵ
	  { return i >= 0 && i < NumVertices ? NodeTable[i].data : NULL; }
   void InsertVertex ( const NameType & vertex );			//��ͼ�в���һ������
   void RemoveVertex ( const int v );					//��ͼ��ɾ��һ������
   void InsertEdge ( const int v1, const int v2, const DistType weight );		//��ͼ�в���һ����
   void RemoveEdge ( const int v1, const int v2 );			//��ͼ��ɾ��һ����
   DistType GetWeight ( const int v1, const int v2 );			//���ر��ϵ�Ȩֵ
   int GetFirstNeighbor ( const int v );				//ȡ����v�ĵ�һ���ڽӶ���
   int GetNextNeighbor ( const int v1, const int v2 );		//ȡ����v1��ĳ�ڽӶ���v2����һ���ڽӶ���
   void OutPut();
   void OutPutEach();
   //int GetVertexPos ( const NameType & vertex );
   void DFS ( );
   void DFS ( const int v, int visited [ ] );
   void BFS ( int v );
   //void DfnLow ( const int x );
   //void DfnLow ( const int u, const int v );
   //void Components ( );
   //void Biconnected ( );
   //void Biconnected ( const int u, const int v );
   //void CriticalPath();
};


const int MaxNumEdges=20;
template <class NameType, class DistType>Graph <NameType, DistType>::
Graph ( const int sz=DefaultSize ) : NumVertices (0), MaxNumVertices (sz), NumEdges (0) {
   int n, e, k, j;
   NameType name, tail, head;
   DistType weight;
   NodeTable = new Vertex<NameType,DistType>[MaxNumVertices];			//�������������
   cout<<"Please enter the number of the vertex:"<<endl;
   cin >> n;										//���붥�����   
   assert(n<=sz);   
   cout<<"Please enter the vertex:"<<endl;
   for ( int i=0; i<n; i++)
   {
     cin >> name;
     InsertVertex ( name );
	 cout<<"continue:"<<endl;
   }		//�������붥��, ����ͼ��
   cout<<"Please enter the number of the edge:"<<endl;
   cin >> e;										//�������   
   assert(e<=MaxNumEdges);   
   cout<<"Please enter the edge:start end and cost:"<<endl;
   for ( i=0; i<e; i++) {								//�����������Ϣ
	 cin >> tail >> head >> weight;						//�������
	 k = GetVertexPos ( tail );  j = GetVertexPos ( head );			//ȡ������λ��
	 InsertEdge ( k, j, weight );	//����ͼ��
	 cout<<"continue:"<<endl;
   }
}

template <class NameType, class DistType> Graph<NameType, DistType>::~Graph ( ) {
   for ( int i=0; i<NumVertices; i++ ) {						//ɾ�����������еĽ��
	 Edge<DistType> *p = NodeTable[i].adj;
	 while ( p != NULL ) 							//ѭ��ɾ��
	   {	NodeTable[i].adj = p->link;  delete p;  p = NodeTable[i].adj; }
   }
   delete [ ] NodeTable;								//ɾ����������
}

template <class NameType, class DistType>
int Graph<NameType, DistType>::GetVertexPos( const NameType & vertex )
{
	if(NumVertices>=0){
		for ( int i=0; i< NumVertices; i++) {
			if ( NodeTable[i].data == vertex ) return i;
		}
	}

   return -1;
}
template <class NameType, class DistType> int Graph<NameType, DistType>::GetFirstNeighbor ( const int v ) {
//��������λ��Ϊv�ĵ�һ���ڽӶ����λ��, ����Ҳ���, ��������-1��
   if ( v>=0 ) {							//v����
	 Edge<DistType> *p = NodeTable[v].adj;				//�������һ������ַ
	 if ( p != NULL ) return p->dest;				//��, ���ظñ���һ������
   }
   return -1;								//û�б�
}

template <class NameType, class DistType>
int Graph<NameType, DistType>::GetNextNeighbor ( const int v1, const int v2 ) {
//��������v1��ĳ�ڽӶ���v2����һ���ڽӶ����λ��, ��û����һ���ڽӶ���, ��������-1��
   if ( v1!=-1) {									//v1����
	 Edge<DistType> *p = NodeTable[v1].adj;				//�������һ������ַ
	 while ( p != NULL ) {							//Ѱ�ҵ�v2���ڽӶ���
	   if ( p->dest == v2 && p->link != NULL ) return p->link->dest;
	   else p = p->link;
	 }
   }
   return -1;
}

template <class NameType, class DistType>
DistType Graph<NameType, DistType>::GetWeight ( const int v1, const int v2) {
//�������ر�(v1, v2)�ϵ�Ȩֵ, ���ñ߲���ͼ��, ��������Ȩֵ0��
   if ( v1 != -1 && v2 != -1 ) {
	 Edge<NameType,DistType> *p = NodeTable[v1].adj;				//������ͷָ��
	 while ( p != NULL ) {
	   if ( p->dest == v2 ) return p->cost;				//�ҵ��˱�, ����Ȩֵ
	   else p = p->link;							//��������һ����
	 }
   }
   return 0;										//�߲���ͼ��
}


template <class NameType, class DistType>
void  Graph<NameType, DistType>::InsertEdge ( const int v1, const int v2, const DistType weight ){
	
	static Edge<DistType> *p,*temp1,*temp2;
	temp1=new Edge<DistType>;
	temp2=new Edge<DistType>;
	temp1->cost=weight;
	temp2->cost=weight;
	temp1->dest=v2;
	temp2->dest=v1;
	if(NodeTable[v1].adj==NULL){
		cout<<"yunxing zheli :"<<endl;
		NodeTable[v1].adj=temp1;
	}
	else{
		p=NodeTable[v1].adj;
		while (p->link!=NULL) {
			p=p->link;
			
		}
		p->link=temp1;
	}
	if(NodeTable[v2].adj==NULL){
		NodeTable[v2].adj=temp2;
	}
	else{
		p=NodeTable[v2].adj;
		while (p->link!=NULL) {
			p=p->link;
			
		}
		p->link=temp2;
	}
	delete p;

}

template <class NameType, class DistType>
void  Graph<NameType, DistType>::InsertVertex ( const NameType & vertex ){
	++NumVertices;
	NodeTable[NumVertices-1].data=vertex;
	NodeTable[NumVertices-1].adj=NULL;
}
template <class NameType, class DistType>
void  Graph<NameType, DistType>::OutPut(){
	for (int i=0;i<NumVertices;i++) {
		cout<<"This is the vetex:"<<endl;
		cout<<NodeTable[i].data<<endl;
		
	}
}
template <class NameType, class DistType> void Graph<NameType, DistType>::BFS (  int v ) {
		//�Ӷ���v����, �Թ�����ȵĴ����������ͼ, �㷨��ʹ����һ�����С�
	int *visited = new int[NumberOfVertices()];                  		//visited��¼�����Ƿ���ʹ�
	for ( int i=0; i<NumberOfVertices(); i++ ) visited[i] = 0;			//��ʼ��
	cout<<endl<<"This is the BFS:"<<endl;
	cout << GetValue (v) << ' ';	
	visited[v] = 1;			//���ȷ��ʶ���v, ���ѷ��ʱ��
	Queue<int> q;								//q��ʵ�ֲַ���ʵĶ���
	q.EnQueue (v);								//����v������
	while ( !q.IsEmpty ( ) ) {
		v = q.DeQueue ( );							//�Ӷ������˳�����v
		int w = GetFirstNeighbor (v);					//�Ҷ���v�ĵ�һ���ڽӶ���
		while ( w != -1 ) {							//w��v���ڽӶ���
			if ( !visited[w] ) {						//��δ���ʹ�
				cout << GetValue (w) << ' ';  visited[w] = 1;		//���ʶ���w
				q.EnQueue (w);						//����w������
			}
			w = GetNextNeighbor (v, w);					//�Ҷ���v����һ���ڽӶ���}
		}
	}
	cout<<endl;
		delete [ ] visited;
}
template <class NameType, class DistType> void Graph<NameType, DistType>::OutPutEach(){
	Edge<DistType> *p;
	for (int i=0;i<NumberOfVertices ( );i++) {
		p=NodeTable[i].adj;
		cout<<"this is the    "<<i<<"th link:"<<endl;
		if(p!=NULL) {
			cout<<NodeTable[i].data<<endl;
		}

		while(p!=NULL){
			cout<<GetValue(p->dest)<<endl;
			p=p->link;
			
		}
	}
}