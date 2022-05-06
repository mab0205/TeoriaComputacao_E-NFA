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

void Grafo::BuscaDos(char letra, int totalPalavras, int &caso,int num, int ultimaLetra, int estadoFinal ){
    int aux3 = k;
    int aux=0;
    int h = 0;
   //cout<<"el num"<< num << estadoFinal<< endl;
    for (int i = 0; i < numVertices; i++){
        cout<<k<<"badbunny" << "el num "<< num <<"EF: "<< estadoFinal<< " vertices H"<< vertices[h-1] <<endl;
        if ( matrizAdj[k][estadoFinal].find('&') != string::npos  and (num == ultimaLetra || vertices[h-1] == estadoFinal) ){ //or (vertices[h-1] == estadoFinal  and vertices[h-1] == estadoFinalsolo he cambiado aqui
            cout<<"estadoFinal" <<endl;
            verticesFinais[totalPalavras][arestasVertice] = estadoFinal;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;
            k=estadoFinal;
            i=numVertices+14332;

        }/*else if(  matrizAdj[k][estadoFinal].find('&') != string::npos and vertices[h-1] == estadoFinal){
            cout<<"estadoFinal" <<endl;
            verticesFinais[totalPalavras][arestasVertice] = estadoFinal;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;
            k=estadoFinal;
            i=numVertices+14332;

        }*/ else if (matrizAdj[k][i].find('&') != string::npos) {
            cout<<"&"<<endl;
            int j = 0;

            for (l=0; l < numVertices; l++) {
                if (matrizAdj[k][l].find('&') != string::npos) {
                    vertices[h] = l;
                    h++;
                }   
            }

            if( l == numVertices and h == 1 ){ //tratamento de erro 
                cout<<"entro aquiii"<< "i: "<< i<<endl;
                    k=vertices[h-1];
                    h--;
                    j=numVertices;
                   //cout<<"entro aquiii"<< "aux3: "<< aux3<<endl;
                    i=0;
                   
            } else aux = vertices[aux2]; // | 1 4 | aux = 1  aux2=0
             
            for (; j < numVertices; j++) {
                if (matrizAdj[aux][j].find(letra) != string::npos) {
                   verticesFinais[totalPalavras][arestasVertice] = j;
                   verticesIniciais[totalPalavras][arestasVertice] = aux;
                   arestasVertice++;
                    k=j;
                    
                    if(num == ultimaLetra){
                        cout<<"entro"<< vertices[h-1] <<endl;
                        i=j;
                    }else
                     i=numVertices; //si no quiero que se vaya a la proxima palabra hay que comentar
                    j=numVertices;
                    caso = 1;           
                    
                } else if (matrizAdj[aux][j].find('&') != string::npos) { // 1 y 2 tienen &
                    vertices[h]=j;//| 1 4 2 |---> uso el 1 entonces |4 2|
                    h++;
                    aux2++;
                    aux=vertices[aux2]; //ahora vamos usar aux = 4
                    j=0;
                } else if (j+1 == numVertices and aux2<h) { // si se va acabar el vector que contiene las posiciones & y si aun hay algun valor dentro de vertices[]
                     //| 1 4 2 |--->ahora vamos usar aux = 2
                    aux2++;
                    aux=vertices[aux2];
                    j=0;
                }  
               // imprimeGrafo();
            }
            for (int v = 0; v < h; v++){
                if (h>10){
                 cout<< "verga";
                 exit(0);}
                cout<< "D:" << vertices[v]<<endl; 
                }
            cout<< "K:" << k<<endl;

        }else if (matrizAdj[k][i].find(letra) != string::npos) {
            verticesFinais[totalPalavras][arestasVertice] = i;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;
            k = i;
            caso = 1;
           // cout << "hola"<<k<<endl;
            //if(num!=estadoFinal) num++;// aumenta el nuemro de de estados visitados del main(i), nooo descomentar
            i = numVertices; //si no quiero que se vaya a la proxima palabra hay que comentar 
            
         // si no encuentra la letra en los siguientes estados ligados
       } else if ((i+1 == numVertices) and  (aux3 == k) and (matrizAdj[k][k].find(letra) == string::npos) ){ //if chagou ate final de matrizAdj..and..k nao mudou ..and.. el vertice vai para ele mesmo  
            //cout<< "aux3: "<< aux3<<endl;
            cout << "cago"<<k<<endl;
             caso = 0;
            verticesFinais[totalPalavras][arestasVertice-1]=-1;
        }
    }  
 }
    