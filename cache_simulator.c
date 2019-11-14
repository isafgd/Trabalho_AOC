#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
  
	int nsets, bsize, assoc, flag_saida,dados[MAX],k=0,tag,i=0,j, tam=0;
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

     for(i=0; i<tam-1; i++) {
         printf("%u\n", dados[i]);
     }


	
	 /*= nsets/assoc;*/
	j = assoc;

	int matriz[i][j];
	
	for (int t = 0; t < k ; ++t)
	{
		tag = dados[t]%i;

	}
  	
	return 0;
}
