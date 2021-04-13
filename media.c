/*
22.	Faça um programa que leia os dados de 10 alunos (Nome, matricula, Media Final), armazenando em um vetor. Uma vez lidos os dados, dívida estes dados em 2 novos vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a media mínima para a aprovação como sendo 5.0. Exibir na tela os dados do vetor de aprovados, seguido dos dados do vetor de reprovados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");

    typedef struct{
        char nome[30];
        int matricula;
        float media;
    }aluno;

    aluno al[10];

    for(int i = 0; i <= 9; i++){
        printf("\nDigite seu nome: ");
        fflush(stdin);
        gets(al[i].nome);
        printf("\nDigite sua matricula: ");
        scanf("%i", &al[i].matricula);
        printf("\nDigite sua média: ");
        scanf("%f", &al[i].media);
    }

    int contApr = 0, contRep = 0;

    for(int i = 0; i <= 9; i++){
        if(al[i].media >= 5){
            contApr ++;
        }else{
            contRep ++;
        }
    }

    aluno aprovados[contApr];
    aluno reprovados[contRep];
    int a = 0;
    int r = 0;

    for(int i = 0; i <= 9; i++){
        if(al[i].media >= 5){
            aprovados[a].matricula = al[i].matricula;
            aprovados[a].media = al[i].media;
            a++;
        }else{
            reprovados[r].matricula = al[i].matricula;
            reprovados[r].media = al[i].media;
            r++;
        }   
    }
    
    printf("\nAprovados:\n");
    for(int i = 0; i < contApr; i++){
        printf("\nMatricula: %i, Média: %.2f", aprovados[i].matricula, aprovados[i].media);
    }

    printf("\n\nReprovados\n");
    for(int i = 0; i < contRep; i++){
        printf("\nMatricula: %i, Média: %.2f", reprovados[i].matricula, reprovados[i].media);      
    }   

    return 0;
}