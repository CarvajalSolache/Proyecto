#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void main(void)
{
	char nombre[256];
	char cadenas[300];
	char buffer[300][20];
	int caracter = 0,conta=0,caracter2=0,caracter3=0;
	char comparara[10];


	FILE* fp;
	scanf_s("%s", nombre, 256);
	fopen_s(&fp, nombre, "r");
	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf_s(fp, "%s", cadenas, 300);
			caracter = 0;
			caracter3 = 0;
			caracter2 = 0;
			while (cadenas[caracter])
			{
				if (cadenas[caracter] == ')'||cadenas[caracter]=='('||cadenas[caracter]=='.'||cadenas[caracter]==',')
				{
					buffer[conta][caracter3++] = cadenas[caracter++];
					buffer[conta++][caracter3] = '\0';
					caracter2 = 0;
				}
				else
				{
					if (cadenas[caracter] != '('||cadenas[caracter]!=')'||cadenas[caracter]!='.'||cadenas[caracter]!=',')
					{
						while (cadenas[caracter] != '(' && cadenas[caracter] != ')' && cadenas[caracter] != '.'&&cadenas[caracter]!='\0'&&cadenas[caracter]!=',')
						{
							caracter3 = 0;
							buffer[conta][caracter2++] = cadenas[caracter++];
							buffer[conta][caracter2] = '\0';
						}
						conta++;
					}
				}
			}
		}
		fclose(fp);
	}
	else
	{
		printf("nose puedo");
	}
	printf("\nhay %i cadenas", conta);
}


