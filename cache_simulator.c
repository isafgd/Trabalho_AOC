#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

const int MAX = 1000;
unsigned int lido;
/*
nsets = numero de conjuntos
bsize = tamanho do bloco
assoc = nível de associatividade
subs  = politica de substituição
flag_ = flag de saida
*/

int main(int argc, char const *argv[]){
  
	int nsets, bsize, assoc, flag_saida,dados[MAX],k, indice,i=0,j, tam=0, cont=0,random,hit=0,missConf=0,missCap=0,missComp=0;
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
	printf("\n%d\n",tam);
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
						break;
					}
					else{
						if(cont == j){
							random = rand() % j;
							matriz[indice][random] = dados[t];
							missCap++;
							missConf;
						}
						else
							cont++;
					}
				}
					
			}
		 }

	 for (int i = 0; i < k; ++i)
	 {
	 	printf("\n");
	 	for (int t = 0; t < j; ++t)
	 	{
	 		printf("%d ",matriz[i][t]);
	 	}
	 }

	return 0;
}
