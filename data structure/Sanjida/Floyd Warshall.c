#include<stdio.h>
int V=4;
void floydWarshall (int graph[][V])
{

	int dist[V][V], i, j, k;

	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];

	for (k = 0; k < V; k++)
	{

		for (i = 0; i < V; i++)
		{

			for (j = 0; j < V; j++)
			{

				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	printSolution(dist);
}

void printSolution(int dist[][V])
{
	printf ("The following matrix shows the shortest distances"
			" between every pair of vertices \n");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == 99999)
				printf("%7s", "INF");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
}

int main()
{

	int graph[4][4] = { {0, 5, 99999, 10},
						{99999, 0, 3, 99999},
						{99999, 99999, 0, 1},
						{99999, 99999, 99999, 0}
					};

	floydWarshall(graph);
	return 0;
}

