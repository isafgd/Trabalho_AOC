#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

const int MAX = 10000;
unsigned int lido;
/*
nsets = numero de conjuntos
bsize = tamanho do bloco
assoc = nível de associatividade
subs  = politica de substituição
flag_ = flag de saida
*/

int main(int argc, char const *argv[]){
  
	int nsets, bsize, assoc, flag_saida,dados[MAX],k, indice,i=0,j, tam=0, cont=0,random;
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
        printf("Problemas com a leitura do arquivo. \n");
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

	int matriz[k][j];
	
	for(i=0; i < k ;i++){
		for(int t=0;t < j;t++){
			matriz[i][t] = -1;
		}
	}
		for (int t = 0; t < tam ; ++t){
			cont = 0;
			indice = dados[t]%k;
			for (i=0;i<j;i++){
				if (matriz[indice][i] == dados[t]){
						hit++;
						break;
					}
				else {
					if(matriz[indice][i] == -1){
						matriz[indice][i] = dados[t];
						missComp++;
						break;
					}
					else{
						if(cont == j-1){
							random = rand() % j;
							matriz[indice][random] = dados[t];

							if (j==1)
								missConf++;
							else {
								if  (k==1)
									missCap++;
								else{
									missCap++;
									missConf++;
								}
							}
						}
						else
							cont++;
					}
				}
					
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
