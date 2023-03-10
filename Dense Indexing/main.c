#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#define MAXNUM 50
typedef struct Record
{
    int ogrNo;
    int dersKodu;
    int puan;
    int ogrOff;
} Record;


void indexDosyasiOlustur(int ogrNo[],int ogrOff[],int MAXNUM)
{
    FILE *index;
    index=fopen("C:\\Users\\Berk\\Desktop\\index.txt","w+");
    if(index==NULL)
    {
        printf("Index Dosyasi Acilamadi");
        exit(1);
    }

    for(int i=0; i<(MAXNUM)-1; i++)
    {
        for(int j=0; j<(MAXNUM)-1-i; j++)
        {
            if(ogrNo[j]>ogrNo[j+1])
            {
                int temp=ogrNo[j];
                ogrNo[j]=ogrNo[j+1];
                ogrNo[j+1]=temp;

                int temp4=ogrOff[j];
                ogrOff[j]=ogrOff[j+1];
                ogrOff[j+1]=temp4;
            }
        }
    }
    for(int i=0; i<(MAXNUM); i++)
    {
        fprintf(index,"\n%d %d",ogrNo[i],ogrOff[i]);

    }
    fclose(index);
}

void indexDosyasiniSil()
{
    int ret=remove("C:\\Users\\Berk\\Desktop\\index.txt");
    if(ret==0)
    {
        printf("\nDosya Basariyla silindi.\n");
    }
    else
    {
        printf("\nDosya silinemedi.\n");
    }
}
void indexDosyasiniGoster(int MAXNUM)
{
    FILE *index;
    index=fopen("C:\\Users\\Berk\\Desktop\\index.txt","r");
    if(index==NULL)
    {
        printf("Index Dosyasi Acilamadi");
        exit(1);
    }
    int l=0;
    int ogrNo[100],ogrOff[100];

    while(fscanf(index,"%d %d",&ogrNo[l],&ogrOff[l])==2)
    {
        l++;
    }
    printf("Index Dosyasi:\n");
    for(int i=0; i<MAXNUM; i++)
    {
        printf("\nogrNo:%d offset:%d",ogrNo[i],ogrOff[i]);
    }
    printf("\n");
    fclose(index);

}
void veriDosyasiniGoster(int MAXNUM)
{
    FILE *veri;
    veri=fopen("C:\\Users\\Berk\\Desktop\\veri.dat","rb");
    if(veri==NULL)
    {
        printf("Veri Dosyasi Acilamadi");
        exit(1);
    }
    int no[MAXNUM],kod[MAXNUM],puan[MAXNUM],offset[MAXNUM];
    int line[100],o=0;
    while(fgets(line,sizeof(line),veri))
    {
        fscanf(veri,"%d %d %d %d",&no[o],&kod[o],&puan[o],&offset[o]);
        o++;
    }

    printf("Veri Dosyasi:\n");
    for(int i=0; i<MAXNUM; i++)
    {
        printf("\nogrNo:%d dersKod:%d puan:%d offset:%d",no[i],kod[i],puan[i],offset[i]);
    }
    fclose(veri);
}

void kayitEkle(int ogrNo,int dersKodu,int puan)
{
    FILE *veri;
    veri=fopen("C:\\Users\\Berk\\Desktop\\veri.dat","a+b");
    if(veri==NULL)
    {
        printf("Veri Dosyasi Acilamadi");
        exit(1);
    }
    int ogrOff=&ogrNo;

    fprintf(veri,"\n%d %d %d %d",ogrNo,dersKodu,puan,ogrOff);

    printf("\nKayit Basariyla eklendi\n");
    fclose(veri);
}


