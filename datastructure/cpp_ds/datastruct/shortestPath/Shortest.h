

const int NumVertices =10;				//ͼ����󶥵����
const int MAXINT=32767;
class Graph {						//ͼ���ඨ��
private:
	int Edge[NumVertices][NumVertices];		//ͼ���ڽӾ���
	int dist[NumVertices];		//ͼ���ڽӾ���
	int path[NumVertices];		//ͼ���ڽӾ���
	int S[NumVertices];
	int CurrentVertices;
public:
	   Graph ( );
	   Graph ( const int sz);	
	   void InitGraph();
	   void ShortestPath ( int n, int v) ;
	   void Output(const int num);
};
Graph::Graph ( ) {
	//���캯��
	InitGraph();
};
Graph::Graph (const int sz) {
	//���캯��
	CurrentVertices=sz;
	InitGraph();
};
void Graph::InitGraph(){	
	for (int m=0;m<CurrentVertices;m++) 
		for (int n=0;n<CurrentVertices;n++) {
			Edge[m][n]=MAXINT;
		}
		for ( m=0;m<CurrentVertices;m++) 
		{
			Edge[m][m]=0;
		}
		int num,i,j,cost;
		cout<<"Input the number of edge:"<<endl;
		cin>>num;
		cout<<"Input the edge start end and cost :"<<endl;
		for(int k=0;k<num;k++){
			cin>>i>>j>>cost;
			Edge[i][j]=cost;
			if(k!=(num-1)) cout<<"continue:"<<endl;
		}	
		cout<<"the matrix is :"<<endl;
		for (int m1=0;m1<CurrentVertices;m1++) 
			for (int n1=0;n1<CurrentVertices;n1++) {
				cout<<Edge[m1][n1]<<" ";
				if (n1==CurrentVertices-1) { cout<<endl;}
			}
}
void Graph::ShortestPath (  int n,int v) {
	//G��һ������n������Ĵ�Ȩ����ͼ, �����ϵ�Ȩֵ��Edge[i][j]���������㷨������һ������: dist[j], 0 < j < n,
	//�ǵ�ǰ�󵽵ĴӶ���v������j�����·������, ͬʱ������path[j],	0 < j < n, ����󵽵����·����
	// assert(((v<n) &&(v>=0)));
	for ( int i=0; i<n; i++) {				// dist��path�����ʼ��
		dist[i] = Edge[v][i];					//�ڽӾ����v��Ԫ�ظ��Ƶ�dist��
		S[i] = 0;						//��������·���Ķ��㼯�ϳ�ʼ��
		if ( i != v && dist[i] < MAXINT ) path[i] = v;
		else path[i] = -1;					//·����������ʼ��
	}
	S[v] = 1;  dist[v] = 0;					//����v���붥�㼯��
	for ( i=0; i<n-1; i++ ) {				//�Ӷ���vȷ��n-1��·��
		int min = MAXINT;
		int u = v;
		for ( int j=0; j<n; j++ )				//ѡ��ǰ���ڼ���S�о������·���Ķ���u
			if ( !S[j] && dist[j] < min ) { u = j;  min = dist[j]; }
			S[u] = 1;						//������u���뼯��S, ��ʾ���������·����
			for ( int w=0; w<n; w++ )			//�޸�
				if ( !S[w] && Edge[u][w] < MAXINT && dist[u] + Edge[u][w] < dist[w] ) {
					dist[w] = dist[u] + Edge[u][w];  path[w] = u;
				}
	}
	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	

}
void Graph::Output(const int num){//������� num�� ����0��ֵ
	cout<<"the shortest path is:";
	int a;
	cout<<endl<<num<<endl;
	a=path[num];
	while (a!=0) {
		cout<<a<<endl;
		a=path[a];
	}
	cout<<0<<endl;
	cout<<"the shortest value of the path is:"<<endl;
	cout<<dist[num]<<endl;

	}