/*
 * Exercício para nota 01.
 *
 * Prof. Me. Orlando Saraiva Jr
 * Aplicado em : 28/09/2024
 */

#include <iostream>
#include <string>

#define TAMANHO_PILHA 10

using namespace std;

struct Carro {
    string  placa;
    int     ano;
};

struct Pilha {
    Carro   data[TAMANHO_PILHA];
    int     contador;
};
/* Protótipos das funções. Desenvolver a partir da linha 59 */
void inicializar(Pilha *estacionamento);
void estacionar(Pilha *estacionamento, string placa, int ano);
void estacionar(Pilha *estacionamento, Carro);
Carro sair(Pilha *estacionamento);
void imprime_pilha(Pilha *estacionamento);
void imprime_tudo(Pilha *estacionamento);
int quantidade_vagas(Pilha estacionamento);


int main() {
    Pilha estacionamento;
    inicializar(&estacionamento);
    Carro carro_comum;

    estacionar(&estacionamento,"ABC1234", 1999);
    carro_comum.placa = "DOW5782";
    carro_comum.ano = 2004;
    estacionar(&estacionamento, carro_comum);
    cout << "Quantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_pilha(&estacionamento);
    estacionar(&estacionamento,"XYZ3215", 2022);
    estacionar(&estacionamento,"WQT2245", 2020);
    estacionar(&estacionamento,"GIN3285", 2017);
    estacionar(&estacionamento,"HIX5215", 2008);
    imprime_pilha(&estacionamento);

    carro_comum = sair(&estacionamento);
    cout << "Saiu o carro: " << carro_comum.placa << endl;
    imprime_pilha(&estacionamento);
    cout << "Quantidade de vagas " << quantidade_vagas(estacionamento) << endl;
    imprime_tudo(&estacionamento);

}

/* Desenvolver as funções propostas a partir daqui */
void inicializar(Pilha *estacionamento) {
    estacionamento->contador = 0;
    int x;
	for (x = TAMANHO_PILHA-1; x >= 0 ; x--){
		estacionamento->data[x].placa = "AAA0000" ;
        estacionamento->data[x].ano = 0 ;
    }
}

void estacionar (Pilha *estacionamento, string placa, int ano){
	if (estacionamento->contador < TAMANHO_PILHA){
		estacionamento->data[estacionamento->contador].placa = placa;
		estacionamento->data[estacionamento->contador].ano = ano;
		estacionamento->contador++;
	} else {
		cout << "Estacionamento cheio" << endl;
	}
	
}

void estacionar(Pilha *estacionamento, Carro carro_comum){
	if (estacionamento->contador < TAMANHO_PILHA){
		estacionamento->data[estacionamento->contador] = carro_comum;
		estacionamento->contador++;
	} else {
		cout << "Estacionamento cheio!!" << endl;
	}
}

Carro sair(Pilha *estacionamento) {
	if (estacionamento->contador > 0) {
		estacionamento->contador--;
		Carro desempilhar = estacionamento->data[estacionamento->contador];
		estacionamento->data[estacionamento->contador].placa = "XXX0000";
		estacionamento->data[estacionamento->contador].ano = 0;
		return desempilhar;
	} else {
		cout << "Estacionamento vazio!!" << endl << endl;
		return Carro{"", 0};
	}
}

void imprime_pilha (Pilha *estacionamento) {
	for (int x=0; x<estacionamento->contador; x++){
		cout << estacionamento->data[x].placa;
		cout << "   ";
		cout << estacionamento->data[x].ano << endl << endl;
	}
}

void imprime_tudo(Pilha *estacionamento) {
	for (int x=0; x<TAMANHO_PILHA; x++){
		cout << estacionamento->data[x].placa;
		cout << "   ";
		cout << estacionamento->data[x].ano << endl << endl;
	}
}

int quantidade_vagas(Pilha estacionamento){
	return TAMANHO_PILHA - estacionamento.contador;
}
