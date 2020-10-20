#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student{
	char *name;
	int m_score;
	int f_score;
};
//루트 노드 포인터
struct student *root = NULL;

int compare(const void *cp1, const void *cp2)
{
	return strcmp(((struct student *)cp1)->name, (((struct student *)cp2)->name));
}

void print_node(const void *nodeptr, VISIT order, int level)
{
	if(order == preorder || order == leaf){
		printf("Name: %-10s Mid score: %-10d Final score: %-10d\n",(*(struct student **)nodeptr)->name, (*(struct student **)nodeptr)->m_score, (*(struct student **)nodeptr)->f_score);
}
}

int main()
{
	int std_count, i=0;
	printf("Input student size : ");
	scanf("%d", &std_count);

	//Save student nametable
	char *std_nametable = (char *)malloc(20);

	struct student *nodetable = (struct node *)malloc(std_count * sizeof(struct student));
	struct student **ret;

	printf("Input student name, mid score , final score\n");
	while(scanf("%s%d%d",std_nametable, &nodetable->m_score, &nodetable->f_score) != EOF){
		i++;
		nodetable->name = std_nametable;
		ret = (struct node **) tsearch((void *) nodetable, (void **) &root, compare);
		printf("%s student ", (*ret)->name);
		if(*ret == nodetable){
			printf("add tree.\n");
		}else{
			printf("already tree\n");
			i--;	
			
		}
		
		std_nametable += strlen(std_nametable) + 1;
		nodetable++;
		if( (i+1) > std_count) break;
	}
	printf("=================================student score list=============================\n");
	twalk((void *) root, print_node);
	return 0;
}
