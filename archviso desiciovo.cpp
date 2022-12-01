#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void main(void)
{
	char nombre[500];
	char cadenas[200];
	char buffer[200][20];
	int caracter = 0, conta = 0, caracter2 = 0, caracter3 = 0;
	int conta10 = 0;

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
				if (cadenas[caracter] == ')' || cadenas[caracter] == '(' || cadenas[caracter] == '.' || cadenas[caracter] == ',')
					caracter++;
				else
				{
					if (cadenas[caracter] != '(' || cadenas[caracter] != ')' || cadenas[caracter] != '.' || cadenas[caracter] != ',')
					{
						while (cadenas[caracter] != '(' && cadenas[caracter] != ')' && cadenas[caracter] != '.' && cadenas[caracter] != '\0' && cadenas[caracter] != ',')
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
	caracter = 0;
	buffer[conta][caracter] = '\0';
	//estadistica comienza en 1
	int estadistica =0;
	conta = 0; int conta2 = 0;
	while (buffer[conta2][caracter])
	{
		if (conta2 == conta)
			conta++;
		else
		{ 
			while ((strcmp(buffer[conta2], buffer[conta2+1]) == 0))
			{
				estadistica++;
			}
			printf("%i\n", estadistica);
			conta2++, conta = 0;
			estadistica = 1;
		}
	}
	buffer[conta][0] = '\0';
	conta = 0, caracter2 = 0;
	while (buffer[conta][caracter2])
	{
		while (buffer[conta][caracter2])
			printf("%c", buffer[conta][caracter2++]);
		conta++, caracter2 = 0;
		printf("\n");
	}
	printf("\nhay %i cadenas", conta);
}

