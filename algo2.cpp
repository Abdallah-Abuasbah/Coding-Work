#include<iostream>
#include<vector>
using namespace std;
class Glist
{
private :
	vector<int> *adj;
	int size; 
	int* in;
	int* out;
public :

	Glist(int s)
	{
		size = s; 
		adj = new vector<int>[size];
		in = new int[size];
		out = new int[size];
		for (int i = 0; i < s; i++)
			in[i] = out[i] = 0; 
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
		out[u]++;
		in[v]++;
	}
	
	void  CountEdges()
	{
		int sum = 0; 
		for (int i = 0;i < size; i++)
		{
			sum += in[i]; 
        }

		cout << "number of edges is " << sum << endl; 
	}
	
	void indegree(int v )
	{
		if (v >= size || v < 0)
		cout << "this vertix is ot valid ...\n";
		else 
		cout << "indegree of vertix " << v << " is : " << in[v] << endl;
	}

	void outdegree( int v  )
	{
		if (v >= size || v < 0)
		cout << "this vertix is ot valid ...\n";
		else 
		cout << "outdegree of vertix " << v << " is : " << out[v] << endl;
	}

	void FindEdge(int a1, int a2)
	{
		if (a1 >= 0 && a1 < size)
		{
			for (int i = 0;i < adj[a1].size(); i++)
			{
				if (adj[a1].at(i) == a2)
				{
					cout << "\nEdge is found ...\n";
					return;
				}
			}
			cout << "\nEdge is not found ...\n";

		}
		cout << "something go wrong ( number of vertix is not correct ) ...\n"; 
	}

	void printGraph( )
	{
		for (int v = 0; v < size; ++v)
		{
			if (adj[v].empty())
			{
				continue;
			}
			cout << "\n Adjacency list of vertex "<< v << "\n head ";
			for (auto x : adj[v])
				cout << "-> " << x;
			cout<<endl;
		}
	}
};
class Gmatrix
{
private:
	bool** adjMatrix;
	int vertexnum;
	int* in; 
	int* out; 

public:
	Gmatrix(int x) 
	{
	    vertexnum = x;
		in = new int[vertexnum];
		out = new int[vertexnum];
		
		for (int i = 0; i < vertexnum; i++)
		in[i] = out[i] = 0;
		
		
		adjMatrix = new bool* [vertexnum];
		for (int i = 0; i < vertexnum; i++)
		{
			adjMatrix[i] = new bool[vertexnum];
			
			for (int j = 0; j < vertexnum; j++)
				adjMatrix[i][j] = false;
		}
	}

	void addEdge(int i, int j)
	{
		adjMatrix[i][j] = true;
		adjMatrix[j][i] = true;
		out[i]++; 
		in[j]++;
		
	}

	void printGraph()
	{
		for (int i = 0; i < vertexnum; i++) {
			cout << i << " : ";
			for (int j = 0; j < vertexnum; j++)
				cout << adjMatrix[i][j] << " ";
				
			cout << "\n";
		}
		cout << "______\n";
	}

	void FindEdge()
	{
	
		cout << "Enter two vertix to search for Edge: ";
		int a1,a2;
	    cout<<"Enter vertix one: ";cin>>a1;
	    cout<<"   Enter vertix two: "; cin>>a2;
		if (adjMatrix[a1][a2] == 1)
		{

			cout << "\nThe edge exists" << endl;

		}
		else
		{

			cout << "\nThe edge does not exist" << endl;

		}
	}

	void CountEdges()
	{

		int i, j, k = 0;

		for (i = 0; i < vertexnum; i++)

		{

			for (j = 0; j < vertexnum; j++)

			{

				if (adjMatrix[i][j] == 1)

				{

					k++;

				}

			}

		}
		cout << "The Number Of Edges is --> " << k/2 << endl;
		cout << "______\n"; 
	}

	void indegree(int v)
	{
		if (v >= vertexnum || v < 0)
		cout << "this vertix is ot valid ...\n";
		else
		cout << "indegree of vertix " << v << " is : " << in[v] << endl; 
	}

	void outdegree(int v)
	{
		if (v >= vertexnum || v < 0)
		cout << "this vertix is ot valid ...\n";
		else 
		cout << "outdegree of vertix " << v << " is : " << out[v] << endl;
	}

	~Gmatrix() {
		for (int i = 0; i < vertexnum; i++)
		delete[] adjMatrix[i];
		delete[] adjMatrix;
	}
};
int main()
{
    
    int key;
    cout << "1-adjacency list Graph.\n";
	cout << "2-adjacency matrix Graph.\n";
	cin >> key;
	if(key==1)
	{
	Glist A(10);
	
	A.addEdge( 0, 1);
	A.addEdge( 0, 4);
	A.addEdge( 1, 2);
	A.addEdge( 1, 3);
	A.addEdge( 1, 4);
	A.addEdge( 2, 3);
	A.addEdge( 3, 4);
	A.printGraph();
	cout<<endl;
	int in;cout<<"choose vertix to find indegree: ";cin>>in;
	A.indegree(in);
	int out;cout<<"choose vertix to find outdegree: ";cin>>out;
	A.outdegree(out);
	cout<<"Enter two vertix to search for Edge:    ";
	int a1,a2;
	cout<<"Enter vertix one: ";cin>>a1;
	cout<<"   Enter vertix two: "; cin>>a2;
	A.FindEdge(a1,a2);
	
    cout<<"\ndone.";
}
	else if(key==2)
	{
	Gmatrix G(4);
	
	G.addEdge(0, 1);
	G.addEdge(0, 2);
	G.addEdge(1, 2);
	G.addEdge(2, 3);
	G.printGraph(); 
	G.CountEdges();
	int in;cout<<"choose vertix to find indegree: ";cin>>in;
	G.indegree(in);
	int out;cout<<"choose vertix to find outdegree: ";cin>>out;
	G.outdegree(out);
	G.FindEdge();
	
	cout<<"\ndone.";
	}
	else
	cout<<"wrong choise...\n";
}


