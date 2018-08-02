#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH 5

void main(){
	unsigned int ch = 0;
	FILE *fpIn, *fpOut;
	int i;
	unsigned char key[KEY_LENGTH] = {0x5A, 0x1B, 0x00, 0x00, 0x00};

	fpIn = fopen("ctext.txt", "r+");
	if(fpIn == NULL ){
			printf("erro");
			return;
	}
	fpOut = fopen("outtext.txt", "w");
	if(fpOut == NULL ){
			printf("erro");
			return;
	}
	i=0;
			while(fscanf(fpIn, "%02X", &ch) != EOF) {
					
			if(ch!='\n'){
			
			fpOut = fopen("otext.txt", "a");
			fprintf(fpOut, "%c", ch ^ key[i % KEY_LENGTH]);
			fclose(fpOut);
			i++;
			
			}
	
	}
	
	fclose(fpIn);
	return;
}




