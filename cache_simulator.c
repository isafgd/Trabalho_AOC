#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <conio.h>

const int MAX = 10000;
unsigned int lido;
/*
nsets = numero de conjuntos
bsize = tamanho do bloco
assoc = nível de associatividade
subs  = politica de substituição
flag_ = flag de saida
*/
//void substituição (char subs[4],int x,int *matrizS[][]);


int main(int argc, char const *argv[]){
  
	int nsets, bsize, assoc, flag_saida,dados[MAX],k, indice,i=0,j, tam=0,random, p, random2, aux=0;
	float hit=0,missConf=0,missCap=0,missComp=0;
	float txHit, txMiss, txComp, txCap, txConf;
	char *subs,file[15];
	FILE *entrada;
	//atribuições iniciais
	nsets = atoi (argv[1]);
	bsize = atoi (argv[2]);
	assoc = atoi (argv[3]);
	subs = argv [4];
	flag_saida = atoi (argv [5]); 
	
	entrada = fopen(argv[6],"rb");
	
	if(entrada == NULL) {
        printf("Arquivo inválido. \n");
        return 1;
    }

    while (!feof(entrada)) {
        fread(&lido, sizeof(unsigned int), 1, entrada);
        dados[tam] = __builtin_bswap32(lido);
        tam++;
    }
	tam--;
	k = nsets/assoc;
	j = assoc;
	p = bsize/4;

	int matriz[k][j][p];

	/*if(strcmp(subs,"FIFO")==0){
    	int matrizF[k][j];
    }
    else
    	if(strcmp(subs,"LRU")==0){
    		int matrizL[k][j];
    	}
	*/
    	
	for(i=0; i < k ;i++){
		for(int t=0;t < j;t++){
			for (int n=0; n < p; n++)
				matriz[i][t][n] = -1;
		}
	} //preenche toda a matriz com -1
		
		for (int t = 0; t < tam ; ++t){
			aux = 0;
			indice = dados[t]%k;
			for (i=0;i<j;i++){
				for (int n=0; n<p;n++){
					if (matriz[indice][i][n] == dados[t]){
						hit++;
						aux++;
						break;
					}
					else {
						if(matriz[indice][i][n] == -1){
							matriz[indice][i][n] = dados[t];
							missComp++;
							aux++;
							break;
						}
						else{
							if(i == j-1 && n == p-1){
								random = rand() % j;
								random2 = (rand() % p)+1;
								matriz[indice][random][random2] = dados[t];

							if (j==1)
								missConf++;
							else {
								if  (k==1)
									missCap++;
								else{
									missConf++;
									int cont = 0;
									for (int i = 0; i < k; ++i){
										for (int m = 0; m < j; ++m){
											for (int n =0; n<p;n++){
												if(matriz[i][m][n]==-1)
													cont++;
											}
										}
									}
									if (cont==0)
										missCap++;
								}
							}
						}
					}
				}
					
				}
				if (aux==1)
					break;
			}
		 }

for(i=0; i < k ;i++){
		printf("\n");
		for(int t=0;t < j;t++){
			printf("[");
			for (int n=0; n < p; n++)
				printf("(%d) ",matriz[i][t][n]);
			printf("]");
		}
	}

	int missTotal = missCap + missConf + missComp;
	txHit = hit/tam;
	txMiss = 1 - txHit;
	txCap = missCap/missTotal;
	txComp = missComp/missTotal;
	txConf = missConf/missTotal;

	if (flag_saida == 0)
		printf ("Número total de acessos: %d\nTaxa de hits: %.2f\nTaxa de miss: %.2f\nTaxa de miss compulsório: %.2f\nTaxa de miss de capacidade: %.2f\nTaxa de miss de conflito: %.2f\n", tam, txHit, txMiss, txComp, txCap, txConf);
	else 
		printf ("%d, %.2f, %.2f, %.2f, %.2f, %.2f", tam, txHit, txMiss, txComp,  txCap, txConf);
	return 0;
}


/*void substituição (char subs[4],int x, int *matrizS[][]){
	if((strcmp (subs,'R')==0)){
		
	}
}*/


