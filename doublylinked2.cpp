
#include <iostream>

using namespace std;

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

void basaEkle(int key) {
    struct node* willbeadded = new node();
    willbeadded->data = key;

    if (head == NULL) {
        head = willbeadded;
        head->next = NULL;
        head->prev = NULL;
        cout << "ilk eleman eklendi" << endl;
    }
    else {
        willbeadded->next = head;
        head->prev = willbeadded;
        head = willbeadded;
        cout << "listeye eleman eklendi" << endl;
    }

}

void sonaEkle(int key) {
    struct node* willbeadded = new node();
    willbeadded->data = key;

    if (head == NULL) {
        head = willbeadded;
        head->next = NULL;
        head->prev = NULL;
        cout << "bos listeye eleman eklendi" << endl;
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            temp->next = willbeadded;
            willbeadded->prev = temp;
            willbeadded->next = NULL;
            cout << "sona eleman eklendi" << endl;
        }
        
    }
}

void arayaEkle(int key, int sayi) {
    struct node* willbeadded = new node();
    willbeadded->data = key;

    if (head == NULL) {
        head = willbeadded;
        head->next = NULL;
        head->prev = NULL;
        cout << "bos listeye eleman eklendi" << endl;
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL) {

            if (temp->data == sayi) {
                struct node* temp2 = temp->prev;
                struct node* temp3 = temp->next;
                willbeadded->prev = temp2;
                temp2->next = willbeadded;
                willbeadded->next = temp3;
                temp3->prev = willbeadded;
                cout << "araya sayi eklendi" << endl;
                break;
            }
            temp = temp->next;
            
        }

    }
}


void yazdir() {
    system("cls");
    if (head == NULL) {
        cout << "listede eleman bulunmamaktadir" << endl;
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
        cout << temp->data << endl; 
    }
}
int main()
{
    int sayi, sayi2, secim;

    while (1) {
        cout << "listenin basina sayi eklemek icin 1" << endl;
        cout << "listenin sonuna sayi eklemek icin 2" << endl;
        cout << "araya sayi eklemek icin 3" << endl;
        cout << "listeyi goruntulemek icin 4" << endl;
        cout << "cikis icin 5" << endl;
        cout << "sec birini: ";
        cin >> secim;

        switch (secim) {
        case 1:
            cout << "listenin basina eklenecek sayiyi gir: ";
            cin >> sayi;
            basaEkle(sayi);
            break;
        case 2:
            cout << "listenin sonuna eklenecek sayiyi gir: ";
            cin >> sayi;
            sonaEkle(sayi);
            break;
        case 3:
            cout << "araya eklenecek sayiyi gir: " << endl;
            cin >> sayi;
            cout << "hangi sayidan once eklenecek: ";
            cin >> sayi2;
            arayaEkle(sayi,sayi2);
            break;
        case 4:
            yazdir();
            break;
        case 5:
            cout << "cikis yapiliyor...";
            return 0;
        default:
            cout << "seceneklerden sec sadece" << endl;
        }
    }
}


