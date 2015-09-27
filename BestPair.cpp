#include <iostream>

class Edge;

class Vertex
{

    public:
        Edge a, b;
        char name;

        Vertex(char name)
        {
           this->name = name; 
           this->a = a;
           this->b = b; 
        }

        void assigneEdge(Edge a, Edge b)
        {
           this->a = a;
           this->b = b; 
        }
        

};


class Edge
{

    pubic:
        Vertex a, b;
        int number;

        Edge(int number, Vertex a, Vertex b)
        {
            this->number = number;
            this->a = a;
            this->b = b;
        }
};


int main()
{

    Vertex A('1');
    Vertex B('2');
    Vertex C('3');
    Vertex D('4');
    Vertex E('5');
  
    Edge AD(A, D); 
    Edge AC(A, C); 
    Edge EC(A, D); 
    Edge ED(A, D); 
    Edge EE(A, D); 
}
