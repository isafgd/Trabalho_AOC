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
	
	k = nsets/assoc;
	j = assoc;

	int matriz[k][j];
	
	for(i=0; i<= k ;i++){
		for(int t=0;t<=j;t++){
			matriz[i][j] = -1;
		}
	}
	
	for (int t = 0; t < tam ; ++t)
	{
		indice = dados[t]%k;
		for (int m = 0; m < j; ++m)
		{
			if(matriz[indice][m] == dados[t]){
			hit++;
			break;
			}
		}
		for (i=0;i<j;i++){
			if (matriz[indice][i] == -1 || matriz[indice][i] == dados[t]){
				if (matriz[indice][i]==-1)
				{
					matriz[indice][i] = dados[t];
					missComp++;
				}
				matriz[indice][i] = dados[t];

				break;
			}
			else {
				if(cont == j){
					}
				}
				else
					cont++;
			}
		}
		
	} 
  	
	return 0;
}
