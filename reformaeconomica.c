#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

#define WINBASE 100
#define EMPATEBASE 30
#define CLEANSHEATBASE 25
#define DERROTABASE 10
#define MSSLTOP1 1500
#define MSSLTOP2 750
#define MSSLTOP3 325
#define VENCEDOR_USL 1500
#define FINALISTA_USL 1500
#define TERCEIRO_USL 800
#define SEMIFINALISTA_USL 800
#define VENCEDOR_CSL 1500
#define FINALISTA_CSL 1200
#define TERCEIRO_CSL 850
#define TOP4_CSL 600
#define TOP6_CSL 400
#define TOP8_CSL 300
#define PARTICIPA_CSL 500
#define MSSL 3
#define USL 4.5
#define CSL 0

int main(void){
	int torneio, jogos, vitorias, empates, cleansheets, posicao, premio, peso;
	
	printf("Quantos jogos sua equipe teve?\n");
	scanf("%d", &jogos);
	
	while(jogos <= 0){
			
		printf("Número Inválido\n");
		scanf("%d", &jogos);
			
	}

	printf("Quantas vitórias sua equipe teve?\n");
	scanf("%d", &vitorias);
	
	while(vitorias < 0 || vitorias > jogos){
		
		printf("Número Inválido\n");
		scanf("%d", &vitorias);
		
	}
	
	printf("Quantas empates sua equipe teve?\n");
	scanf("%d", &empates);
	
	while(empates < 0 || empates > jogos-vitorias){
		
		printf("Número Inválido\n");
		scanf("%d", &empates);
		
	}
	
	printf("Quantos cleansheets sua equipe fez?\n");
	scanf("%d", &cleansheets);
	
	while(cleansheets < 0 || cleansheets > jogos){
		
		printf("Número Inválido\n");
		scanf("%d", &cleansheets);
		
	}

	printf("Qual competição a sua equipe jogou?\n[1] MSSL\n[2] CSL\n[3] USL\n");
	scanf("%d", &torneio);
	
	while(torneio != 1 && torneio != 2 && torneio != 3){
		
		printf("Torneio Inválido. Digite o ID novamente.\n");
		scanf("%d", &torneio);
		
	}
	
	switch(torneio){
		
		case 1:
		
			peso = MSSL;
		
			printf("Qual foi sua situação final na competição?\n[1] Primeiro Lugar \n[2] Segundo Lugar \n[3] Terceiro \n[4] Outro\n");
			scanf("%d", &posicao);
			
			while(posicao != 1 && posicao != 2 && posicao != 3 && posicao != 4){
		
			printf("Número Inválido\n");
			scanf("%d", &posicao);
		
			}			

			switch(posicao){
				
				case 1:
					premio = MSSLTOP1;
				break;
				
				case 2:
					premio = MSSLTOP2;
				break;	

				case 3:
					premio = MSSLTOP3;
				break;

				case 4:
					premio = 0;
				break;					
			}
			
			break;
		
		case 2:
		
			peso = CSL;
		
			printf("Qual foi sua situação final na competição?\n[1] Campeão \n[2] Finalista \n[3] Terceiro \n[4] Top 4\n[5] Top 6\n[6] Top 8\n[7] Outro\n");
			scanf("%d", &posicao);
			
			while(posicao != 1 && posicao != 2 && posicao != 3 && posicao != 4 && posicao != 5 && posicao != 6 && posicao != 7){
		
			printf("Número Inválido\n");
			scanf("%d", &posicao);
			
			}
			
			switch(posicao){
				
				case 1:
					premio = VENCEDOR_CSL + FINALISTA_CSL + TERCEIRO_CSL + TOP4_CSL + TOP6_CSL + TOP8_CSL + PARTICIPA_CSL;
				break;
				
				case 2:
					premio = FINALISTA_CSL + TERCEIRO_CSL + TOP4_CSL + TOP6_CSL + TOP8_CSL + PARTICIPA_CSL;
				break;

				case 3:
					premio = TERCEIRO_CSL + TOP4_CSL + TOP6_CSL + TOP8_CSL + PARTICIPA_CSL;
				break;

				case 4:
					premio = TOP4_CSL + TOP6_CSL + TOP8_CSL + PARTICIPA_CSL;
				break;	

				case 5:
					premio = TOP6_CSL + TOP8_CSL + PARTICIPA_CSL;
				break;

				case 6:
					premio = TOP8_CSL + PARTICIPA_CSL;
				break;

				case 7:
					premio = PARTICIPA_CSL;
				break;				
			}
			
			break;
			
		case 3:
		
			peso = USL;
		
			printf("Qual foi sua situação final na competição?\n[1] Campeão \n[2] Segundo Lugar \n[3] Terceiro \n[4] Semifinalista\n[5] Outro\n");
			scanf("%d", &posicao);
			
			while(posicao != 1 && posicao != 2 && posicao != 3 && posicao != 4 && posicao != 5){
		
			printf("Número Inválido\n");
			scanf("%d", &posicao);
			}
			
			switch(posicao){
				
				case 1:
					premio = VENCEDOR_USL + FINALISTA_USL + SEMIFINALISTA_USL + PARTICIPA_CSL;
				break;
				
				case 2:
					premio = FINALISTA_USL + SEMIFINALISTA_USL + PARTICIPA_CSL;
				break;	

				case 3:
					premio = TERCEIRO_USL + SEMIFINALISTA_USL + PARTICIPA_CSL;
				break;

				case 4:
					premio = SEMIFINALISTA_USL + PARTICIPA_CSL;
				break;				

				case 5:
					premio = PARTICIPA_CSL;
				break;
			}
			
			break;
			
			
	}		
	
	printf("Premiação Total: %d",(((vitorias*WINBASE)+(EMPATEBASE*empates)+(((jogos-(vitorias+empates))*DERROTABASE))+(cleansheets*CLEANSHEATBASE))*peso + premio));
	
	return 0;
}