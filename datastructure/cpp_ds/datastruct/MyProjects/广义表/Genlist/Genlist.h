#include<string.h>
#include<iostream.h>
#include<stdlib.h>
#define HEAD 	0
#define INTGR 	1
#define CH 		2
#define LST 		3
class GenList;		//GenList��ǰ������
class GenListNode {	      //���������
friend class GenList;
public:
	int utype;
	 GenListNode *tlink;
union {
        int ref;		        //utype = 0, ��ͷ���,������ü���
        int intgrinfo;	        //utype = 1, ����	
        char charinfo;             //utype = 2, �ַ���
	   GenListNode *hlink;   //utype = 3, ���ָ���ӱ��ָ	��
	} value;
public:
    GenListNode():utype(0),tlink(NULL){}
	GenListNode & Info ( GenListNode *elem );
     int nodetype ( GenListNode *elem ) { return elem->utype; }
	 friend int equal ( GenListNode *s, GenListNode *t );   //�е�
//���ؽ�������
     void setInfo ( GenListNode *elem,GenListNode &x );
//������޸�Ϊx
};
class GenList {                    //�������
private:
//public:
    GenListNode* first;        //������ͷָ��
    GenListNode* Copy ( GenListNode* ls );
//����һ��lsָ����޹����ӱ�ķǵݹ��
    int depth ( GenListNode *ls );//�������		
    void Remove (GenListNode *ls );//ɾ��
public:
    GenList ( ); 
    //~GenList ( );
    GenListNode& Head ( );//���ص�һ��Ԫ�ص�ֵ
    GenList& Tail ( );//���ر�β
    GenListNode *First ( );//���ص�һ��Ԫ��	
    GenListNode *Next ( GenListNode *elem );//����ֱ�Ӻ��
	int CreateList ( GenListNode *ls,  char * s );
	int sever ( char *str1, char *hstr1 ) ;
    void Push ( GenListNode *x );  //��x���뵽��ǰ��
    GenList & Addon ( GenList& list,  GenListNode *x );                  //����һ����xΪͷ,listΪβ���±�
    void setHead ( GenListNode& x );//�����ͷԪ����Ϊx
    void setNext ( GenListNode *elem1,GenListNode *elem2 );
 	friend int operator==(const GenList &l,const GenList &m);
    //void delvalue(GenListNode *ls,const value x);
//��elem2���뵽elem1֮��
    void setTail ( GenList& list );	//��list����Ϊ������β
	//int equal(GenListNode *s,GenListNode *t);
    void Copy ( const GenList & l );//�����ĸ���
	void output (GenListNode *ls);
    int depth();//����ǵݹ������
    int Createlist ( GenListNode* ls, char* s );
	void returnFirst ( GenListNode *ls);
//�ӹ������ַ�������s����,����һ������ͷ���Ĺ����
};
GenListNode & GenListNode ::Info (GenListNode* elem )
 {//��ȡ�������ָ����Ԫ��elem��ֵ
     GenListNode * pitem = new GenListNode;
     pitem->utype = elem->utype;
     pitem->value = elem->value;
     return * pitem;
}
void GenListNode :: setInfo(GenListNode* elem, GenListNode& x ) 
{//����Ԫ��elem�е�ֵ�޸�Ϊx
    elem->utype = x.utype;
    elem->value = x.value; 
}
//�������Ĺ���ͷ��ʳ�Ա����

GenList :: GenList ( ) {
    first = new GenListNode;	
    first->utype = 0;  first->value.ref = 1;  
    first->tlink = NULL;     //��������ͷ���
}
GenListNode & GenList :: Head ( ) {
//�������ǿգ����ر�ı�ͷԪ�ص�ֵ
    if ( first->tlink == NULL ) {       //�ձ� 
		cout<<"Illigal head operation."<<endl;
		exit(1);
    }
    else {
 	  GenListNode * temp = new GenListNode;
       temp->utype = first->tlink->utype;
       temp->value = first->tlink->value;
       return  *temp;
    }
}
GenList & GenList :: Tail ( ) {
//�������ǿգ����ع�������ͷԪ������
//��Ԫ����ɵı�������û�ж���
    if ( first->tlink == NULL ) {       //�ձ� 
		cout<<"Illigal tail operation."<<endl;
		exit(1);
    }
    else {
       GenList * temp=NULL;
       temp->first->tlink = Copy(first->tlink->tlink);
       return  *temp;
    }
}
GenListNode *GenList::First(){
   //���ع����ĵ�һ��Ԫ�أ�����գ��򷵻�һ���ض��Ŀ�ֵ��
      if (first->tlink==NULL)  return  NULL;
      else  return  first->tlink;
}
//���ر�Ԫ��elem��ֱ�Ӻ��
GenListNode *GenList::Next(GenListNode  *elem){
  if (elem->tlink==NULL) return NULL;
  else  return  elem->tlink;
}
void GenList::Push ( GenListNode *x ) {
//������ x �ӵ������ǰ��
    if ( first->tlink==NULL) first->tlink=x; 
    else {
        x->tlink=first->tlink;  first->tlink=x;	 
    }
}
GenList & GenList::Addon ( GenList & list, GenListNode *x )
 {
//����һ����xΪͷ��listΪβ���¹����
    GenList * newlist = new GenList;
    newlist->first = Copy ( list.first );//����list��newlist
    x->tlink=newlist->first->tlink;//������x
    newlist->first->tlink = x;
    return * newlist;
}  
void GenList:: setHead(GenListNode& x ) 
{//�����ͷԪ������Ϊx
    first->tlink->utype = x.utype;
    first->tlink->value = x.value; 
}
void GenList:: setTail(GenList & list ) 
{//��list����Ϊ�����ı�β
	GenListNode *temp;
	temp=first->tlink->tlink;//tempָ������this�ı�β
	first->tlink->tlink=list.first->tlink;//this��ͷ��tlinkָ��list��ͷ
	delete list.first;//ɾȥlist��ͷ���
	//free List(temp);
}
void GenList::setNext(GenListNode *elem1,GenListNode *elem2)
{ 
	GenListNode *temp;
	while (elem1->tlink!=NULL){
		temp=elem1->tlink;
		elem1->tlink=temp->tlink;
		delete temp;
	}
		elem1->tlink=elem2;
}
void GenList::Copy ( const GenList & l ) {             
    first = Copy ( l.first );
}

