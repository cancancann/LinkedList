#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;

};

struct node* start = NULL;
struct node* temp = NULL;
struct node* q = NULL;

void sonaEkleme(int veri)
{
    struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
    eklenecek->data = veri;
    eklenecek->next = NULL;

    if(start == NULL)
    {
        start = eklenecek;
    }

    else
    {
        q = start;
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = eklenecek;
    }
}


void yazdir()
{
    q = start;
    while(q->next !=NULL)
    {
        printf("%d=>", q->data);
        q = q->next;

    }
    printf("%d",q->data);
}


void basaEkleme(int basa)
{
    struct node *basaGelecek = (struct node *)malloc(sizeof(struct node));
    basaGelecek->data = basa;
    basaGelecek->next = start;
    start = basaGelecek;
}

void arayaEkleme(int x, int y)
{
    struct node* arayaEklenecek = (struct node*)malloc(sizeof(struct node));
    arayaEklenecek->data = y;
    q = start;
    while(q->next->data!= x)
    {
        q = q->next;
    }
    struct node* onune = (struct node*)malloc(sizeof(struct node));
    onune = q->next;
    q->next = arayaEklenecek;
    arayaEklenecek->next = onune;
}

void sondanSil()
{
    q = start;
    while(q->next->next !=NULL)
    {
        q = q->next;
    }
    free(q->next);
    q->next= NULL;
}

void bastanSil()
{
    struct node * ikinci = NULL;
    ikinci = start->next;
    free(start);
    start = ikinci;
}

void aradanSil(int x)
{
    if(start->data == x)
    {
        bastanSil();
    }

    struct node *onceki = NULL;
    struct node *sonraki = NULL;

    q =start;
    while(q->next->data!=x)
    {
        q = q->next;
    }
    if(q->next==NULL)
    {
        sondanSil();
    }

    onceki = q;
    sonraki = q->next->next;
    free(q->next);
    onceki->next = sonraki;
}

int main()
{
    int secim, sona, basa, x, y;
    while(1==1)
    {
        printf("\n1- Sona eleman ekleme");
        printf("\n2- Basa eleman ekleme");
        printf("\n3- Araya eleman ekleme");
        printf("\n4- Sondan  eleman sil");
        printf("\n5- Bastan  eleman sil");
        printf("\n6- Aradan  eleman sil");

        printf("\n Yapmak istediqiniz islemi secin\n");
        scanf("%d",&secim);

        switch(secim)
        {
        case 1:
            printf("\n Sona eklemek istediginiz elemani girin...");
            scanf("%d", &sona);
            sonaEkleme(sona);
            yazdir();
            break;
        case 2:
            printf("\n Basa eklemek istediginiz elemani girin...");
            scanf("%d", &basa);
            basaEkleme(basa);
            yazdir();
            break;
        case 3:
            printf("\n Hangi sayinin onune ekleme yapacaksiniz...");
            scanf("%d", &x);
            printf("\n hangi sayiyi gireceksiniz?...");
            scanf("%d", &y);
            arayaEkleme(x,y);
            yazdir();
            break;
        case 4:
            sondanSil();
            yazdir();
            break;
        case 5:
            bastanSil();
            yazdir();
            break;
        case 6:
            printf("\nsilinmesini istediginiz sayiyi girin...");
            scanf("%d",&secim);
            aradanSil(secim);
            yazdir();
            break;

        }




    }



}
