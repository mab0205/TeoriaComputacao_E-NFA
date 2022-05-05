#ifndef GRAFO
#define GRAFO

#include <bits/stdc++.h>

using namespace std;

class Grafo { // estrutua Grafo com um int apontado para o primeiro int e uma struct para a proxima lista de adjacencia
   int numVertices;
   
   public:
    int l = 0;
    int z=0;
    int aux2=0;

   int arestasVertice=0;
   int k = 0;
   int verticesIniciais[100][100];
   int verticesFinais[100][100];
    vector<vector<string>> matrizAdj;
    int vertices[100];
    Grafo(int vertices);
    void adicionaAresta( int v, int v2, string aresta); // vertice e vertice2
    void imprimeGrafo();
    void Imprimir(char letra);
    void Busca(char letra, int totalPalavras);
    void BuscaDos(char letra, int totalPalavras, int &caso, int num, int ultimaLetra, int estadoFinal);
};

#endif  //!GRAFO
