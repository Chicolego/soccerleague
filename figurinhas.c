#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define SIZE 35

int maior = 0;
int menor = 1000;

//booleano que verifica se todos os vértices já foram visitados.
int verificar(int vertices[]){
	for(int i = 0; i < SIZE; i++){
		if(vertices[i] == 0){
			//printf("Vértice %d não foi acessado!\n", i);
			return 0;
		}
	}
	return 1;
}

//função dedicada a zerar o valor de todos os vértices para que seja possível realizar outra simulação.
void inicializar(int vertices[]){
	for(int i = 0; i < SIZE; i++){
		vertices[i] = 0;
	}
}

//função dedicada a realizar todas as simulações.
float gerar(int runs, int vertices[]){
	int passos = 0;
	int passosrun = 0;
	int random;
	
	for(int i = 0; i < runs; i++){
		
		passosrun = 0;
		//inicialização da run.
		inicializar(vertices);
		
		//processo de uma run.
		while(!verificar(vertices)){
		    random = rand()%35;
            vertices[random] = 1;
			passos++;
			passosrun++;
			//printf("Ganhei a figurinha %d \n", random);
		}
		if (passosrun > maior) {maior = passosrun;}
		if (passosrun < menor) {menor = passosrun;}
	}
	
	//retorno da quantidade média de passos para atingir o objetivo de uma run.
	return ((float)passos/runs);
}

int main(int argc, char* argv[]){
	
	//variáveis globais.
	float media;
	int runs = 0;
	int vertices[SIZE];
	srand(time(NULL));

	//leitura e avaliação dos parâmetros de entrada.
	if(argc<2) {
		printf("Digite: %s <quantidade de execuções>\n", argv[0]);
		return 1;
	}
	
	//passa a quantidade de execuções e chama a função para fazer todas as simulações pedidas.
	runs = atoi(argv[1]);
	media = gerar(runs, vertices);
	
	printf("Após %d execuções, constatamos que o valor médio de figurinhas para completar o álbum é %.2f\n", runs, media);
	printf("Maior: %d \nMenor: %d \n", maior, menor);
	
	return 0;
}