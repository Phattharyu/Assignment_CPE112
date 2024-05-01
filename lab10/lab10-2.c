//66070503448 Phattharapong Duangkham
#include <stdio.h> 
#include <stdlib.h> 

int comparator(const void* p1, const void* p2) 
{ 
	const int(*x)[3] = p1; 
	const int(*y)[3] = p2; 

	return (*x)[2] - (*y)[2]; 
} 

void makeSet(int parent[], int rank[], int n) 
{ 
	for (int i = 0; i < n; i++) { 
		parent[i] = i; 
		rank[i] = 0; 
	} 
} 

int findParent(int parent[], int component) 
{ 
	if (parent[component] == component) 
		return component; 

	return parent[component] 
		= findParent(parent, parent[component]); 
} 

void unionSet(int u, int v, int parent[], int rank[], int n) 
{ 
	u = findParent(parent, u); 
	v = findParent(parent, v); 

	if (rank[u] < rank[v]) { 
		parent[u] = v; 
	} 
	else if (rank[u] > rank[v]) { 
		parent[v] = u; 
	} 
	else { 
		parent[v] = u; 

		rank[u]++; 
	} 
} 

int isMST(int vertices_num, int edges_num, int mat[edges_num][3]){

    int count_edges = 0;
    for (int i = 0; i < edges_num; i++) {
        if (mat[i][0] != mat[i][1])
            count_edges++;
    }

    if (count_edges == vertices_num - 1)
        return 1; 
    else
        return 0;
}

void kruskalAlgo(int n, int edge[n][3]) 
{ 
	qsort(edge, n, sizeof(edge[0]), comparator); 

	int parent[n]; 
	int rank[n]; 

	makeSet(parent, rank, n); 

	int minCost = 0; 

	for (int i = 0; i < n; i++) { 
		int v1 = findParent(parent, edge[i][0]); 
		int v2 = findParent(parent, edge[i][1]); 
		int wt = edge[i][2]; 

		if (v1 != v2) { 
			unionSet(v1, v2, parent, rank, n); 
			minCost += wt; 
		} 
	} 

	printf("%d\n", minCost); 
} 

int main() 
{ 
	int n,p; scanf("%d %d",&n,&p);
    int a[p][3];
    for(int i=0;i<p;i++) scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
    if (isMST(n, p, a)) {
        int total_weight = 0;
        for (int i = 0; i < p; i++) {
            total_weight += a[i][2];
        }
        printf("%d", total_weight);
    } else {
        kruskalAlgo(p, a);
    }
	return 0; 
}
