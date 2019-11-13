#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char const *argv[]){
  
	int nsets, bsize, assoc, flag_saida,dado,maisvariavel;
	char *subs; 
	FILE *entrada;
	nsets = atoi (argv[1]);
	bsize = atoi (argv[2]);
	assoc = atoi (argv[3]);
	subs = argv [4];
	flag_saida = atoi (argv [5]); 
	entrada = fopen (argv [6], "rb");
	
	int x;
	while (true){
		int k = fscanf (entrada, "%d", &x);
		if (k!=1) break; //para a leitura
	}
  
  	fclose (entrada);
  	printf ("%d", x);
	return 0;
}
