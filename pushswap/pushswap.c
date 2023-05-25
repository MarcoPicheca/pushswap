#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct t_list{
	int	content;
	struct t_list *next;
}	t_list;

int		ft_check(char **av)
{
	int	i = 0;

	while (av[i])
	{
		if ((av[i] >= "0" && av[i] >= "9") || av[i] == "-")
			i++;
		else
			return(1);
	}
	return(0);
}

t_list	*stackato(char *av, t_list *stack_a)
{
	int data = 0;

	data = atoi(av);
	stack_a->content = data;
	stack_a = stack_a->next;
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_list *stack_a;
	int i = 1;

	stack_a = (t_list*)malloc(ac * sizeof(t_list));
	if (!stack_a || ac < 2)
		return (0);
	else
	{
		stack_a->content = atoi(av[i]);
		//printf("sono qua %d\n", stack_a->content);
		while (i < ac && stack_a != NULL)
		{
			if (ft_check(&av[i]) == 1)
			{
				free(stack_a);
				exit(0);
			}
			printf("%d\n", stack_a->content);
			stack_a = stack_a->next;
			stackato(av[i], stack_a);
			i++;
		}
	}
}