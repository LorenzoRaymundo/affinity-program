#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define MAXPESSOAS 100
#define STRLEN 40
#define NUM_CARACTERISTICAS 15
#define ESC 27

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct data{

    char nome[STRLEN];
    int data_nascimento; /// ///
    char email[STRLEN];
    char telefone[STRLEN]; // // //
    char time[STRLEN];
    char equipe[STRLEN];
    char esportes[STRLEN];
    char profissao[STRLEN];
    char cidade[STRLEN];
    char comida[STRLEN];
    char videogame[STRLEN];
    char hobbie[STRLEN];
    char celular[STRLEN]; //xiaomi samsumg ihpone
    int litros_agua; // // //
    char carro[STRLEN];
    char cor[STRLEN];
    char cachorro[STRLEN];
    char livro[STRLEN];


} Pessoa;

void ler_caracteristica(char qual_caracteristica[], char caracteristicaParaDigitar[], int numero){

    printf("\nDigite a/o %s da pessoa %d:", caracteristicaParaDigitar, numero+1);
    fflush(stdin);
    gets(qual_caracteristica);

}

// Pessoa *p = &pessoa[i];
// *p->nome = "joao";a

void cadastrar_usuarios(Pessoa pessoas[MAXPESSOAS]){

    FILE *fp = fopen("usuarios_cadastrados.txt", "a+t");
    FILE *file = fopen("cadastro.dat", "a+b"); // escreve em bytes para posteriormente ficar mais facil de se procurar pelo arquivo

    for (int i = 0; i < MAXPESSOAS; i++){

        //char *pes_atual = &pessoas[i];
        ler_caracteristica(pessoas[i].nome, "Nome", i);
        if (strcmp(pessoas[i].nome, "") == 0) break; // caso digite enter ele encerra a digitacao

        ler_caracteristica(pessoas[i].email, "Email", i);
        ler_caracteristica(pessoas[i].time, "Time", i);
        ler_caracteristica(pessoas[i].equipe, "Equipe", i);
        ler_caracteristica(pessoas[i].esportes, "Esportes", i);
        ler_caracteristica(pessoas[i].profissao, "Profissão", i);
        ler_caracteristica(pessoas[i].cidade, "Cidade", i);
        ler_caracteristica(pessoas[i].comida, "Comida Favorita", i);
        ler_caracteristica(pessoas[i].videogame, "Videogame Favorito", i);
        ler_caracteristica(pessoas[i].hobbie, "hobbie", i);
        ler_caracteristica(pessoas[i].carro, "carro", i);
        ler_caracteristica(pessoas[i].celular, "marca de celular", i);
        ler_caracteristica(pessoas[i].cor, "Cor Favorita", i);
        ler_caracteristica(pessoas[i].cachorro, "Cachorro favorito", i);
        ler_caracteristica(pessoas[i].livro, "Livro favorito", i);

        fflush(stdin);
        printf("\nDigite a data de nascimento da pessoa %d DDMMAAAA: ", i+1);
        scanf("%d", &pessoas[i].data_nascimento);

        fflush(stdin);
        printf("\nDigite o telefone da pessoa %d (ex: +55 51 900000000): ", i+1);
        gets(pessoas[i].telefone);

        fflush(stdin);
        printf("\nDigite qauntos litros de agua a pessoa %d toma: ", i+1);
        scanf("%d", &pessoas[i].litros_agua);

        fprintf(fp, "\n-------------------------------", i+1);
        fprintf(fp, "\nNome: %s", pessoas[i].nome);
        fprintf(fp, "\nEmail: %s", pessoas[i].email);
        fprintf(fp, "\nData de nascimento: %d", pessoas[i].data_nascimento);
        fprintf(fp, "\nTelefone: %s", pessoas[i].telefone);

        fprintf(fp, "\n\nLitros de Agua: %d", pessoas[i].litros_agua);
        fprintf(fp, "\nCidade: %s", pessoas[i].cidade);
        fprintf(fp, "\nTime: %s", pessoas[i].time);
        fprintf(fp, "\nEquipe: %s", pessoas[i].equipe);
        fprintf(fp, "\nEsportes: %s", pessoas[i].esportes);
        fprintf(fp, "\nProfissão: %s", pessoas[i].profissao);
        fprintf(fp, "\nComida Favorita: %s", pessoas[i].comida);
        fprintf(fp, "\nVideogame Favorito: %s", pessoas[i].videogame);
        fprintf(fp, "\nHobbie: %s", pessoas[i].hobbie);
        fprintf(fp, "\nCarro: %s", pessoas[i].carro);
        fprintf(fp, "\nMarca de celular: %s", pessoas[i].celular);
        fprintf(fp, "\nCor favorita: %s", pessoas[i].cor);
        fprintf(fp, "\nRaça de cachorro: %s", pessoas[i].cachorro);
        fprintf(fp, "\nLivro favorito: %s", pessoas[i].livro);

        fwrite(&pessoas[i], sizeof(pessoas[i]), 1, file);

    }
    fclose(fp);
    fclose(file);
}

