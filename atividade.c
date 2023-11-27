Nome: Gabriélly C. Ferreira

#include <stdio.h>
#define N 5

struct TipoNodo
{
    int codigo;
    char nome[10];
    float numero;
};

typedef struct TipoNodo TipoNodo;

int menu();
int inserirInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int inserirFinal(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo);
int removerInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
int removerFinal(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo)
int mostrar(TipoNodo LL[], int IA, int FA, int IL, int FL);

int main()
{
    TipoNodo LL[N], infoNodo;
    int opcao, IA=0, FA=N-1, IL=-1, FL=-1, aux=0;
    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            printf("\n>>>>>> Inserir um nó no Início <<<<<\n");
            printf("\nCódigo...: ");
            scanf("%d",&infoNodo.codigo);
            printf("\nNome.....: ");
            scanf("%s",infoNodo.nome);
            printf("\nNúmero...: ");
            scanf("%f",&infoNodo.numero);
            if(inserirInicio(LL, IA, FA, &IL, &FL, infoNodo))
                printf(">>> Lista cheia, não foi possível inserir <<<\n");
            else    
                printf(">>> Inserido com sucesso\n");
            break;
        case 2:
            printf("\n\nInserir um nó no Fim\n\n");
            printf("Código....: ");
            scanf("%d", &infoNodo.codigo);
            printf("Nome......: ");
            scanf("%s", infoNodo.nome);
            printf("Número....: ");
            scanf("%f", &infoNodo.numero);
            if (inserirFinal(LL, IA, FA, &IL, &FL, infoNodo))
            printf(">>> Lista cheia, não foi possível inserir <<<\n");
             else 
              printf("\n\n>>>>>>Inserido com sucesso!!!\n\n");
            break;
        case 3:
            printf("\n\n Remover no Início\n\n");
            removerInicio(LL, IA, FA, &IL, &FL, infoNodo)
            printf("\n\n>>>>>>Removido com sucesso!!!\n\n");
            break;                
        case 4:
            removerFinal(LL, IA, FA, &IL, &FL, infoNodo)
            printf(">>> Lista não está cheia, não precisa remover <<<\n");
             else
            printf("\n\n>>>>>>Removido com sucesso!!!\n\n");
            break;
        case 5:
            printf("\n\nMostrar a lista\n\n");
            mostrar(LL, IA, FA, IL, FL);
            break;
        case 0:
            printf("\n\nJá vai tarde!!!\n\n");
            break;
        default :
            printf("\n\nErrroouuu!!!\n\n"); 
        }
        
    }
    while (opcao != 0);
}

int menu()
{
    int opcao;
    printf("*********** M E N U ************\n");
    printf("[1] Inserir no início\n");
    printf("[2] Inserir no fim\n");   
    printf("[3] Remover no início\n"); 
    printf("[4] Remover no fim\n");    
    printf("[5] Mostrar\n");
    printf("[0] Sair\n");
    printf("********************************\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    return opcao;
}

int inserirInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo){
    if (IA == *IL && FA == *FL) 
        return 1;
    else
    {
        if (*IL == -1)
            *IL = *FL = IA;
        else if (*IL > IA) 
            *IL = *IL-1;
        else
        {
            for(int i=*FL; i>=*IL; i--)
                LL[i+1] = LL[i];
            *FL = *FL+1;
        }
        LL[*IL] = infoNodo;
        return 0;
    }
}

int inserirFinal(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo){
    if (IA == *IL && FA==*FL)
        return 1;
    else 
    {
        if (*IL == -1)
           *IL = *FL = IA;
        else if (*FL < FA)
           *FL = *FL+1;
        else
        {
            for(int i=*IL; i>=*FL; i++)
                LL[i-1] = LL[i];
            *IL = *IL-1;
        }
        LL[*FL] = infoNodo;
        return 0;
    }
    
}

int removerInicio(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo) { 
    for (int i = *FL; i >= *IL; i--) 
    LL[i - 1] = LL[i]; *FL = *FL - 1; 
    return 0; 
    
} 
    
int removerFinal(TipoNodo LL[], int IA, int FA, int *IL, int *FL, TipoNodo infoNodo) { 
    for (int i = *IL; i >= *FL; i++) LL[i + 1] = LL[i]; *FL = *FL - 1; 
    return 0; 

}

int mostrar(TipoNodo LL[], int IA, int FA, int IL, int FL){
    for(int i=IA; i<=FA; i++){
        if(i>=IL && i<=FL)
            printf("%4d - %8.2f - %s\n",LL[i].codigo, LL[i].numero, LL[i].nome);
        else   
            printf("--- --- ----\n");
    }
    return 0;
}