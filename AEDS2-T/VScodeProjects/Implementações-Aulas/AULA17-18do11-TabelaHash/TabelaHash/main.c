/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: flavio
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "tabela_hash.h"

/*
 * 
 */
int main() {
	hash * ha = cria_hash(1000);


	int x;
	char nome[50];
	int indice=125;
	int i=124;
	do{
		printf("\nDigite a opção: ");
		scanf("%d", &x);
		switch(x){
			case 1:
				printf("\nDigite o nome do estudante: ");
				scanf("%s", nome);
				if(i>=indice){
					indice++;
				}
				estudante * e = cria_estudante(nome, indice);
				insere_hash_enc_separado(ha, e);
				i++;
				break;

			case 2:
				char * a = busca_hash_enc_separado(ha, indice);
				if (a != NULL)
					printf("Presente: %s\n", a);
				else
					printf("Aluno nao encontrado.\n");
				break;

		}
	}while(x!=0);
	

	libera_hash(ha);
	return (EXIT_SUCCESS);
}

