#include <stdlib.h>
#include <unistd.h>
#include<stdio.h>

int ft_strlen(char *s)
{
    int l = 0;
    while (s[l])
        l++;
    return (l);
}

void	infin_add(char *s1, char *s2)
{
	int l1 = ft_strlen(s1);
	int l2 = ft_strlen(s2);
	int sign1 = 1;
	int sign2 = 1;
	int res_len = (l1 > l2 ? l1 : l2);
	char *res = malloc(res_len + 1);
	res[res_len] = '\0';
	if (s1[0] == '-')
		sign1 = -1;
	if (s2[0] == '-')
		sign2 = -1;
	if (sign1 != sign2)
	{
		int swap = 0;
		if (l1 == l2)
		{
			for (int i = 0; i < l1; i++)
			{
				if (s2[i] > s1[i])
				{
					swap = 1;
					break;
				}
			}
		}
		else
		{
			if (l2 > l1)
				swap = 1;
		}
	}
	
}


int main(int ac, char **av)
{
    if (ac == 3)
        infin_add(av[1], av[2]);
    write(1, "\n", 1);
}