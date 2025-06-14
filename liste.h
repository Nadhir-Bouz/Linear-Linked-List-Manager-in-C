struct node
{
    int cle;
    struct node *next;
};

typedef struct
{
    struct node *premier;
    struct node *dernier;
} liste;

liste *create(void);
void init(liste *l, int x);
unsigned vide(liste *l);
void remplir(liste *l);
void affiche(liste *l);
void ins_av_prem(liste *l, int x);
void ins_apr_der(liste *l, int x);
void ins_av_ref(struct node *p, int x);
void ins_av(liste *l, int x);
void supp_prem(liste *l);
void supp_succ(struct node *p);
void supp_elem_ref(struct node *p);
void supp_skip(liste *l);
void supp_min(liste *l);
int existe(liste *l, int x);
void im_pair(liste *l1, liste *l2, liste *l3);
