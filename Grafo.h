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
    vector<char>sumLetras; // variable que almacena las letras y espacios en blanco &

   int arestasVertice=0;
   int k = 0; // Variavel importante: tem o conteudo do da ultima posicao onde ficou a BUSCADOS 
   int verticesIniciais[100][100]; // variavel para armazenar a sequencia de impresao 
   int verticesFinais[100][100];// variavel para armazenar a sequencia de impresao 
    vector<vector<string>> matrizAdj; // Matriz de Adjacencia 
    // a veriavel mais importante  para E-NFA
    int vertices[100]; // variavel que amazena os estados finais se a BuscaDos achar uma palavra vazia por exemplo 
    // exemplo do Prof 2 do PDF: | 1 4 2 | 

    //funcoes 
    Grafo(int vertices);
    void adicionaAresta( int v, int v2, string aresta); // vertice e vertice2
    void imprimeGrafo();
    void BuscaDos(char letra, int totalPalavras, int &caso, int num, int ultimaLetra, int estadoFinal);
};

#endif  //!GRAFO
