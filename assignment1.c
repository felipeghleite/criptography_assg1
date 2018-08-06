#include <stdio.h>
#include <stdlib.h>

#define KEY_LENGTH 7

void main(){
	unsigned short ch = 0;
	FILE *fpIn, *fpOut;
	int i;
//	unsigned char key[KEY_LENGTH] = {0xBA, 0x20, 0x80, 0xA0, 0x00, 0x80, 0x20};
	unsigned char key[KEY_LENGTH] = {0xBA, 0x1F, 0x91, 0xB2, 0x53, 0xCD, 0x3E};
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




