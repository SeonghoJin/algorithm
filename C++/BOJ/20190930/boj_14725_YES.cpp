/*
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>

struct element;
bool compare(const element *a, const element *b);

struct element
{
	char name[16];
	std::vector<element*> child;
	element(const char *temp) { strncpy(name, temp, 16); }
	~element()
	{
		for (int i = 0; i < child.size(); i++) delete child[i];
	}
	int find(const char *temp)
	{
		for (int i = 0; i < child.size(); i++) if (strcmp(child[i]->name, temp) == 0) return i;
		return -1;
	}
	void print(int space)
	{
		std::sort(child.begin(), child.end(), compare);
		for (int i = 0; i < child.size(); i++)
		{
			for (int j = 0; j < space; j++) printf("-");
			printf("%s\n", child[i]->name);
			child[i]->print(space+2);
		}
	}
};

bool compare(const element *a, const element *b)
{
	return (strcmp(a->name, b->name) < 0);
}

int main()
{
	element* root = new element("");
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int K, char_cursor = 0;
		char name[16] = {};
		scanf("%d ", &K);
		element* cursor = root;
		while (K > 0)
		{
			char temp;
			int ret;
			ret = scanf("%c", &temp);
			name[char_cursor++] = temp;
			if (temp == ' ' || temp == '\n' || ret == EOF)
			{
				name[char_cursor - 1] = '\0';
				char_cursor = 0;
				int index = cursor->find(name);
				if (index != -1) cursor = cursor->child[index];
				else
				{
					element* new_eat = new element(name);
					cursor->child.push_back(new_eat);
					cursor = new_eat;
				}
				char_cursor = 0;
				K--;
			}
		}
	}
	root->print(0);
	delete root;
	return 0;
}*/