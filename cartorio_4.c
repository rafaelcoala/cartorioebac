#include <stdio.h> //biblioteca de comunição com o usuário
#include <stdlib.h> //biblioteca de alocaçâo de espaço de memória
#include <locale.h> //biblioteca de alocaçôes de texto por regiâo
#include <string.h> //biblioteca responsavel pelas string

int registro() //função responsavel pelo cadastro dos usuários
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coleta de informação do usuário
	scanf("%s", cpf); //%s referente a string
	
	strcpy(arquivo, cpf); //responsavel por copiar valor da string
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva valor de variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo,"a"); //abre o arquivo
	fprintf(file,","); //salva valor de variavel
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	

}

int consulta()
{
    setlocale(LC_ALL, "portuguese"); 

	char cpf [40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while (fgets(conteudo,200,file)!=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuaário não se encontra no sistema! .\n");
		system("pause");
	}
}
int main()
{
  int opcao=0; //Definindo variáveis
  int laco=1;
  
  for(laco=1;laco=1;) 
  {
  	
  	 system("cls");
  
     setlocale(LC_ALL, "portuguese"); //definindo a linguagem
  
     printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
     printf("Escolha a opção desejada do menu:\n\n");
     printf("\t1 - Registrar nomes\n");
     printf("\t2 - Consultar nome\n");
     printf("\t3 - Deletar nomes\n\n"); 
     printf("Opção: ");//fim do menu

     scanf("%d", &opcao); //armazenamento de escolha do usuário
  
     system("cls"); //responsavel por limpar tela
     
     switch(opcao) //inicio seleção de menu
    {
    	case 1:
		registro(); //chamada de funções
        break;
        
        case 2:
        consulta();
        break;
        
        case 3:
        deletar();
        break;
        
        default:
        printf("essa opção não existe!\n");
        system("pause");
        break;
        
	} // fim da seleção
  
     
}
}
