#include "libft.h"

char  **ft_sortlist(char **array)
{
  int i;
  int j;
  int sorted;
  
  if (!array)
    return (0);
    sorted = 0;
  while (!sorted)
  {
    i = 1;
    sorted = 1;
    while (array[i])
    {
      if (ft_strcmp(array[i - 1], array[i] < 0)
      {
        ft_swap(array[i - 1], array[i]);
        sorted = 0;
      }
      i++;
    }
  }
  return (array);
}
