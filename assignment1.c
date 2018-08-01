#include <stdio.h>
#define KEY_LENGTH 2

void main(){
	unsigned char ch;
	FILE *fpIn, *fpOut;
	int i;
	unsigned char key[KEY_LENGTH] = {0x01, 0x02};

	fpIn = fopen("ptext.txt", "r");
	fpOut = fopen("ctext.txt", "w");
	i=0;
	while(fscanf(fpIn, "%c", &ch) != EOF) {

		if(ch!='\n'){
			fprintf(fpOut, "%02X", ch ^ key[i % KEY_LENGTH]);

			i++;}
	}
	
	fclose(fpIn);
	fclose(fpOut);
	return;
}




