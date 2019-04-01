
#include "fillit.h"

int	get_max_dots(const int tet_amount)
{
  if (tet_amount == 12 || tet_amount == 20 || tet_amount == 6 || tet_amount == 2)
    return (1);
   if (tet_amount == 11 || tet_amount == 19 || tet_amount == 5 || tet_amount == 1)
    return (5);
   if (tet_amount == 10 || tet_amount == 18)
    return (9);
   if (tet_amount == 9 || tet_amount == 16 || tet_amount == 25 || tet_amount == 4)
    return (0);
   if (tet_amount == 8 || tet_amount == 15 || tet_amount == 24 || tet_amount == 3)
    return (4);
   if (tet_amount == 13 || tet_amount == 22)
    return (12);
    if (tet_amount == 14 || tet_amount == 23 || tet_amount == 7)
    return (8);
    if (tet_amount == 17)
    return (13);
    if (tet_amount == 21)
    return (16);
    if (tet_amount == 26)
    return (17);
}