void pesquisa(char *caracteristica){

    FILE *file = fopen("cadastro.dat", "rb");

    Pessoa pessoas[MAXPESSOAS];
    Pessoa semelhantes[MAXPESSOAS];

    int prox = 0;
    int pessoasEncontradas = 0;

    while (fread(&pessoas[prox], sizeof(pessoas[prox]), 1, file) == 1) {

        if (strcasecmp(pessoas[prox].nome, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].email, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].cidade, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].time, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].equipe, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].esportes, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].profissao, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].comida, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].videogame, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].hobbie, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].carro, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].cor, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].cachorro, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].livro, caracteristica) == 0 ||
            strcasecmp(pessoas[prox].celular, caracteristica) == 0)
        {
            semelhantes[pessoasEncontradas++] = pessoas[prox];
        }
        
        prox++;

    }

    fclose(file);

    if (pessoasEncontradas > 0) {
        printf("\n%sPessoas encontradas com a caracteristica%s %s'%s'%s:\n", GREEN, RESET, YELLOW, caracteristica, RESET);
        for (int i = 0; i < pessoasEncontradas; i++) 
            printf("%s%d%s. %s%s%s\n", YELLOW, i + 1, RESET, CYAN, semelhantes[i].nome, RESET);
    } else
        printf("%sNenhuma pessoa encontrada com a caracteristica '%s'.%s\n", RED, caracteristica, RESET);
}

void calcularAfinidades(Pessoa people[], int nPessoas, float afinidades[nPessoas][nPessoas]){

    // recebe como parametro uma lista de pessoas, um numero de pessoas dessa lista e uma matriz para serem armazenadas as afinidades nela

    /* 
        1. Percorrer todas as pessoas do cadastro
        2. Comparar para cada pessoa as suas caracteristicas com outra pessoa
        3. somar afinidades
    */

    // p[i].cidade == p[j].cidade
    // afinidades[i+j] += 1;


    for (int pesPrincipal = 0; pesPrincipal < nPessoas; pesPrincipal++){
        for (int pesAtual = 0; pesAtual < nPessoas; pesAtual++){

            afinidades[pesPrincipal][pesAtual] = 0; // deixa todas as afinidades em 0

            if (people[pesPrincipal].litros_agua == people[pesAtual].litros_agua)
                afinidades[pesPrincipal][pesAtual] += 1;
            
            if (strcmp(people[pesPrincipal].cidade, people[pesAtual].cidade) == 0)
                afinidades[pesPrincipal][pesAtual] += 3;
            
            if (strcmp(people[pesPrincipal].time, people[pesAtual].time) == 0)
                afinidades[pesPrincipal][pesAtual] += 5;
            
            if (strcmp(people[pesPrincipal].equipe, people[pesAtual].equipe) == 0)
                afinidades[pesPrincipal][pesAtual] += 7;
            
            if (strcmp(people[pesPrincipal].esportes, people[pesAtual].esportes) == 0)
                afinidades[pesPrincipal][pesAtual] += 10;
            
            if (strcmp(people[pesPrincipal].profissao, people[pesAtual].profissao) == 0)
                afinidades[pesPrincipal][pesAtual] += 8;
            
            if (strcmp(people[pesPrincipal].comida, people[pesAtual].comida) == 0)
                afinidades[pesPrincipal][pesAtual] += 5;
            
            if (strcmp(people[pesPrincipal].videogame, people[pesAtual].videogame) == 0)
                afinidades[pesPrincipal][pesAtual] += 10;
            
            if (strcmp(people[pesPrincipal].hobbie, people[pesAtual].hobbie) == 0)
                afinidades[pesPrincipal][pesAtual] += 10;
            
            if (strcmp(people[pesPrincipal].carro, people[pesAtual].carro) == 0)
                afinidades[pesPrincipal][pesAtual] += 3;
            
            if (strcmp(people[pesPrincipal].celular, people[pesAtual].celular) == 0)
                afinidades[pesPrincipal][pesAtual] += 1;
            
            if (strcmp(people[pesPrincipal].cor, people[pesAtual].cor) == 0)
                afinidades[pesPrincipal][pesAtual] += 3;
            
            if (strcmp(people[pesPrincipal].cachorro, people[pesAtual].cachorro) == 0)
                afinidades[pesPrincipal][pesAtual] += 5;
            
            if (strcmp(people[pesPrincipal].livro, people[pesAtual].livro) == 0)
                afinidades[pesPrincipal][pesAtual] += 7;
            

        }
    }

    for (int pesPrincipal = 0; pesPrincipal < nPessoas; pesPrincipal++){
        for (int pesAtual = 0; pesAtual < nPessoas; pesAtual++)
            afinidades[pesPrincipal][pesAtual] = ((float)afinidades[pesPrincipal][pesAtual] / 78) * 100; // calcula em porcentagem
    }

}

void encurtarNome(char *nome){

    char nomeEncurtado[STRLEN];
    int l = 0;

    for (l = 0; l < strlen(nome); l++){

        nomeEncurtado[l] = nome[l];

        if (nome[l] == ' '){
            
            nomeEncurtado[l+1] = toupper(nome[l+1]);
            nomeEncurtado[l+2] = '.';
            nomeEncurtado[l+3] = '\0';

            break;

        }
        
    }

    // Adiciona o final, caso não tenha um sobrenome
    if (nome[l] != ' ') {
        nomeEncurtado[l] = '\0';
    }

    strcpy(nome, nomeEncurtado);

}

