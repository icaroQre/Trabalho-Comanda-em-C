#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//LANCAR PRODUTOS NA COMANDA
void lancar_produtos(FILE *ptrcomanda1, FILE *ptrcomanda2, FILE *ptrcomanda3, FILE *ptrnotacomanda1, FILE *ptrnotacomanda2, FILE *ptrnotacomanda3){

    int continuar, comanda, codigo, quantidade, i, j, total=0;
    int produto[6] = {5, 4, 2, 15, 12, 10};
    char nome[6][15] = {"Coca-Cola", "Suco", "Agua", "Porcao", "Lanche", "Salada"};

        //COMEÇA O LOOP DE CADASTRO
    do{
        printf("\n Qual comanda deseja abrir? \n");
        scanf("%d", &comanda);

        if (comanda < 1 || comanda > 3){
            printf("\n Comanda nao existente \n");
            exit(1);
        }

        do{
        printf("\n Codigo do produto: \n");
        scanf("%d", &codigo);
        if(codigo < 1 || codigo > 6){
            printf("\n Codigo de produto nao existente. \n");
            exit(1);
        }
        }while(codigo < 1 || codigo > 6);

        printf("\n Quantidade do produto: \n");
        scanf("%d", &quantidade);

        i=produto[codigo-1];
        j=nome[codigo-1];

        switch (comanda){
        
        //COMANDA 1 
        case 1: 
        printf("%s", j);
        ptrcomanda1 = fopen("comanda_1.txt", "r");
        fscanf(ptrcomanda1, "%d", &total);
        fclose(ptrcomanda1);
        ptrcomanda1=fopen("comanda_1.txt", "w");
        fprintf(ptrcomanda1, "%d", (i*quantidade)+total);
        fclose(ptrcomanda1);
        fprintf(ptrnotacomanda1, "\n %s \n %d \n %d \n", j, i, quantidade);
        break;

        //COMANDA 2
        case 2: 
        ptrcomanda2 = fopen("comanda_2.txt", "r");
        fscanf(ptrcomanda2, "%d", &total);
        fclose(ptrcomanda2);
        ptrcomanda2=fopen("comanda_2.txt", "w");
        fprintf(ptrcomanda2, "%d", (i*quantidade)+total);
        fclose(ptrcomanda2);
        fprintf(ptrnotacomanda2, "\n %s \n %d \n %d \n", j, i, quantidade);
        break;

        //COMANDA 3
        case 3: 
        ptrcomanda3 = fopen("comanda_3.txt", "r");
        fscanf(ptrcomanda3, "%d", &total);
        fclose(ptrcomanda3);
        ptrcomanda3=fopen("comanda_3.txt", "w");
        fprintf(ptrcomanda3, "%d", (i*quantidade)+total);
        fclose(ptrcomanda3);
        fprintf(ptrnotacomanda3, "\n %s \n %d \n %d \n", j, i, quantidade);
        break;
        }

        //CONTINUAR NO LOOP
        printf("\n Deseja continuar lanCando produtos? \n 1- Sim  \n 2- Nao \n");
        scanf("%d", &continuar);
        if(continuar != 1){
            system("cls");
            printf("\n Programa encerrado. \n");
            exit(1);
        }
    system("cls");
    }while (continuar == 1);
    //FINAL DO LOOP DE CADASTRO NA COMANDA
}

