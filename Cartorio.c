#include <stdio.h> //Biblioteca de comunica�ao com o usu�rio
#include <stdlib.h> //Biblioteca de aloca�ao de espa�o em memoria 
#include <locale.h> //Biblioteca de aloca�ao de texto por regiao 
#include<string.h>//Biblioteca respon�vel por cuidar das string 

int registro()//Fun��o responsavel por cadastra os usuarios no sistema 
{
	//inicio da cria��o de variaveis /etring
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o de variaveis /string
    
    printf("Digite o CPF a ser cadastrado: ");//validaando informa�Vdo usuario
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavelpor copiar os valores da string
  
    FILE *file; // cria arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: " );
	scanf("%s",sobrenome);
	
	file=fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
	
	system("pause");
	
  
}

int consulta()
{ 
    setlocale(LC_ALL, "Portuguese");//delinindo a linguagem

	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)

    {
         printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	
	 } 
	 
	 while(fgets(conteudo, 200, file)!=NULL)
	 
	 {printf("Essas s�o as informa��es do usu�rio: ");
	 printf("%s", conteudo);
	 printf("\n\n");
	 }
	 
	 system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digiteo CPF do usuario a ser deletado; ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	
	if(file == NULL)
	
	{ 
     printf("\nO usuario n�o se encontra no sistema!.\n\n");
	}
	
	else
    {
        fclose(file); // Fechar o arquivo se ele existir
        printf("Usu�rio deletado com sucesso!\n\n");
    }

    system("pause");	
}

int main()
{
	int opcao=0;//definindo variaveis 
	int laco=1;
	
	for(laco=1;laco==1;)
	{
	
	system("cls");// responsavel por limpar a tela
	
    	setlocale(LC_ALL, "Portuguese");//delinindo a linguagem
	
    	printf("##Cartorio da EBAC##\n\n ");//inicio do menu
    	printf("Escolha a Op��o Desejada do Menu\n ");
    	printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar  nomes\n");
    	printf("\t3 - Deletar nomes\n");
    	printf("Op��o:");//fim do menu
	
	scanf("%d",&opcao);//armazenando a escolha do usuario
		
	system("cls");
	
	switch(opcao)//inicio da sele�ao
	{
		case 1:
		registro();	
		break;
		
		case 2:
		consulta();	
		break;
			
		case 3:
		deletar();	
		break;
		
		default:
		printf("Essa op��o n�o esta disponivel!\n");
    	system("pause");
    	break;
	}//fim da sele�ao
	

}
}

