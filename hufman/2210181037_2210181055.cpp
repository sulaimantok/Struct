#include<iostream>
#include<vector>
#include<iomanip>
#include<string>
#include<math.h>

using namespace std;

struct node
{
	node * leftChild;
	node * rightChild;
	double frequency;
	char content;
	string code;
};

struct input
{
	char letter;
	int count;
};

struct huffmanCode
{
	char character;
	string value;
};

vector<node> nodeArray;
node root;
vector<huffmanCode> v;

node extractMin()
{
double temp = (double) INT8_MAX;
vector<node>::iterator i1,pos;
for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
{
 if(temp>(*i1).frequency)
 {
    pos = i1;
    temp = (*i1).frequency;
 }
}

 node tempNode = (*pos);
 nodeArray.erase(pos);

 return tempNode;
}

node getHuffmanTree()
{
 while(!nodeArray.empty())
 {
	 node *tempNode= new node;
	 node *tempNode1= new node;
	 node *tempNode2= new node;
	 *tempNode1=extractMin();
	 *tempNode2=extractMin();
	 tempNode->leftChild=tempNode1;
	 tempNode->rightChild=tempNode2;
	 tempNode->frequency=tempNode1->frequency+tempNode2->frequency;
	 nodeArray.push_back(*tempNode);
	 if(nodeArray.size()==1)
	 {
		 break;
	 }
 }
 return nodeArray[0];
}


void encodeData(node * temproot,string s,vector<huffmanCode> &v)
{
	node *root1=new node;
	root1=temproot;
	root1->code=s;
	if(root1==NULL)
	{

	}
	else if(root1->leftChild==NULL && root1->rightChild==NULL)
	{
		huffmanCode h;
		h.character=root1->content;
		h.value=root1->code;
		v.push_back(h);
		cout<<"content is "<< root1->content <<" and its corresponding Huffman code is "<<root1->code<<endl;
	}
	else
	{
		root1->leftChild->code=s.append("0");
		s.erase(s.end()-1);
		root1->rightChild->code=s.append("1");
		s.erase(s.end()-1);
		encodeData(root1->leftChild,s.append("0"),v);
		s.erase(s.end()-1);
		encodeData(root1->rightChild,s.append("1"),v);
		s.erase(s.end()-1);
	}

}

void getEncodedData(node *p,string str,string &encode)
{
	for(unsigned i=0;i<str.size();i++)
	{
	for(unsigned j=0;j<v.size();j++)
	{
		char a=str[i];
		if(v[j].character==a)
		{
			encode=encode+v[j].value;
		}
	}
	}
}

string getStrings(node * temproot,string str)
{
	 string res = "";
	    node *tempnode = temproot;
	    for (unsigned i = 0; i != str.size(); ++i)
	    {
	        if (str[i] == '0') { // left child
	        	tempnode = tempnode->leftChild;
	        } else { // rigth child
	        	if (str[i] == '1')
	        		tempnode = tempnode->rightChild;
	        }
	        if (tempnode->leftChild==NULL && tempnode->rightChild==NULL)
	        {
	            res += tempnode->content;
	            tempnode = temproot;
	        }
	    }
	    return res;

}

void sortChar(string &arr)
{
	bool swapped;

		 do{
			 swapped=false;
			 for(unsigned j=0;j<arr.size()-1;j++)
			 	 {
				 	 if(arr[j]>arr[j+1])
				 	 {
				 		 swap(arr[j],arr[j+1]);
				 		 swapped=true;
				 	 }
			 	 }
		 }while(swapped);
}



void decode(string s)
{
	cout<<endl<<"Decoded Data is : "<<getStrings(&root,s)<<endl<<endl;
}


void getHuffmanCode()
{
 vector<input> characters;
 unsigned i;
 int count=1;
 string name;
 cout<<"please enter your input to encode"<<endl;
 getline(cin,name);
 string name1=name;
 for(i=0;i<name.size();i++)
 {
	 sortChar(name);
 }
 for(i = 0;i<name.size();i++)
	 {
		 if(name[i]==name[i+1])
		 {
			 count++;
		 }
		 else
		 {
			 input temp;
			 temp.letter=name[i];
			 temp.count=count;
			 characters.push_back(temp);
			 count=1;
		 }
	 }
 for(i = 0;i<characters.size();i++)
 {
  node tempNode;

  tempNode.frequency = characters[i].count;
  tempNode.content = characters[i].letter;
  tempNode.leftChild = NULL;
  tempNode.rightChild = NULL;
  nodeArray.push_back(tempNode);
 }
 root = getHuffmanTree();
 string encode;
 encodeData(&root,"",v);
 getEncodedData(&root,name1,encode);
 cout<<"Encoded data is : "<<encode<<endl;
 decode(encode);
}



int main()
{
 getHuffmanCode();
 return 0;
}