#include"SeqList.h"
const int MaxNumEdges = 50;							//������
const int MaxNumVertices=10;							//��󶥵���

template <class NameType, class DistType> class Graph {			//ͼ���ඨ��
private:
   SeqList<NameType> VerticesList;//(5);			//�����
   DistType Edge[MaxNumVertices][MaxNumVertices];			//�ڽӾ���
   int CurrentEdges;								//��ǰ����
   int CurrentVertices;
  //int FindVertex ( SeqList<NameType> & L, const NameType & vertex )
   // { return L.Find (vertex); }     //�ڶ����L����������vertex
   //int GetVertexPos ( const NameType & vertex )
    //{ return FindVertex (VerticesList, vertex ); }
     //��������vertex��ͼ�е�λ��
public:
   //SeqList<NameType> VerticesList(MaxNumVertices);			//�����
	//SeqList<NameType> VerticesList(3);
   Graph ( const int sz);					//���캯��	
   void InitGraph();
   int GraphEmpty ( ) const { return VerticesList.IsEmpty ( ); }		//��ͼ�շ�
   int GraphFull ( ) const { return VerticesList.IsFull ( ) || CurrentEdges ==MaxNumEdges; }
   int NumberOfVertices ( ) { return VerticesList.Length(); }		//���ص�ǰ������
   int NumberOfEdges ( ) { return CurrentEdges; }				//���ص�ǰ����
   NameType GetValue ( const int i )						//ȡ����i��ֵ, i�������򷵻ؿ�
      { return VerticesList.Get(i); }
   DistType GetWeight ( const int v1, const int v2 );		//�����Զ���v1��v2Ϊ���˵�ı��ϵ�Ȩֵ
   int GetFirstNeighbor ( const int v );				//��������λ��Ϊv�ĵ�һ���ڽӶ����λ��
   int GetNextNeighbor ( const int v1, const int v2 );		//��������λ��v1��ĳ�ڽӶ���v2����һ���ڽӶ���
   void InsertVertex (  NameType & vertex );		//����һ������vertex, �ö���û�����
   void InsertEdge ( const int v1, const int v2, DistType weight );	//����һ����(v1, v2), �ñ��ϵ�ȨֵΪweight
   void RemoveVertex ( const int v );				//��ͼ��ɾȥ����vertex����������������ı�
   void RemoveEdge ( const int v1, const int v2 );		//��ͼ��ɾȥ��(v1,v2)
  // void Prim ( MinSpanTree &T ) ;
  // void Kruskal ( MinSpanTree &T );
   friend istream& operator >>(istream& , Graph&);
   void DFS ();
   void BFS(int v);
   void DFS ( const int v, int visited[]) ;
};

template <class NameType, class DistType> Graph<NameType, DistType>::Graph ( const int sz ) {
	//���캯��
	CurrentVertices=sz;
	for (int i=0;i<sz;i++) {
		//VerticesList.Insert(char(65+i));
		VerticesList.Insert(i);
	}
	VerticesList.Output();
	InitGraph();
};
template <class NameType, class DistType> void Graph< NameType, DistType>::InitGraph(){	
	for (int m=0;m<CurrentVertices;m++) 
		for (int n=0;n<CurrentVertices;n++) {
				Edge[m][n]=0;
		}
		int num,i,j;
		cout<<"Input the number of edge:"<<endl;
		cin>>num;
		cout<<"Input the edge:"<<endl;
		for(int k=0;k<num;k++){
			cin>>i>>j;
			Edge[i][j]=1;
			if(k!=(num-1)) cout<<"continue:"<<endl;
		}
	for ( i=1;i<CurrentVertices;i++) 
		for ( j=0;j<i;j++) {
			Edge[i][j]=Edge[j][i];
		}
		cout<<"the matrix is :"<<endl;
	for (int m1=0;m1<CurrentVertices;m1++) 
		for (int n1=0;n1<CurrentVertices;n1++) {
				cout<<Edge[m1][n1]<<" ";
				if (n1==CurrentVertices-1) { cout<<endl;}
		}
}

template <class NameType, class DistType>
DistType Graph<NameType, DistType>::GetWeight ( const int v1, const int v2 ) 
{
//�����Զ���v1��v2Ϊ���˵�ı��ϵ�Ȩֵ
   if ( v1 != -1 && v2 != -1 ) return Edge[v1][v2];
   else return NULL;							//��Ȩͼ��ȨֵΪ0, ��ʾ��Ȩֵ
};


