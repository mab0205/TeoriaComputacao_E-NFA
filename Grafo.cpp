#include <bits/stdc++.h>

using namespace std;

#include "Grafo.h"

Grafo::Grafo(int vertices){ // cria o grafo e para cada novo vertice, ele muda o tamanho do grafo 
    numVertices = vertices;
    matrizAdj.resize(numVertices);
    for (int i = 0; i < numVertices; i++) {
        matrizAdj[i].resize(numVertices);
        for (int j = 0; j < numVertices; j++)  {
            matrizAdj[i][j] = "";
        }
    }
}

// Função para criar uma  (v)aresta   (v2)VERTICE    (alfabeto)NUMERO OU ARESTA
void Grafo::adicionaAresta(int v, int v2, string aresta){
    matrizAdj[v][v2] = aresta;
}
//funcao para testar o conteudo da amtriz de adjacencia 
void Grafo::imprimeGrafo(){
    for (int i = 0; i < numVertices; i++) {
        cout << i << "->";
        for (int j = 0; j < numVertices; j++)
        {
            cout << matrizAdj[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void Grafo::BuscaDos(char letra, int totalPalavras, int &caso,int num, int ultimaLetra, int estadoFinal ){
    // vairaveis aux, servem para o tratamento de Erros do programa 
    int aux3 = k;
    int aux=0;
    int h = 0;
    bool aux4 = false;

    for (int i = 0; i < numVertices; i++){
       
        if ( matrizAdj[k][estadoFinal].find('&') != string::npos  and (num == ultimaLetra || vertices[h-1] == estadoFinal) ){  //se o grafo termina com um estado vazio entra aqui
           if(num>2 or aux4==false ){
            sumLetras.push_back(letra);//07/05
            verticesFinais[totalPalavras][arestasVertice] = k;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;
            }

           sumLetras.push_back('&');//07/05
            verticesFinais[totalPalavras][arestasVertice] = estadoFinal;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;

            k=estadoFinal;
            i=numVertices+14332;

        }else if (matrizAdj[k][i].find('&') != string::npos) { // se ele achar alma palvra vazia entra as posicoes entra aqui 
            int j = 0;

            for (l=0; l < numVertices; l++) {
                if (matrizAdj[k][l].find('&') != string::npos) {
                    vertices[h] = l;
                    h++;
                }   
            }

            if( l == numVertices and h == 1 ){ //tratamento de erro se a letra que o usuario entra e' so uma e tem uma palvra azia antes dele 
                 sumLetras.push_back('&');//07/05
                   verticesFinais[totalPalavras][arestasVertice] =  vertices[h-1];
                   verticesIniciais[totalPalavras][arestasVertice] = k;
                   arestasVertice++;
                    k=vertices[h-1];
                    h--;
                    j=numVertices;
                    
                   if(num == ultimaLetra and num < 2) num++; //cambio
                    i=0;
            } else aux = vertices[aux2]; // | 1 4 | aux = 1  aux2=0
             
            for (; j < numVertices; j++) {
                if (matrizAdj[aux][j].find(letra) != string::npos) {
                    // armazena o & anterior 
                    //aux++;
                    sumLetras.push_back('&');
                     verticesFinais[totalPalavras][arestasVertice] = vertices[aux2];
                     if(aux2-2 < 0) verticesIniciais[totalPalavras][arestasVertice] = 0;
                     else verticesIniciais[totalPalavras][arestasVertice] = vertices[aux2-2];
                     arestasVertice++;

                   verticesFinais[totalPalavras][arestasVertice] = j;
                   verticesIniciais[totalPalavras][arestasVertice] = aux;
                   arestasVertice++;
                   sumLetras.push_back(letra);//07/05
                   aux4 = true;
                    k=j;
                    
                    if(num == ultimaLetra){
                       // cout<<"entro"<< vertices[h-1] <<endl;
                        i=j;
                    }else i=numVertices; //si no quiero que se vaya a la proxima palabra hay que comentar
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
                     // armazena o & anterior 
                     sumLetras.push_back('&');
                     verticesFinais[totalPalavras][arestasVertice] = vertices[aux2-1];
                     if(aux2-2 < 0) verticesIniciais[totalPalavras][arestasVertice] = 0;
                     else verticesIniciais[totalPalavras][arestasVertice] = vertices[aux2-2];

                     arestasVertice++;
                    aux2++;
                    
                    aux=vertices[aux2];
                    j=0;//07/05
                }  
              
            }
            for (int v = 0; v < h; v++){
                if (h>10){
                
                 exit(0);}
              
                }

        }else if (matrizAdj[k][i].find(letra) != string::npos) { // entra aqui se ja nao tem mais palrvras vazias antes da letra e se bater as posicoes da matrizAdj com a letra 
            verticesFinais[totalPalavras][arestasVertice] = i;
            verticesIniciais[totalPalavras][arestasVertice] = k;
            arestasVertice++;
            sumLetras.push_back(letra);//07/05
            aux4 = true;
            k = i;
            caso = 1;
            if(num == ultimaLetra){
            }else i=numVertices; // proxima palabra 
            
         // se nao encuentra a letra nos siguientes estados ligados
       } else if ((i+1 == numVertices) and  (aux3 == k) and (matrizAdj[k][k].find(letra) == string::npos) ){ //if chagou ate final de matrizAdj..and..k nao mudou ..and.. el vertice vai para ele mesmo  
            
             caso = 0;
            verticesFinais[totalPalavras][arestasVertice-1]=-1;
        }
    }  
 }
    