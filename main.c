#include <stdio.h>
#include "liste.h"

int main()
{
    unsigned x;
    liste *l = create();
    remplir(l);
    printf("ur liste : \n");
    affiche(l);

    printf("donnez un nbr a inser : ");
    scanf("%u", &x);
    ins_av(l, x);
    affiche(l);

    printf("liste after deleting : \n");
    supp_skip(l);
    affiche(l);

    liste *l2 = create();
    liste *l3 = create();
    im_pair(l, l2, l3);
    printf("liste pair : \n");
    affiche(l2);
    printf("liste impair : \n");
    affiche(l3);

    return 0;
}
