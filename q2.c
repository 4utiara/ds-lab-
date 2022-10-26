//evaluate a polynomial//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
    int n;
    struct Term *terms;
};
void create(struct Poly *p)
{
    int i;
    printf("Number of terms?");
    scanf("%d", &p->n);
    p->terms = (struct Term *)malloc(p->n * sizeof(struct Term));

    printf("Enter terms\n");
    for (i = 0; i < p->n; i++)
        scanf("%d%d", &p->terms[i].coeff, &p->terms[i].exp);
}

void display(struct Poly p)
{
    int i;
    for (i = 0; i < p.n; i++)

        printf("%dx%d+", p.terms[i].coeff, p.terms[i].exp);
    printf("\n");
}

void evaluate(struct Poly p, int a)
{
    int sum = 0;
    for (int i = 0; i < p.n; i++)
    {
        sum = sum + p.terms[i].coeff * pow(a, p.terms[i].exp);
    }
    printf("the evaluated expression is - %d ", sum);
}
int main()
{
    int a;
    struct Poly p;

    create(&p);

    printf("enter the number with which you want to evaluate the exprssion");
    scanf("%d", &a);
    evaluate(p, a);
    return 0;
}
