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
	unsigned int temp, temp1;
	unsigned int lastMax, lastKeyLength, lastPos;
	unsigned short keyTemp, keyIndex;
	unsigned char key[32] = {0};
	unsigned char keyFinal[32] = {0};
	float qi2, qimax, qi;
	lastMax = 0;
	lastKeyLength = 0;
	lastPos = 0;
	temp1 = 0;
	qimax = 0;
	qi = 0;
	qi2 = 0;
	fpOut = fopen("freq.txt","w");
	fpIn = fopen("ctext.txt", "r");
	fseek(fpIn, 0, SEEK_END);
	fileLength = (unsigned int)ftell(fpIn);
	fclose(fpIn);

	for(keyLength = 4; keyLength < 10 ; keyLength++){

		for(temp1 = 0x00 ; temp1 < 0x100; temp1++){
			qi = 0;
			for(i = 0; i < keyLength+1; i++){
				fpIn = fopen("ctext.txt", "r");
				fseek(fpIn, i*2, SEEK_CUR);

				while(fscanf(fpIn, "%02X", &ch) != EOF){
					if(temp1  == ch)
					{
						qi++;
					}
					fseek(fpIn, (keyLength-1)*2, SEEK_CUR);
				}

				fclose(fpIn);
			}
			qi = qi/256;
			qi2 += qi*qi;
		}
		if(qi2 > qimax){
			qimax = qi2;
			lastKeyLength = keyLength;
		}
		qi2 = 0;
	}

	j = 0;
	qi2 = 0;
	qimax = 0;

	for(keyIndex = 0; keyIndex < lastKeyLength+1; keyIndex++){

		for(keyTemp = 0; keyTemp < 257; keyTemp++){
			key[keyIndex] = keyTemp;
			j = 1;
			fpIn = fopen("ctext.txt", "r");
			fpOut = fopen("dec_text.txt","w+");
			fseek(fpIn, keyIndex*2, SEEK_SET);

			while(fscanf(fpIn, "%02X", &ch) != EOF){

				ch ^= key[keyIndex];
				if(ch < 32 || ch > 127 ){
					j = 0;
					break;
				}
				fprintf(fpOut,"%c", ch);
				fseek(fpIn, (lastKeyLength-1)*2, SEEK_CUR);
			}
			fclose(fpIn);
			fclose(fpOut);

			if(j){
				j=0;
				for(i = 32; i < 128; i++){
					qi = 0;
					fpOut = fopen("dec_text.txt", "r+");
					while(fscanf(fpOut, "%c", &ch) != EOF){
						if(ch == i){
							qi++;
						}
					}
					fclose(fpOut);
					qi = qi/256;
					qi2 += qi*qi;
				}
			if(qi2 > qimax){
				qimax = qi2;
				keyFinal[keyIndex] = keyTemp;
			}
			qi2 = 0;
		}
	}
		qimax = 0;
}

getchar();
return;
}