//SOMAR VALOR TOTAL DA COMANDA 
void somar_comanda(FILE *ptrcomanda1, FILE *ptrcomanda2, FILE *ptrcomanda3, FILE *ptrnotacomanda1, FILE *ptrnotacomanda2, FILE *ptrnotacomanda3){
    int comanda, total, apagar, mostrar, valorc, quantidadec;
    char produtoc[15];

    printf("\n Qual comanda deseja somar? \n");
    scanf("%d", &comanda);

    if (comanda < 1 || comanda > 3){
        printf("\n Comanda inexistente. \n Programa encerrado.\n");
    }
    
    switch (comanda){

    //COMANDA 1
    case 1:
    fclose(ptrcomanda1);
    ptrcomanda1 = fopen("comanda_1.txt", "r");
    fscanf(ptrcomanda1, "%d", &total);
    fclose(ptrcomanda1);
    printf("\n Total a pagar: %d \n", total);

    printf("\n Deseja mostrar produtos consumidos? \n 1- Sim \n 2- Nao \n");
    scanf("%d", &mostrar);
    system("cls");

    if(mostrar==1){
        fclose(ptrnotacomanda1);
        ptrnotacomanda1 = fopen("nota_comanda_1.txt", "r");
        while((fscanf(ptrnotacomanda1, "\n %s\n %d\n %d", &produtoc, &valorc, &quantidadec))!=EOF)
        printf("\n Produto: %s \n Valor: %d \n Quantidade: %d \n", produtoc, valorc, quantidadec);
    }

    printf("\n Deseja zerar a comanda? \n 1- Sim \n 2- Nao \n");
    scanf("%d", &apagar);
    system("cls");
    if(apagar==1){
        ptrcomanda1 = fopen("comanda_1.txt", "w");
        fclose(ptrcomanda1);
        ptrcomanda1 = fopen("comanda_1.txt", "a");
        fprintf(ptrcomanda1, "%d", 0);
        printf("\n Comanda apagada. \n");
        fclose(ptrcomanda1);
        fclose(ptrnotacomanda1);
        ptrnotacomanda1=fopen("nota_comanda_1.txt", "w");
        fclose(ptrnotacomanda1);
        }
    printf("\n Programa encerrado. \n");
    break;

    //COMANDA 2
    case 2: 
    fclose(ptrcomanda2);
    ptrcomanda2 = fopen("comanda_2.txt", "r");
    fscanf(ptrcomanda2, "%d", &total);
    fclose(ptrcomanda2);
    printf("\n Total a pagar: %d \n", total);

    printf("\n Deseja mostrar produtos consumidos? \n 1- Sim \n 2- Nao \n");
    scanf("%d", &mostrar);
    system("cls");

    if(mostrar==1){
        fclose(ptrnotacomanda2);
        ptrnotacomanda2 = fopen("nota_comanda_2.txt", "r");
        while((fscanf(ptrnotacomanda2, "\n %s\n %d\n %d", &produtoc, &valorc, &quantidadec))!=EOF)
        printf("\n Produto: %s \n Valor: %d \n Quantidade: %d \n", produtoc, valorc, quantidadec);
    }

    printf("\n Deseja zerar a comanda? \n 1- Sim \n 2- Nao \n");
    scanf("%d", &apagar);
    system("cls");
    if(apagar==1){
        ptrcomanda1 = fopen("comanda_2.txt", "w");
        fclose(ptrcomanda2);
        ptrcomanda2 = fopen("comanda_2.txt", "a");
        fprintf(ptrcomanda2, "%d", 0);
        printf("\n Comanda apagada. \n");
        fclose(ptrcomanda2);
        fclose(ptrnotacomanda2);
        ptrnotacomanda2=fopen("nota_comanda_2.txt", "w");
        fclose(ptrnotacomanda2);
        }
    printf("\n Programa encerrado. \n");
    break;

    //COMANDA 3
    case 3: 
    fclose(ptrcomanda3);
    ptrcomanda3 = fopen("comanda_3.txt", "r");
    fscanf(ptrcomanda3, "%d", &total);
    fclose(ptrcomanda3);
    printf("\n Total a pagar: %d \n", total);
    printf("\n Deseja mostrar produtos consumidos? \n 1- Sim \n 2- Nao \n");
    scanf("%d", &mostrar);
    system("cls");

    if(mostrar==1){
        fclose(ptrnotacomanda3);
        ptrnotacomanda3 = fopen("nota_comanda_3.txt", "r");
        while((fscanf(ptrnotacomanda3, "\n %s\n %d\n %d", &produtoc, &valorc, &quantidadec))!=EOF)
        printf("\n Produto: %s \n Valor: %d \n Quantidade: %d \n", produtoc, valorc, quantidadec);
    }

    printf("\n Deseja zerar a comanda? \n 1- Sim \n 2- Nao \n");
    scanf("%d", &apagar);
    if(apagar==1){
        ptrcomanda3 = fopen("comanda_3.txt", "w");
        fclose(ptrcomanda2);
        ptrcomanda3 = fopen("comanda_3.txt", "a");
        fprintf(ptrcomanda3, "%d", 0);
        printf("\n Comanda apagada. \n");
        fclose(ptrcomanda3);
        fclose(ptrnotacomanda3);
        ptrnotacomanda3=fopen("nota_comanda_3.txt", "w");
        fclose(ptrnotacomanda3);
        }

    printf("\n Programa encerrado. \n");
    break;
    }
}

//MOSTRAR CARDAPIO
void cardapio(){
    system("cls");
    printf("\n Produto: Coca-Cola \n Valor: R$ 5,00 \n Codigo: 1 \n");
    printf("\n Produto: Suco \n Valor: R$ 4,00 \n Codigo: 2 \n");
    printf("\n Produto: Agua \n Valor: R$ 2,00 \n Codigo: 3 \n");
    printf("\n Produto: Porcao \n Valor: R$ 15,00 \n Codigo: 4 \n");
    printf("\n Produto: X-Burguer \n Valor: R$ 12,00 \n Codigo: 5 \n");
    printf("\n Produto: Salada \n Valor: R$ 10,00 \n Codigo: 6 \n");
    exit(1);
}

int main (){

    int menu, total, apagar;
    FILE *comanda1 = fopen("comanda_1.txt", "a");
    FILE *comanda2 = fopen("comanda_2.txt", "a");
    FILE *comanda3 = fopen("comanda_3.txt", "a");
    FILE *notacomanda1 = fopen("nota_comanda_1.txt", "a");
    FILE *notacomanda2 = fopen("nota_comanda_2.txt", "a");
    FILE *notacomanda3 = fopen("nota_comanda_3.txt", "a");

    //MENU
    printf("\n 1- Lancar produtos \n 2- Acessar e Somar \n 3- Cardapio \n 4- Sair \n");
    scanf("%d", &menu);

    //ESCOLHE A OPCAO
    if(menu == 1){lancar_produtos(comanda1, comanda2, comanda3, notacomanda1, notacomanda2, notacomanda3);}
    if(menu == 2){somar_comanda(comanda1, comanda2, comanda3, notacomanda1, notacomanda2, notacomanda3);}
    if(menu == 3){cardapio();}
    if(menu == 4){system("cls"); printf("\n Programa encerrado. \n");}

    return 0;
