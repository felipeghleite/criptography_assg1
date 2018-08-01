#include <stdio.h>
#include <stdlib.h>

void main(){
	unsigned short ch;
	FILE *fpIn, *fpOut;
	int i = 0;
	unsigned int keyLength;
	unsigned short initCh;
	unsigned int temp;

	fpOut = fopen("freq.txt", "w");
	
	for(keyLength = 2; keyLength < 10 ; keyLength++){

        	fpIn = fopen("ctext.txt", "r");
        	temp = fscanf(fpIn,"%02X", &initCh);
		fseek(fpIn, keyLength, SEEK_CUR);
		
		while(fscanf(fpIn, "%02X", &ch) != EOF){
		
			if(initCh == ch)
			{
				i++;
				printf("%02X", ch);
				printf("\n");
			}
		
			fseek(fpIn, keyLength, SEEK_CUR);
		}

	printf("keyLength=%d\nFrequency=%d\n____________________________",keyLength,i);
	i = 0;
	fclose(fpIn);	
	
	}

	fclose(fpOut);
	return;
}


