#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "liste.h"

liste *create(void)
{
    liste *l = (liste *)malloc(sizeof(liste));
    if (l == NULL)
    {
        printf("error \n");
        exit(1);
    }
    l->premier = NULL;
    l->dernier = NULL;
    return l;
}

void init(liste *l, int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->cle = x;
    p->next = NULL;
    l->premier = p;
    l->dernier = p;
}

unsigned vide(liste *l)
{
    return ((l->premier == NULL) && (l->dernier == NULL));
}

void ins_av_prem(liste *l, int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->cle = x;
    if (vide(l))
    {
        p->next = NULL;
        l->premier = p;
        l->dernier = p;
    }
    else
    {
        p->next = l->premier;
        l->premier = p;
    }
}

void ins_apr_der(liste *l, int x)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->cle = x;
    p->next = NULL;
    if (vide(l))
    {
        l->premier = p;
        l->dernier = p;
    }
    else
    {
        l->dernier->next = p;
        l->dernier = p;
    }
}

void remplir(liste *l)
{
    int x;
    unsigned rep, i = 1;
    do
    {
        printf("Donner un entier %d de la liste: ", i);
        scanf("%d", &x);
        ins_apr_der(l, x);
        do
        {
            printf("Voulez vous inserer un autre entier ds la liste (1:oui, 0:non): ");
            scanf("%u", &rep);
        } while (!(rep == 1 || rep == 0));
        i++;
    } while (rep);
}

void affiche(liste *l)
{
    struct node *p = l->premier;
    if (vide(l))
    {
        printf("(liste vide)\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d\t", p->cle);
        p = p->next;
    }
    printf("\n");
}

void ins_av_ref(struct node *p, int x)
{
    struct node *q;
    q = (struct node *)malloc(sizeof(struct node));
    *q = *p;
    p->cle = x;
    p->next = q;
}

void ins_av(liste *l, int x)
{
    struct node *p = l->premier;
    while (p)
    {
        ins_av_ref(p, x);
        p = p->next;
        p = p->next;
    }
}

void supp_prem(liste *l)
{
    struct node *p;
    assert(!vide(l));
    p = l->premier;
    l->premier = p->next;
    free(p);
    if (l->premier == NULL)
        l->dernier = NULL; //set l->dernier to NULL, because the list is empty now.
}

void supp_succ(struct node *p)
{
    struct node *q;
    assert(p->next != NULL);
    q = p->next;
    free(q);
}

void supp_elem_ref(struct node *p)
{
    struct node *q;
    assert(p->next != NULL);
    q = p->next;
    *p = *q; // we didnt delete p but we changed it's content (prev elem still points to p)
    free(q);
}

void supp_skip(liste *l)
{
    struct node *curr = l->premier;
    struct node *temp;

    while (curr && curr->next)
    {

        temp = curr->next;
        curr->next = temp->next;

        free(temp);

        // Move to the next valid node
        curr = curr->next;
    }

    // Update the last node pointer
    l->dernier = curr;
}

void supp_min(liste *l)
{
    struct node *p = l->premier;
    struct node *min = l->premier;
    if (p == NULL)
        return; // nothing to delete

    while (p != NULL)
    {
        if (p->cle < min->cle)
            min = p; // not *min=*p cause i want min to point to p not to copy p
        p = p->next;
    }
    supp_elem_ref(min);
}

int existe(liste *l, int x)
{
    struct node *p = l->premier;
    while (p)
    {
        if (p->cle == x)
            return 1;
        p = p->next;
    }
    return 0;
}

void im_pair(liste *l1, liste *l2, liste *l3)
{
    struct node *p = l1->premier;
    while (p)
    {
        if (p->cle % 2 == 0)
        {
            if (!existe(l2, p->cle))
                ins_apr_der(l2, p->cle);
        }
        else
        {
            if (!existe(l3, p->cle))
                ins_apr_der(l3, p->cle);
        }
        p = p->next;
    }
}
