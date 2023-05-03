#include<iostream>
#include<string>

using namespace std;


struct edge {
    int vertex1;
    int vertex2;
    int weight;
};


struct node {
    int vertex;
    node* next;
};


struct graph {
    int num_of_vertices;
    int num_of_edges;
    edge* edges;
    node* adjacency_list;
    int** adjacency_matrix;




    graph() {
        num_of_vertices = 0;
        num_of_edges = 0;
        edges = new edge;
        edges = NULL;
        adjacency_list =NULL;
        adjacency_matrix = new int*;
        adjacency_matrix = NULL ;
    }



    void add_edge(int vertex1, int vertex2, int weight) {
        edge* new_edge = new edge;
        new_edge->vertex1 = vertex1;
        new_edge->vertex2 = vertex2;
        new_edge->weight = weight;
        edges[num_of_edges] = *new_edge;
        num_of_edges++;
    }

    void add_vertex(int vertex) {
        node* new_node = new node;
        new_node->vertex = vertex;
        new_node->next = adjacency_list;
        adjacency_list = new_node;
        num_of_vertices++;
    }

    void display_adjacency_list() {
        node* temp = adjacency_list;
        while (temp != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }



};

//is_subgraph
bool is_subgraph(graph* graph1, graph* graph2) {
    if (graph1->num_of_vertices > graph2->num_of_vertices) {
        return false;
    }
    else {
        node* temp1 = graph1->adjacency_list;
        node* temp2 = graph2->adjacency_list;
        while (temp1 != NULL) {
            while (temp2 != NULL) {
                if (temp1->vertex == temp2->vertex) {
                    break;
                }
                temp2 = temp2->next;
            }
            if (temp2 == NULL) {
                return false;
            }
            temp1 = temp1->next;
        }
        return true;
    }
}


void display_graph(graph* g) {
    for (int i = 0; i < g->num_of_vertices; i++) {
        cout << "Vertex " << i << ": ";
        node* temp = new node;
        temp = g->adjacency_list[i].next;
        while (temp != NULL) {

            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
        delete g->adjacency_list;
    }
}
//output_graph_array_list
void output_graph_array_list(graph* g) {
    cout << "Output graph A from the array of lists" << endl;
    cout << "Number of vertices: " << g->num_of_vertices << endl;
    cout << "Number of edges: " << g->num_of_edges << endl;
    cout << "Edges: " << endl;
    for (int i = 0; i < g->num_of_edges; i++) {
        cout << g->edges[i].vertex1 << " " << g->edges[i].vertex2 << " " << g->edges[i].weight << endl;
    }
    cout << "Adjacency list: " << endl;
    display_graph(g);
}


void display_edges(graph* g) {
    for (int i = 0; i < g->num_of_edges; i++) {
        cout << "Edge " << i << ": " << g->edges[i].vertex1 << " " << g->edges[i].vertex2 << " " << g->edges[i].weight << endl;
    }
}


void display_adjacency_list(graph* g) {
    for (int i = 0; i < g->num_of_vertices; i++) {
        cout << "Vertex " << i << ": ";
        node* temp = g->adjacency_list[i].next;
        while (temp != NULL) {
            cout << temp->vertex << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}


void display_adjacency_matrix(graph* g) {
    for (int i = 0; i < g->num_of_vertices; i++) {
        for (int j = 0; j < g->num_of_vertices; j++) {
            cout << g->adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void create_adjacency_list(graph* g) {
    node* temp = g->adjacency_list;
    while (temp != NULL) {
        node* temp2 = temp->next;
        while (temp2 != NULL) {
            g->adjacency_matrix[temp->vertex][temp2->vertex] = 1;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}


void create_adjacency_matrix(graph* g) {
    node* temp = g->adjacency_list;
    while (temp != NULL) {
        node* temp2 = temp->next;
        while (temp2 != NULL) {
            g->adjacency_matrix[temp->vertex][temp2->vertex] = 1;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}


void create_adjacency_matrix_2(graph* g) {
    node* temp = g->adjacency_list;
    while (temp != NULL) {
        node* temp2 = temp->next;
        while (temp2 != NULL) {
            g->adjacency_matrix[temp->vertex][temp2->vertex] = 1;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
}


//intersection between two graphs
void intersection(graph* g1, graph* g2) {
    for (int i = 0; i < g1->num_of_vertices; i++) {
        for (int j = 0; j < g2->num_of_vertices; j++) {
            if (g1->adjacency_matrix[i][j] == 1 && g2->adjacency_matrix[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }
}


//union_graph
void union_graph(graph* g1, graph* g2) {
    for (int i = 0; i < g1->num_of_vertices; i++) {
        for (int j = 0; j < g2->num_of_vertices; j++) {
            if (g1->adjacency_matrix[i][j] == 1 || g2->adjacency_matrix[i][j] == 1) {
                cout << i << " " << j << endl;
            }
        }
    }
}

//the vertex (vertices) with the highest degree
void highest_degree(graph* g) {
    int max = 0;
    int vertex = 0;
    for (int i = 0; i < g->num_of_vertices; i++) {
        int count = 0;
        for (int j = 0; j < g->num_of_vertices; j++) {
            if (g->adjacency_matrix[i][j] == 1) {
                count++;
            }
        }
        if (count > max) {
            max = count;
            vertex = i;
        }
    }
    cout << "Vertex with the highest degree: " << vertex << endl;
}

//output_graph_array_struct
void output_graph_array_struct(graph* g) {
    cout << "Output graph A from the array of structs" << endl;
    cout << "Number of vertices: " << g->num_of_vertices << endl;
    cout << "Number of edges: " << g->num_of_edges << endl;
    cout << "Edges: " << endl;
    for (int i = 0; i < g->num_of_edges; i++) {
        cout << g->edges[i].vertex1 << " " << g->edges[i].vertex2 << " " << g->edges[i].weight << endl;
    }
    cout << "Adjacency list: " << endl;
    display_graph(g);
}



//output_graph_matrix
void output_graph_matrix(graph* g) {
    cout << "Output graph A from the matrix" << endl;
    cout << "Number of vertices: " << g->num_of_vertices << endl;
    cout << "Number of edges: " << g->num_of_edges << endl;
    cout << "Edges: " << endl;
    display_edges(g);
    cout << "Adjacency matrix: " << endl;
    display_adjacency_matrix(g);
}

//whether the two graphs are equal (the same graph) or not.
void is_equal(graph* g1, graph* g2) {
    bool is_equal = true;
    if (g1->num_of_vertices != g2->num_of_vertices) {
        is_equal = false;
    }
    else {
        for (int i = 0; i < g1->num_of_vertices; i++) {
            node* temp = g1->adjacency_list[i].next;
            while (temp != NULL) {
                if (g2->adjacency_matrix[i][temp->vertex] != 1) {
                    is_equal = false;
                }
                temp = temp->next;
            }
        }
    }
    if (is_equal) {
        cout << "The two graphs are equal" << endl;
    }
    else {
        cout << "The two graphs are not equal" << endl;
    }
}

//degree of a vertex
int degree(graph* g, int vertex) {
    int count = 0;
    node* temp = g->adjacency_list[vertex].next;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

//

//display_highest_degree
void display_highest_degree(graph* g) {
    int max = 0;
    int vertex = 0;
    for (int i = 0; i < g->num_of_vertices; i++) {
        int count = degree(g, i);
        if (count > max) {
            max = count;
            vertex = i;
        }
    }
    cout << "Vertex with the highest degree: " << vertex << endl;
}

//add_edge
void add_edge(graph* g, int vertex1, int vertex2, int weight) {
    g->edges= new edge;
    g->edges[g->num_of_edges].vertex1 = vertex1;
    g->edges[g->num_of_edges].vertex2 = vertex2;
    g->edges[g->num_of_edges].weight = weight;
    g->num_of_edges++;
}


/*
create main function with the following options
Please select one of the following:
1- Output graph A from the array of lists
2- Output graph A from the matrix
3- Output graph A from the array of structures/objects. 4- Output graph B from the array of lists
5- Output graph B from the matrix
6- Output graph B from the array of structures/objects. 7- The intersection between both graphs
8- The union of the two graphs
9- Is graph (A) a subgraph of graph (B)?
10- Is graph (B) a subgraph of graph (A)?
11- Display the vertex (vertices) with the highest degree from graph A. 12- Display the vertex (vertices) with the highest degree from graph B. 13- Are the graphs equal (the same graph)?
14- Exit program

User Interface:
 Please enter the number of nodes in graph A:
Please enter the number of edges in Graph A:
Please enter edge1 and its weight in the order (vertex1, vertex2, weight): Please enter edge2 and its weight in the order (vertex1, vertex2, weight):
*/


int main() {
    int num_of_vertices;
    int num_of_edges;
    int vertex1;
    int vertex2;
    int weight;
    int choice;
    graph* g1 = new graph;
    graph* g2 = new graph;
    cout << "Please enter the number of nodes in graph A: ";
    cin >> num_of_vertices;
    cout << "Please enter the number of edges in Graph A: ";
    cin >> num_of_edges;
    g1->num_of_vertices = num_of_vertices;
    g1->num_of_edges = num_of_edges;
    g1->adjacency_list = new node[num_of_vertices];
    g1->adjacency_matrix = new int* [num_of_vertices];
    for (int i = 0; i < num_of_vertices; i++) {
        g1->adjacency_matrix[i] = new int[num_of_vertices];
    }
    for (int i = 0; i < num_of_vertices; i++) {
        for (int j = 0; j < num_of_vertices; j++) {
            g1->adjacency_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < num_of_edges; i++) {
        cout << "Please enter edge" << i + 1 << " and its weight in the order (vertex1, vertex2, weight): ";
        cin >> vertex1 >> vertex2 >> weight;
        add_edge(g1, vertex1, vertex2, weight);


    }
    cout << endl;
    cout << "Please enter the number of nodes in graph B: ";
    cin >> num_of_vertices;
    cout << "Please enter the number of edges in Graph B: ";
    cin >> num_of_edges;
    g2->num_of_vertices = num_of_vertices;
    g2->num_of_edges = num_of_edges;
    g2->adjacency_list = new node[num_of_vertices];
    g2->adjacency_matrix = new int* [num_of_vertices];
    for (int i = 0; i < num_of_vertices; i++) {
        g2->adjacency_matrix[i] = new int[num_of_vertices];
    }
    for (int i = 0; i < num_of_vertices; i++) {
        for (int j = 0; j < num_of_vertices; j++) {
            g2->adjacency_matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < num_of_edges; i++) {
        cout << "Please enter edge" << i + 1 << " and its weight in the order (vertex1, vertex2, weight): ";
        cin >> vertex1 >> vertex2 >> weight;
        add_edge(g2, vertex1, vertex2, weight);
    }
    cout << endl;
    cout << "Please select one of the following: " << endl;
    cout << "1- Output graph A from the array of lists" << endl;
    cout << "2- Output graph A from the matrix" << endl;
    cout << "3- Output graph A from the array of structures/objects. 4- Output graph B from the array of lists" << endl;
    cout << "5- Output graph B from the matrix" << endl;
    cout << "6- Output graph B from the array of structures/objects. 7- The intersection between both graphs" << endl;
    cout << "8- The union of the two graphs" << endl;
    cout << "9- Is graph (A) a subgraph of graph (B)?" << endl;
    cout << "10- Is graph (B) a subgraph of graph (A)?" << endl;
    cout << "11- Display the vertex (vertices) with the highest degree from graph A. 12- Display the vertex (vertices) with the highest degree from graph B. 13- Are the graphs equal (the same graph)?" << endl;
    cout << "14- Exit program" << endl;
    cout << "Please enter your choice: ";
    cin >> choice;
    while (choice != 14) {
        if (choice == 1) {
            output_graph_array_list(g1);
        }
        else if (choice == 2) {
            output_graph_matrix(g1);
        }
        else if (choice == 3) {
            output_graph_array_struct(g1);
        }
        else if (choice == 4) {
            output_graph_array_list(g2);
        }
        else if (choice == 5) {
            output_graph_matrix(g2);
        }
        else if (choice == 6) {
            output_graph_array_struct(g2);
        }
        else if (choice == 7) {
            intersection(g1, g2);
        }
        else if (choice == 8) {
            union_graph(g1, g2);
        }
        else if (choice == 9) {
            is_subgraph(g1, g2);
        }
        else if (choice == 10) {
            is_subgraph(g2, g1);
        }
        else if (choice == 11) {
            display_highest_degree(g1);
        }
        else if (choice == 12) {
            display_highest_degree(g2);
        }
        else if (choice == 13) {
            is_equal(g1, g2);
        }
        cout << "Please enter your choice: ";
        cin >> choice;
    }
    return 0;
}