int kayitBulSon(int arr[], int n, int x)
{
    int low = 0, high = n - 1, res = -1;
    while (low <= high)
    {

        int mid = (low + high) / 2;
        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;

        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}
void kayitSilIndex(int del)
{


    FILE *index;
    index=fopen("C:\\Users\\Berk\\Desktop\\index.txt","r+");
    if(index==NULL)
    {
        printf("Index Dosyasi Acilamadi");
        exit(1);
    }
    FILE *index1;
    index1=fopen("C:\\Users\\Berk\\Desktop\\index1.txt","w+");
    if(index==NULL)
    {
        printf("Index Dosyasi Acilamadi");
        exit(1);
    }
    fseek(index,0,SEEK_SET);
    char curr;
    int line_number=0;


    curr = getc(index);
    if(curr!=EOF)
    {
        line_number =1;
    }
    while(1)
    {
        if(del != line_number)
            putc(curr, index1);
        curr = getc(index);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }


    fclose(index1);
    fclose(index);
    remove("C:\\Users\\Berk\\Desktop\\index.txt");
    int ret=rename("C:\\Users\\Berk\\Desktop\\index1.txt","C:\\Users\\Berk\\Desktop\\index.txt");
    if(ret==0)
    {
        printf("Rename Sucessful");
    }
    else
    {
        printf("Rename not sucessful");
    }

}
void kayitSilVeri(int del)
{
    FILE *veri;
    veri=fopen("C:\\Users\\Berk\\Desktop\\veri.dat","rb");
    if(veri==NULL)
    {
        printf("Veri Dosyasi Acilamadi");
        exit(1);
    }
    FILE *veri1;
    veri1=fopen("C:\\Users\\Berk\\Desktop\\veri1.dat","wb");
    if(veri1==NULL)
    {
        printf("Veri1 Dosyasi Acilamadi");
        exit(1);
    }
    fseek(veri,0,SEEK_SET);
    char curr;
    int line_number=0;


    curr = getc(veri);
    if(curr!=EOF)
    {
        line_number =1;
    }
    while(1)
    {
        if(del != line_number)
            putc(curr, veri1);
        curr = getc(veri);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }


    fclose(veri1);
    fclose(veri);

    remove("C:\\Users\\Berk\\Desktop\\veri.dat");
    int ret=rename("C:\\Users\\Berk\\Desktop\\veri1.dat","C:\\Users\\Berk\\Desktop\\veri.dat");
    if(ret==0)
    {
        printf("Rename Veri Sucessful");
    }
    else
    {
        printf("Rename Veri not sucessful");
    }
}
void kayitGuncelle()
{
    FILE *veri;
    veri=fopen("C:\\Users\\Berk\\Desktop\\veri.dat","rb");
    if(veri==NULL)
    {
        printf("Veri Dosyasi Acilamadi");
        exit(1);
    }

    FILE *index;
    index=fopen("C:\\Users\\Berk\\Desktop\\index.txt","r+");
    if(index==NULL)
    {
        printf("Index Dosyasi Acilamadi");
        exit(1);
    }




}

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{

    time_t t;
    srand((unsigned) time(&t));


    FILE *veri;
    veri=fopen("C:\\Users\\Berk\\Desktop\\veri.dat","rb");
    if(veri==NULL)
    {
        printf("Veri Dosyasi Acilamadi");
        exit(1);
    }


    //1111111111VERI FILE OKUMA YAZDIRMA
    int buffer = 0;
    for (int a, b, c, d; fscanf(veri, "%d%d%d%d", &a, &b, &c, &d) == 4; ++buffer)
        ;

    Record *recs = malloc(buffer * sizeof *recs);

    rewind(veri);

    for (int i = 0; i < buffer && fscanf(veri, "%d%d%d%d", &recs[i].ogrNo, &recs[i].dersKodu, &recs[i].puan, &recs[i].ogrOff) == 4; ++i)
        ;





    int asNo[buffer],bsKod[buffer],csPuan[buffer],dsOffset[buffer];
    int aaNo[buffer],bbKod[buffer],ccPuan[buffer],ddOffset[buffer];
    for(int i=0; i<buffer; i++)
    {
        aaNo[i]=recs[i].ogrNo;
        bbKod[i]=recs[i].dersKodu;
        ccPuan[i]=recs[i].puan;
        ddOffset[i]=recs[i].ogrOff;
    }
    for(int i=0; i<buffer; i++)
    {
        asNo[i]=recs[i].ogrNo;
        bsKod[i]=recs[i].dersKodu;
        csPuan[i]=recs[i].puan;
        dsOffset[i]=recs[i].ogrOff;
    }
    for(int i=0; i<(buffer)-1; i++)
    {
        for(int j=0; j<(buffer)-1-i; j++)
        {
            if(asNo[j]>asNo[j+1])
            {
                int temp=asNo[j];
                asNo[j]=asNo[j+1];
                asNo[j+1]=temp;

                int temp2=bsKod[j];
                bsKod[j]=bsKod[j+1];
                bsKod[j+1]=temp2;

                int temp3=csPuan[j];
                csPuan[j]=csPuan[j+1];
                csPuan[j+1]=temp3;

                int temp4=dsOffset[j];
                dsOffset[j]=dsOffset[j+1];
                dsOffset[j+1]=temp4;
            }
        }
    }

    fclose(veri);

    //22222222222222
//kaiyt sil icin lazim kayitbullen bulim indexi sora cevirim oni kayitSil e em sora oradan sileym yazaym ayri dosyaya ilk dosyayi sileym 2. dosyayi renameleym


    //MENU//
    int secim=0;
LOOP:
    printf("***ISLEMLER***\n");
    printf("1:Index Dosyasi Olustur\n");
    printf("2:Yeni Kayit Ekle\n");
    printf("3:Kayit Bul\n");
    printf("4:Kayit Sil\n");
    printf("5:Kayit Guncelle(Calismiyor)\n");
    printf("6.Veri Dosyasini Goster\n");
    printf("7.Index Dosyasini Goster\n");
    printf("8.Index Dosyasini Sil\n");
    printf("0.Cikis yap\n");
    printf("SECIM YAPINIZ:");
    scanf("%d",&secim);

    if(secim==1)
    {

        indexDosyasiOlustur(asNo,dsOffset,buffer);
        //indexDosyasiOlustur(aaNo,ddOffset,buffer);
        printf("\n Index Dosyasi Olusturuldu\n");

    }

    if(secim==2)
    {
        int i=0;
        int ogrno,derskodu,puan;
        printf("\nEklemek istediginiz kayiti OgrNo DersKodu Puan seklinde giriniz:");
        scanf("%d %d %d",&ogrno,&derskodu,&puan);
        kayitEkle(ogrno,derskodu,puan);

    }

    if(secim==3)
    {
        int ogr;
        printf("Bulmak istediginiz OgrNo giriniz:");
        scanf("%d",&ogr);
        int n=sizeof(asNo)/sizeof(asNo[0]);
        int result= kayitBulSon(asNo,n-1,ogr);
        printf("\n%d\n",result);
        for(int i=0; i<=(result); i++)
        {
            printf("\n ogrNo:%d,dersKodu:%d,puan%d, adres:%d",asNo[i],bsKod[i],csPuan[i],dsOffset[i]);
        }
        //printf("Istediginiz kayit:%d sirasindadir",result);
        printf("\n");
    }

    if(secim==4)
    {

        int sil;
        for(int i=0; i<buffer; i++)
        {
            printf("ogNo:%d dersKodu:%d puan:%d offset:%d\n",asNo[i],bsKod[i],csPuan[i],dsOffset[i]);
        }


        printf("\n");
        printf("Silmek istediginiz ogrNo nun adresini giriniz:");
        scanf("%d",&sil);
        int c=sizeof(dsOffset)/sizeof(dsOffset[0]);
        int k=sizeof(ddOffset)/sizeof(ddOffset[0]);
        //int results=binarySearch(dsOffset,0,c,sil);
        int results=search(dsOffset,c,sil);
        int results2=search(ddOffset,k,sil);
        printf("\n%d\n",results+1);
        printf("\n%d\n",results2+1);

        //printf("Istediginiz kayit:%d sirasindadir",result);
        printf("\n");
        kayitSilIndex(results+1);
        kayitSilVeri(results2+1);



    }

    if(secim==5)
    {

    }

    if(secim==6)
    {
        veriDosyasiniGoster(buffer);

    }

    if(secim==7)
    {
        indexDosyasiniGoster(buffer);
    }

    if(secim==8)
    {
        indexDosyasiniSil();

    }
    if(secim==0)
    {

        exit(1);

    }
    goto LOOP;

    /////////////////////////////////////////////VERI DOSYASI RANDOM YAZMA////////////////////////////////
//    for(int i=0; i<MAXNUM; i++)
//    {
//        kayit[i].ogrNo=rand()%10;
//        kayit[i].dersKodu=rand()%10;
//        kayit[i].puan=rand()%100;
//        kayit[i].ogrOff=&kayit[i].ogrNo;
//    }
//    int aNo[MAXNUM],bKod[MAXNUM],cPuan[MAXNUM],dOffset[MAXNUM];
//    for(int i=0; i<MAXNUM; i++)
//    {
//        aNo[i]=kayit[i].ogrNo;
//        bKod[i]=kayit[i].dersKodu;
//        cPuan[i]=kayit[i].puan;
//        dOffset[i]=&kayit[i].ogrOff;
//    }
//    for(int i=0 ;i<MAXNUM;i++)
//    {
//        fprintf(veri,"\n%d %d %d %d",aNo[i],bKod[i],cPuan[i],dOffset[i]);
//    }



    return 0;
}
