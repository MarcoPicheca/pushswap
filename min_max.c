
#include "push_swap.h"

int	min_int(int *j)
{
	int	n;
	int i;

	i = 0;
	n = INT_MAX;
	while (j)
	{
		if (j[i] < n)
			n = j[i];
		else
			i++;
	}
	return (n);
}

int	max_int(int *j)
{
	int	n;
	int i;

	i = 0;
	n = INT_MIN;
	while (j)
	{
		if (j[i] > n)
			n = j[i];
		else
			i++;
	}
	return (n);
}