void escreverAfinidades(void){

    FILE *cadastro = fopen("cadastro.dat", "rb");
    FILE *tabela = fopen("tabela.txt", "wt");

    Pessoa people[MAXPESSOAS];
    Pessoa temp[MAXPESSOAS];

    int nPessoas = 0;

    /* LE AS PESSOAS DO ARQUIVO */
    while (fread(&temp[nPessoas], sizeof(temp[nPessoas]), 1, cadastro) == 1){ // somente para armazenar todas as pessoas em um vetor de pessoas
        people[nPessoas] = temp[nPessoas];
        nPessoas++;
    }

    float afinidades[nPessoas][nPessoas];
    calcularAfinidades(people, nPessoas, afinidades);

    // escrever o nome de cada pessoa numa linha de cima e uma linha de baixo NO ARQUIVO
    for (int i = 0; i < nPessoas; i++){

        if (i == 0){
            encurtarNome(people[i].nome);
            fprintf(tabela, "   %-11s| %-11s ", "PESSOAS", people[i].nome); // so pra ficar bonito
        }
        else {
            encurtarNome(people[i].nome);
            fprintf(tabela, "| %-11s ", people[i].nome); // escreve todos os nomes horizontalmente
        }

    }

    fprintf(tabela, "\n");
    for (int i = 0; i < nPessoas; i++)
        fprintf(tabela, "---------------"); // adiciona uma linha dps de cada nome

    for (int i = 0; i < nPessoas; i++){

        fprintf(tabela, "\n");
        encurtarNome(people[i].nome);
        fprintf(tabela, "| %-11s ", people[i].nome); // escreve todos os nomes horizontalmente

        for (int j = 0; j < nPessoas; j++)
            fprintf(tabela, "|    %-6.1f   ", afinidades[i][j]);

        fprintf(tabela, "\n");

        for (int n = 0; n < nPessoas; n++) fprintf(tabela, "---------------"); // adiciona uma linha dps de cada nome
    }

    /************************************************************* */

    printf("\n\n");

    for (int i = 0; i < nPessoas; i++){

        if (i == 0){
            encurtarNome(people[i].nome);
            fprintf(stdout, "%-3s|  %-3c", "PES.", (people[i].nome)[0]); // so pra ficar bonito
        }
        else {
            encurtarNome(people[i].nome);
            fprintf(stdout, "|  %-3c", (people[i].nome)[0]); // escreve todos os nomes horizontalmente
        }

    }

    for (int i = 0; i < nPessoas; i++){

        fprintf(stdout, "\n");
        encurtarNome(people[i].nome);
        fprintf(stdout, "|%-3c", (people[i].nome)[0]); // escreve todos os nomes horizontalmente

        for (int j = 0; j < nPessoas; j++)
            fprintf(stdout, "| %-3.0f ", afinidades[i][j]);

    }

    fclose(cadastro);
    fclose(tabela);

}

void menu(void){

    printf("\n%s--------------------PESQUISANDO AFINIDADES-------------------%s", GREEN, RESET);
    printf("\n%sLorenzo Santos Raymundo%s", GREEN, RESET);
    printf("\n%s4311%s\n\n", GREEN, RESET);
    printf("%s1%s. %sCadastrar Novo Usuario%s \n", YELLOW, RESET, CYAN, RESET);
    printf("%s2%s. %sPesquise um usuario por elementos%s \n", YELLOW, RESET, CYAN, RESET);
    printf("%s3%s. %sGerar tabela de afinidades%s \n", YELLOW, RESET, CYAN, RESET);
    printf("\n%sDigite uma opcao: %s", YELLOW, RESET);

}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Pessoa pessoas[MAXPESSOAS];


    while (1){

        int op;
        char caracteristica[STRLEN];

        menu();
        scanf("%d", &op);
        fflush(stdin);

        switch (op){

            case 1:

                cadastrar_usuarios(pessoas);
                printf("\n\n%sUSUARIOS CADASTRADOS COM SUCESSO! Para mais informacoes acesse o arquivo:%s %s'usuarios cadastrados.txt'%s", GREEN, RESET, YELLOW, RESET);

                break;

            case 2:
                printf("\n%sPor qual caracteristica voce quer econtrar as pessoas?%s ", YELLOW, RESET);
                printf("\n%s(ex: Hamburguer, violao, ferrari etc):%s ", CYAN, RESET);
                gets(caracteristica);

                pesquisa(caracteristica);
                break;
            
            case 3:

                printf("\n\n%sTABELA GERADA COM SUCESSO NO ARQUIVO%s %s'tabela.txt'%s", GREEN, RESET, YELLOW, RESET);
                escreverAfinidades();
                break;

            default:
                printf("\n------------VOLTE SEMPRE!!!---------");
                return 0;
                break;
                
        }


    }

    return 0;
}