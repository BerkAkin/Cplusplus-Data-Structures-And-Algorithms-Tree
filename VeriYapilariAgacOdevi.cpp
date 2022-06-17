//191307012 BERK AKIN
#include <iostream>
#include <locale>
using namespace std;

struct düğüm
{
    int veri;
    struct düğüm* sağ;
    struct düğüm* sol;
};

typedef struct düğüm BinaryTree;

BinaryTree* yeni_düğüm(int veri)
{
    BinaryTree* p = new BinaryTree();
    p->veri = veri;
    p->sol = NULL;
    p->sağ = NULL;
    return p;
}
BinaryTree* Ekle(BinaryTree*kök,int veri)
{
    if (kök != NULL)
    {
        if (veri<kök->veri)
        {
            kök->sol = Ekle(kök->sol, veri);
        }
        else
        {
            kök->sağ = Ekle(kök->sağ, veri);
        }
    }
    else
    {
        kök = yeni_düğüm(veri);
    }
    return kök;
}
void PreOrder(BinaryTree* kök)
{
    if (kök != NULL)
    {
        cout << kök->veri << "\t";
        PreOrder(kök->sol);
        PreOrder(kök->sağ);
    }
}
void PostOrder(BinaryTree* kök)
{
    if (kök != NULL)
    {
        PostOrder(kök->sol);
        PostOrder(kök->sağ);
        cout << kök->veri << "\t";
    }
}
void InOrder(BinaryTree* kök)
{
    if (kök != NULL)
    {
        InOrder(kök->sol);
        cout << kök->veri << "\t";
        InOrder(kök->sağ);
    }
}
void Ayna(BinaryTree* kök)
{
    if (kök != NULL)
    {
        struct düğüm* geçici;
        Ayna(kök->sol);
        Ayna(kök->sağ);
        geçici = kök->sol;
        kök->sol = kök->sağ;
        kök->sağ = geçici;
    }
    else
    {
        return;
    }
}
int main()
{
    setlocale(LC_ALL, "Turkish");
    BinaryTree* Kök = NULL;
    int i = 0;
    do
    {
        cout << "Ağaç İçin Veri Girişi Yapınız (Tamsayı), Çıkış için -1 Yazın. \nSayı: ";
        cin >> i;
        if (i != -1)
        {
            Kök = Ekle(Kök,i);
        }
    } 
    while (i!=-1);

    cout << "PreOrder Düzeninde Dolaşım:" << endl;
    PreOrder(Kök);
    cout << endl;
    cout << "PostOrder Düzeninde Dolaşım:" << endl;
    PostOrder(Kök);
    cout << endl;
    cout << "InOrder Düzeninde Dolaşım:" << endl;
    InOrder(Kök);
    cout << endl;

    Ayna(Kök);

    cout << "PreOrder Düzeninde Yansıtılmış Dolaşım:" << endl;
    PreOrder(Kök);
    cout << endl;
    cout << "PostOrder Düzeninde Yansıtılmış Dolaşım:" << endl;
    PostOrder(Kök);
    cout << endl;
    cout << "InOrder Düzeninde Yansıtılmış Dolaşım:" << endl;
    InOrder(Kök);
    cout << endl;
    return 41;
}