/*template <class NameType, class DistType> 
NameType Graph<NameType, DistType>::GetFirstNeighbor ( const int v ) {
//��������λ��Ϊv�ĵ�һ���ڽӶ����λ��, ����Ҳ���, ��������-1��
   if ( v != -1 ) {
	 for ( int col=0; col<VerticesList.Length(); col++ ) if ( Edge[v][col] > 0 ) return VerticesList.Get(col);
   }
   return -1;
};*/
template <class NameType, class DistType> 
int Graph<NameType, DistType>::GetFirstNeighbor ( const int v ) {
//��������λ��Ϊv�ĵ�һ���ڽӶ����λ��, ����Ҳ���, ��������-1��
   if ( v != -1 ) {
	 for ( int col=0; col<VerticesList.Length(); col++ ) if ( Edge[v][col] > 0 ) return col;
   }
   return -1;
};
/*template <class NameType, class DistType>
NameType Graph<NameType, DistType>::GetNextNeighbor ( const int v1, const int v2 ) {
//��������v1��ĳ�ڽӶ���v2����һ���ڽӶ���
   if ( v1 != -1 && v2 != -1 )
   {
     for ( int col=v2+1; col<VerticesList.Length(); col++ )
       if ( Edge[v1][col] > 0 ) return VerticesList.Get(col);
   }
   return -1;
};*/
template <class NameType, class DistType>
int Graph<NameType, DistType>::GetNextNeighbor ( const int v1, const int v2 ) {
//��������v1��ĳ�ڽӶ���v2����һ���ڽӶ���
   if ( v1 != -1 && v2 != -1 )
   {
     for ( int col=v2+1; col<VerticesList.Length(); col++ )
       if ( Edge[v1][col] > 0 ) return col;
   }
   return -1;
};

template <class NameType, class DistType>
void Graph<NameType, DistType>::InsertVertex (  NameType & vertex )		//����һ������vertex, �ö���û�����
{
	assert (VerticesList.Insert ( vertex, VerticesList.Length() ));		
};

template <class NameType, class DistType>
void Graph<NameType, DistType>:: InsertEdge ( const int v1, const int v2, DistType weight )	//����һ����(v1, v2), �ñ��ϵ�ȨֵΪweight
{
	CurrentEdges++;
	Edge[v1][v2]=weight;
};
/*template <class NameType, class DistType>istream& operator >>(istream& is, Graph<NameType,DistType>& g)
{
   int n,e,k,j;
   NameType head,tail,name;
   DistType weight;
   is >> n;										//���붥�����
   for ( int i=0; i<n; i++)
   {
     is >> name;
     g.InsertVertex ( name );
   }		//�������붥��, ����ͼ��

   is >> e;										//�������

   for ( i=0; i<e; i++) {								//�����������Ϣ
	 is >> tail >> head >> weight;						//�������
	 k = g.GetVertexPos ( tail );  j = g.GetVertexPos ( head );			//ȡ������λ��
	 g.InsertEdge ( k, j, weight );							//����ͼ��
   }
   return is;

}*/

template <class NameType, class DistType> void Graph< NameType, DistType>::DFS ( ) {						//����ͨͼ�����������������������
	int *visited = new int [NumberOfVertices()];					//������������
	for ( int i=0; i<NumberOfVertices(); i++ ) visited [i] = 0;			//���������ʼ��
	cout<<"This is the DFS"<<endl;
	DFS(0,visited);								//�Ӷ���0��ʼ�����������
	delete [ ] visited;
};
template <class NameType, class DistType>void Graph< NameType, DistType>::DFS (const int v, int visited []){		//�ӹ���
		//�Ӷ���λ��v����, ��������ȵĴ���������пɶ������δ���ʹ��Ķ��㡣�㷨���õ�һ����������
		// visited, ���ѷ��ʹ��Ķ��������ʱ�ǡ�
	cout << GetValue (v) << ' ';					//���ʸö��������
	visited[v] = 1;							//���ʱ�־��Ϊ�ѷ��ʹ�
	int w = GetFirstNeighbor (v);					//�Ҷ���v�ĵ�һ���ڽӶ���w
	while ( w != -1 ) {						//���ڽӶ���
		if ( !visited[w] ) {
			DFS ( w, visited );			//��δ���ʹ�, ��w�ݹ����
		}
		w = GetNextNeighbor ( v, w );				//�Ҷ���v����һ���ڽӶ���
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