#include <stdio.h>
#include <stdlib.h>

void main(){
	unsigned short ch;
	FILE *fpIn, *fpOut;
	int i = 0;
	int j = 0;
	unsigned int keyLength;
	unsigned int fileLength;
	unsigned short initCh;
	unsigned int temp;
	unsigned int lastMax, lastKeyLength, lastPos;
	lastMax = 0;
	lastKeyLength = 0;
	lastPos = 0;

	fpOut = fopen("freq.txt", "w");
	fpIn = fopen("ctext.txt", "r");
	fseek(fpIn, 0, SEEK_END);
	fileLength = (unsigned int)ftell(fpIn);
	fclose(fpIn);

	for(keyLength = 2; keyLength < 17 ; keyLength++){

		for(j = 0; j < fileLength; j++){
			fpIn = fopen("ctext.txt", "r");
			fseek(fpIn, j, SEEK_SET);
			temp = fscanf(fpIn,"%02X", &initCh);
			fseek(fpIn, keyLength, SEEK_CUR);

			while(fscanf(fpIn, "%02X", &ch) != EOF){

				if(initCh == ch)
				{
					i++;
//					printf("%02X", ch);
//					printf("\n");
				}

				fseek(fpIn, keyLength, SEEK_CUR);
			}

			if(i > lastMax){
				lastMax = i;
				lastKeyLength = keyLength;
				lastPos = j;
				printf("keyLength=%d\nFrequency=%d\nCharacter=%02X\n____________________________\n",keyLength,i,initCh);

			}

			i = 0;
			fclose(fpIn);

		}


	}

	fclose(fpOut);
	getchar();
	return;
}


