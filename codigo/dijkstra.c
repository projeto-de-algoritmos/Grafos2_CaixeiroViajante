#include<stdio.h>
#include<stdlib.h>
#define INFINITO 9999
#define MAX 10
 
void addEdge(int x, int y, int G[MAX][MAX]); 
void dijkstra(int G[MAX][MAX],int n,int noInicial);
 
int main()
{
	int G[MAX][MAX],i,j,n,u,x,y;
	printf("Digite o numéro de vertices desejadas: "); //Recebendo o numero de vertice.
	scanf("%d",&n);


	//Inicializando a Matriz
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i == j){
				G[i][j] = 1;
			}else{
				G[i][j] = 0;
			}
			
		}
	}


	printf("\nInforme as adjacencias (termine com EOF): \n"); //Lendo as adjacencias
	while(scanf("%d %d", &x, &y) == 2){
		if(x < n && y < n){
			addEdge(x, y, G);
		}else{
			printf("Valor invalido!\n");
		}
	}

	
	printf("\nDigite o nó inicial: "); //Inserindo o nó inicial.    
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	printf("\n");
	
	return 0;
}

//Função de adicionar aresta
void addEdge(int x, int y, int G[MAX][MAX]){
	G[x][y] = 1;
	G[y][x] = 1;

	return;
}


//Função Dijkstra 
void dijkstra(int G[MAX][MAX],int n,int noInicial)
{
 
	int custo[MAX][MAX],distance[MAX],predecessor[MAX];
	int visitado[MAX],count,minimaDistancia,noProximo,i,j;
	
	//predecessor [] armazena o predecessor de cada nó
	//O count(contador) dá o número de nós vistos até agora. 
	//Criando a matriz de custos.
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(G[i][j] == 0)
				custo[i][j] = INFINITO;
			else
				custo[i][j] = G[i][j];
	
	//Inicializando predecessor[],distance[] e visitado[]
	for(i = 0; i < n; i++)
	{
		distance[i] = custo[noInicial][i];
		predecessor[i] = noInicial;
		visitado[i] = 0;
	}
	
	distance[noInicial] = 0;
	visitado[noInicial] = 1;
	count = 1;
	
	while(count < n-1)
	{
		minimaDistancia = INFINITO;
		
		//Proxímo nó dá o nó a uma distância mínima.
		for(i = 0; i < n; i++)
			if(distance[i] < minimaDistancia && !visitado[i])
			{
				minimaDistancia = distance[i];
				noProximo = i;
			}
			
			//Verificando se existe um caminho melhor através do próximo nó			
			visitado[noProximo] = 1;
			for(i = 0; i < n; i++)
				if(!visitado[i])
					if(minimaDistancia + custo[noProximo][i] < distance[i])
					{
						distance[i] = minimaDistancia + custo[noProximo][i];
						predecessor[i] = noProximo;
					}
		count++;
	}
	
 
	//Imprimando o caminho e a distância de cada nó(s)
	for(i = 0; i < n; i++)
		if(i != noInicial)
		{
			printf("\nDistância do nó %d = %d", i, distance[i]);
			printf("\nCaminho = %d", i);
			
			j=i;
			do
			{
				j=predecessor[j];
				printf("<-%d", j);
			}while(j != noInicial);
	}
}