GenListNode* GenList :: Copy(GenListNode *ls)
{
     GenListNode *q = NULL;
     if ( ls != NULL ) {
        q = new GenListNode;     //����һ���½��
        q->utype = ls->utype;      //���Ʊ�־ utype
		switch ( ls->utype ) {//����utype������ֵ��	
           case HEAD: 
                q->value.ref = ls->value.ref;  break; 	      
           case INTGR: 
                q->value.intgrinfo = ls->value.intgrinfo;
                break; 	          
           case CH : 
                q->value.charinfo = ls->value.charinfo;
                break;		
           case LST: 
                q->value.hlink = Copy ( ls->value.hlink );
                break;	
       }
		q->tlink = Copy ( ls->tlink );
    }
    return q;
}
int GenList::depth ( ) 
{//��������������һ���ǵݹ������
    return depth ( first );
}
int GenList :: depth ( GenListNode *ls ) {//˽�к���
    if ( ls->tlink == NULL ) return 1;   //�ձ�
    GenListNode *temp = ls->tlink;  
    int m = 0;
    while ( temp != NULL ) {       //��ɨ�������
         if ( temp->utype == LST) {      //���ӱ����
 	         int n = depth ( temp->value.hlink );			 
			 if ( m < n ) m = n; //ȡ������
         }
         temp = temp->tlink;      
    }
    return m+1;//�������
}
int equal(GenListNode *s,GenListNode *t)
{
	int x;
	if(s->tlink==NULL&&t->tlink==NULL) return 1;//��Ϊ�ձ��Ƚ���
	if(s->tlink!= NULL &&t->tlink!= NULL&&s->tlink->utype==t->tlink->utype)
	{//����ǿ��ҽ��������ͬ
		 if(s->tlink->utype==INTGR)//ͬΪ���ͽ��
		     if(s->tlink->value.intgrinfo==t->tlink->value.intgrinfo)x=1;
		     else x=0;
		  else if(s->tlink->utype==CH) //ͬΪ�ַ��ͽ��
		     if(s->tlink->value.charinfo==t->tlink->value.charinfo) x=1;
		     else x=0;  
		else x=equal(s->tlink->value.hlink,t->tlink->value.hlink); 
		//ͬΪ�ӱ��㣬�͵ݹ�Ƚ��ӱ�Ľ��
	if(x)return equal(s->tlink,t->tlink); //��ȣ��ݹ�Ƚ�ͬ�����һ����㣻���ȣ����ٵݹ�Ƚ�
	}
	return 0;
}
int operator==(const GenList &l,const GenList &m)
{//l,m���Ƿǵݹ������ȣ�����1�����򷵻�0;
	return equal(l.first,m.first);
}
/*void GenList ::delvalue(GenListNode *ls,const value x) {
//�ڹ������ɾ�����к� x �Ľ��
    if ( ls->tlink != NULL ) {			
       GenListNode * p = ls->tlink;   //��ɨ����
       while ( p !=NULL&&((p->utype==INTGR&&p->value.intgrinfo ==x)||(p->utype==CH&&p->value.charinfo ==x ) ) {
	  ls->tlink = p->tlink;   delete p;     //ɾ���ý��(��x)
           p = ls->tlink;      // pָ��ͬ����һ���
       }       
//��������������ӱ���ߵ��ӱ��
       //ͷ�����Ǻ�x���, ת��ѭ��
       if ( p != NULL ) {              
          if ( p->utype ==LST)      //���ӱ���ɾ��
              delvalue ( p->value.hlink, x );	
          delvalue (p,x);	         //���ݹ�ɾ��
      }
   }
}*/
//�й����ӱ�������ֻ�е����ü�����Ϊ0ʱ���������ͷŽ��
/*GenList :: ~GenList ( ) {	        //��������	
    Remove ( first );
} */
/*void GenList :: Remove (GenListNode *ls ) {  
    ls->value.ref --;	   //���ü�����һ
    if ( !ls->value.ref ) {  //���ü�������0����ɾ��         
       GenListNode * y = ls;				
       while ( y->tlink != NULL ) {       //��ɨ����
           y = y->tlink;
		   if ( y->utype ==LST)            //�����ӱ�
              Remove ( y->value.hlink );   //�ݹ�ɾ��        
       }
       y->tlink = av;  av = ls;
       //ɨ�����,���յ������ÿռ��	
    }
}*/
int GenList::sever ( char *str1, char *hstr1 ) {
	if(strlen(str1)==0) {hstr1=NULL;return 0;}
//�Բ�����ֽ�����ַ��������һ��Ԫ��
    char ch = str1[0];   
    int n = strlen ( str1 );
    int i = 0,  k = 0;
    //���str1,ɨ���������', '�����������ͣ
    while ( i < n && ( ch != ',' || k != 0 ) ) {
        if ( ch == '(') k++;//���������ԣ������ż�����1
        else if ( ch ==')' ) k--;//���������ţ�������1
        i++;  ch = str1[i];         // i ����, ȡһ�ַ�
    }    
	if ( i<n ) {
        strncpy( hstr1, str1, i );
        //str1��ǰ i-1 ���ַ����͵�hstr1
		hstr1[i]='\0';
        strncpy ( str1, str1+i+1, n-i );
        //��n-i���ַ�����str1, ��ȥ��,��
		str1[n-i]='\0';
        return 1;
    }
    else if ( k != 0 ) return 0;   //���Ų���Գ���
           else {	                     //�������
              strcpy ( hstr1, str1 );	*str1 =NULL;
              //str1ȫ�����͸�hstr1
              return 1;
           }
}
int GenList ::CreateList ( GenListNode *ls,  char * s ) {
   char sub[20], hsub[20];  
   ls = new GenListNode ( );    //������ͷ���
   ls->utype = HEAD;  ls->value.ref = 1;
    cout<<"love"<<ls->tlink<<"you"<<endl;
  if ( strlen (s) == 0 || !strcmp ( s,"()" ) )
  {ls->tlink = NULL;}	          //�ձ�	
  else {// cout<<"hahalial"<<endl;
		strncpy(sub,s+1,strlen(s)-2);
		sub[strlen(s)-2]='\0';
		//cout<<endl<<endl;
		//for(int j=0;j<strlen(sub);j++){
			//cout<<sub[j];}
		cout<<endl<<endl;
      //��ȥ��������������
     GenListNode* p = ls;
	  while ( strlen (sub)!= 0) {   //��������
           p = p->tlink = new GenListNode ( );
           //�����½��,���β����
           if ( sever (sub, hsub) ) {
			   //cout<<"I love you"<<strlen(sub);
           //�Զ���Ϊ��,�����һ����Ԫ��hsub
              if ( hsub[0] != '('&& hsub[0] !='\'' ) {
	      //���ӱ�,���ַ��ֽ��
                 p->utype = INTGR;    
                 p->value.intgrinfo=atoi ( hsub ); //ת�����ͽ��
				 //cout<<"shide111   "<<ls->utype<<"    love you111 ";
              } 
              else if ( hsub[0] != '(' && hsub[0] == '\'' ) {
              //���ӱ������ַ��ֽ��
				  p->utype = CH;  
				  p->value.charinfo = hsub[1];	
				  //cout<<"shide222   "<<ls->utype<<"    love you222 "<<endl;
               }
               else {                 //���ӱ�,�ݹ齨���ӱ�
                  p->utype = LST; 
				  //cout<<"shide333   "<<ls->utype<<"    love you333 "<<endl;
                  CreateList ( p->value.hlink, hsub );
               }
		   }
            else return 0;     //�ַ������ʽ�д�
			cout<<"love"<<ls->tlink<<"me"<<endl;
			cout<<"love"<<p->tlink<<"her"<<endl;
        }       //ѭ�����
        p->tlink = NULL;  //������һ�����

    }
  cout<<"lovelove"<<ls->tlink<<"meme"<<endl;
//cout<<"biaozhi "<<ls->utype<<endl;
    return 1;
}

void GenList ::output (GenListNode *ls){
	//cout<<ls->nodetype(ls)<<endl;
	cout<<"hehe i love"<<ls->tlink<<"you"<<endl;
	//cout<<ls->value.ref<<endl;
	//cout<<first->tlink;
	//cout<<ls->depth();
}
void GenList ::returnFirst (GenListNode *ls)
{
	this->first=ls;
}

