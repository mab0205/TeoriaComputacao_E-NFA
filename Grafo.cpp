#include <bits/stdc++.h>

using namespace std;

#include "Grafo.h"

Grafo::Grafo(int vertices){
    numVertices = vertices;
    matrizAdj.resize(numVertices);
    for (int i = 0; i < numVertices; i++) {
        matrizAdj[i].resize(numVertices);
        for (int j = 0; j < numVertices; j++)  {
            matrizAdj[i][j] = "";
        }
    }
}

// Função para criar uma aresta   VERTICE    NUMERO OU ARESTA
void Grafo::adicionaAresta(int v, int v2, string aresta){
    matrizAdj[v][v2] = aresta;
}



void Grafo::Busca(char letra, int totalPalavras){
    for (int i = 0; i < numVertices; i++){
        if (matrizAdj[k][i].find(letra) != string::npos) {
            verticesFinais[totalPalavras][arestasVertice] = i;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;
            k = i;
        }
    }
}

void Grafo::BuscaDos(char letra, int totalPalavras, int &caso,int num, int ultimaLetra, int estadoFinal ){
    int aux3 = k;
    int aux=0;
    int h = 0;
    for (int i = 0; i < numVertices; i++){
        if (matrizAdj[k][i].find('&') != string::npos) {


            for (; l < numVertices; l++) {
                if (matrizAdj[k][l].find('&') != string::npos) {
                    vertices[h] = l;
                    h++;
                }
            }
        
             aux = vertices[aux2]; // | 1 4 | aux = 1
             
            for (int j = 0; j < numVertices; j++) {
                if (matrizAdj[aux][j].find(letra) != string::npos) {
                   verticesFinais[totalPalavras][arestasVertice] = j;
                   verticesIniciais[totalPalavras][arestasVertice] = aux;
                   arestasVertice++;
                    k=j;
                    i=j;
                    j=numVertices;
                    caso = 1;
                } else if (matrizAdj[aux][j].find('&') != string::npos) { // 1 y 2 tienen &
                    vertices[h]=j;//| 1 4 2 |---> uso el 1 entonces |4 2|
                    h++;
                    aux2++;
                    aux=vertices[aux2]; //ahora vamos usar aux = 4
                    j=0;
                } else if (j+1 == numVertices and aux2<h) { // si se va acabar el vector que contiene las posiciones & y si aun hay algun valor dentro de vertices[]
                    aux2++;
                    aux=vertices[aux2];
                    j=0;
                }  
               // imprimeGrafo();
            }
            for (int v = 0; v < h; v++)cout<< "D:" << vertices[v]<<endl; 
        }else if (matrizAdj[k][i].find(letra) != string::npos) {
            verticesFinais[totalPalavras][arestasVertice] = i;
            verticesIniciais[totalPalavras][arestasVertice] = k;
           arestasVertice++;
            k = i;
            caso = 1;
         // si no encuentra la letra en los siguientes estados ligados
       } else if (i+1 == numVertices and k == aux3 and matrizAdj[k][k].find(letra) == string::npos ){ //if chagou ate final de matrizAdj..and..k nao mudou ..and.. el vertice vai para ele mesmo  
            cout << "cago"<<k<<endl;
             caso = 0;
        }}  
 }
    