#include <iostream>

 using namespace std;
 const int tamanho = 8;

 //DEFININDO A ESTRUTURA DE HASH
 struct hash
 {
 int chave;
 hash* proximo;
 };

 //FUN플O PARA INSERIR NA TABELA
 void inserir(hash* tabela[], int posicao, int numero)
 {
 cout << " \n == INSERINDO == \n ";
 hash* novo;
 novo = new hash();
 novo->chave = numero;
 novo->proximo = tabela[posicao];
 tabela[posicao] = novo;
 cout << " \n Elemento " << novo->chave << " inserido com sucesso! \n ";
 }

 //FUN플O QUE CALCULA A CHAVE - FUN플O HASHING
 int hashing(int numero)
 {
 cout << " \n == FUNCAO HASHING == \n";
 return numero % tamanho;
 }

 //FUN플O PARA IMPRIMIR A TABELA
 void imprimir(hash* tabela[])
 {
 cout << " \n == IMPRIMINDO == \n";
 hash* aux;
 for(int i =0; i<tamanho; i++)
 {
 aux = tabela[i];
 while(aux != NULL)
 {
 cout << " \n Entrada: " << i << " Chave: " << aux->chave;
 aux = aux->proximo;
 }
 }
 cout << "\n";
 }

 //FUN플O PARA EXCLUIR UM ELEMENTO DA TABELA
 void excluir(hash* tabela[], int numero)
 {
 cout << " \n == EXCLUINDO == \n";
 int posicao = hashing(numero);
 hash* aux;
 if(tabela[posicao] != NULL)
 {
 if(tabela[posicao]->chave == numero)
 {
 aux = tabela[posicao];
 tabela[posicao] = tabela[posicao]->proximo;
 cout << " \n Numero " << aux->chave << " excluido com sucesso! \n";
 delete aux;
 }
 else
 {
 aux = tabela[posicao]->proximo;
 hash* ant = tabela[posicao];

 while(( aux != NULL ) && ( aux->chave != numero ))
 {
 ant = aux;
 aux = aux->proximo;
 }

 if( aux != NULL )
 {
 ant->proximo = aux->proximo;
 cout << " \n Numero " << aux->chave << " excluido com sucesso! \n";
 delete aux;

 }
 else
 {
 cout << " \n Numero nao encontrado! \n";85 }

 }
 }
 else
 {
 cout << " \n Numero nao encontrado! \n";
 }
 }

 //FUN플O PARA INICIALIZAR A TABELA
 void inicializar(hash* tabela[])
 {
 cout << " \n == INICIALIZANDO == \n";
 for(int i =0; i<tamanho; i++)
 {
 tabela[i] = NULL;
 }
 }

 void destruir(hash* tabela[])
 {
 cout << " \n == DESTRUINDO == \n";
 hash* aux;
 for(int i =0; i<tamanho; i++)
 {
 while(tabela[i]!=NULL)
 {
 aux = tabela[i];
 tabela[i] = tabela[i]->proximo;
 delete aux;
 }
 }
 }

 int main()
 {
 hash* tabela[tamanho];
 hash* aux;
 int opcao, posicao, numero;

 //MENU
 do
 {
 cout << " \n | MENU |";
 cout << " \n | 1. Inicializar |";
 cout << " \n | 2. Inserir |";
 cout << " \n | 3. Excluir |";
 cout << " \n | 4. Imprimir |";
 cout << " \n | 5. Destruir |";
 cout << " \n | 6. Sair |";
 cout << "\n";
 cout << " \n Digite a opcao desejada: ";
 cin >> opcao;

 switch(opcao)
 {
 case 1:
 inicializar(tabela);
 break;
 case 2:
 cout << " \n Digite um numero: ";
 cin >> numero;
 posicao = hashing(numero);
 inserir(tabela, posicao, numero);
 break;
 case 3:
 cout << " \n Digite um numero: ";
 cin >> numero;
 excluir(tabela, numero);
 break;
 case 4:
 imprimir(tabela);

 break;
 case 5:
 destruir(tabela);
 break;
 default:
 cout << " \n OPCAO INVALIDA ";
 }

 }
 while(opcao!=6);169 return
0
;

}
