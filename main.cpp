#include <bits/stdc++.h>

using namespace std;

#define MAX 100
#include "Grafo.h"

int main(int argc, char const *argv[]){
    //*Alfabeto y Estados
    int A, Q;        // A: Tamanho do alfabeto   Q: Estados
    string alfabeto; // alfabeto Σ
    cin >> A >> alfabeto;
    cin >> Q; // Q: numero de estados

    //*Numero de Estado finais e quias sao
    int F, finais[MAX]; // F:Numero de Estado finais  finais:Quias sao
    cin >> F;
    for (int i = 0; i < F; i++){
        cin >> finais[i];
    }

    // 0 e o estado inicial
    int X[MAX], Y[MAX], x, y; // estados de 0 ---> Q
    vector<string> str;       // variavel recebe  a string que pertence a o alfabeto ou * para acabar o programa
    char vazio;               // Transicoes vazias (ε) representadas &
    string str2("*");
    string palavra;
    int tam = 0, i = 0, j = 0;

    //*Entrada do Usuario
    vector<string> w;
    int tamPalavras;

    Grafo g(Q);

    while (palavra.compare(str2) != 0){
        cin >> x >> palavra >> y;
        if (palavra.compare(str2) != 0){
            str.push_back(palavra);
            g.adicionaAresta(x, y, palavra);
        }
    }

    palavra = "0";
    int totalPalavras = 0;
    
    while (palavra.compare(str2) != 0){
        //g.l=0;
        g.aux2=0;
        g.k = 0;
        int caso = 1;
        cin >> palavra;
        if (palavra.compare(str2) != 0) {
            for (int i = 0; i < palavra.length(); i++) {
                cout<< endl << palavra[i] << ": LETRA"<<endl  ;
                //cout<<"tam"<<palavra.length()<<endl;
                 g.BuscaDos(palavra[i], totalPalavras , caso , i+1, palavra.length(), finais[0]);
               if (caso == 0){
                    i=palavra.length();
                }
            }

            // ver los estados finales y comparar con el vector de pais
            for (int i = 0; i < F; i++){
                if (g.verticesFinais[totalPalavras][g.arestasVertice - 1] == finais[i]) { // imprime si es aceptada la palabra
                    cout << palavra << ": sim" << endl;
                     //cout << caso << ": caso" << endl;
                    for (int u = 0; u < g.arestasVertice; u++)
                        cout << g.verticesIniciais[totalPalavras][u] << " -> " << palavra[u] << " -> " << g.verticesFinais[totalPalavras][u] << endl;
                    break;
                }
                else
                    cout << palavra << ": nao" << endl;
            }
            cout << endl
                 << "........................................" << endl;
        }
        for(int h; h<100; h++) g.vertices[h]=0;
        g.arestasVertice = 0;
        totalPalavras++;
    }
//g.imprimeGrafo();

    /*
    for (int i = 0; i < g.k; i++){
        cout<< g.verticesFinais[i]<<endl;
    }*/

    /* tamPalavras = i;
     g.imprimeGrafo

     g.Busca('a');
     */

    return 0;
}
