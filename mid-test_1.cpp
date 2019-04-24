/* Nama : Ahmad Irfan Fadholi
NPM : 140810180034 
Tgl : 24 April 2019
Deskripsi : Program Single Linked List Restaurant*/

#include<iostream>
#include<string.h>

using namespace std;

struct ElemtList{
	int no;
	string nama_makanan;
	string harga;
	int jumlah;
	ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;
void createList(List& First){
	First=NULL;
}
void createElement(pointer& pBaru){
	pBaru=new ElemtList;
	cout << "No.Makanan	: "; cin >> pBaru->no;
	cout << "Nama Makanan	: "; cin>>pBaru->nama_makanan; cin.ignore(255,'\n');
	cout << "Harga	: "; cin >> pBaru->harga;
	pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if (First==NULL){
		First=pBaru;
	}
	else {
		last=First;
		while(last->next!=NULL){
			last=last->next;
		}
		last->next=pBaru;
	}
}

void updatePesanan(List &First){
	pointer pBantu;
	pBantu=First;
	while(pBantu!=NULL){
		cout << "Masukkan Jumlah Pesanan	"<< pBantu->nama_makanan<<endl;
		cout << "Masukkan Jumlah : "; cin >> pBantu->jumlah;
		pBantu=pBantu->next;
	}
}

void swap(pointer& p1,pointer& p2){
	int tempjumlah = p1->jumlah;
	
	p1->jumlah = p2->jumlah;
	p2->jumlah = tempjumlah;
	int tempno = p1->no;
	
	p1->no = p2->no;
	p2->no = tempno;
	string tempnama_makanan = p1->nama_makanan;
	p1->nama_makanan = p2->nama_makanan;
	p2->nama_makanan = tempnama_makanan;
	string tempharga = p1->harga;
	p1->harga = p2->harga;
	p2->harga = tempharga;
}

void sorting(List& First){
    int swapped, i;
    pointer ptr1;
    pointer lptr = NULL;

    if (First == NULL)
        return;

    do{
        swapped = 0;
        ptr1 = First;

        while(ptr1->next!=lptr){
            if (ptr1->jumlah>ptr1->next->jumlah){
                swap(ptr1,ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while(swapped);
}

void traversal(List &First){
	pointer pBantu;
	pBantu=First;
	cout<<"No\tNama Makanan\t\tHarga\t\tJumlah\n";
	while(pBantu != NULL){
        	cout <<pBantu->no<<"\t"<<pBantu->nama_makanan<<"\t\t\t"<<pBantu->harga<<"\t\t"<<pBantu->jumlah<<endl;
			pBantu=pBantu->next;
	}
}

int main (){
	List Makanan;
	pointer p;
	int n;
	createList(Makanan);
	cout<<"Banyak Makanan : "; cin>>n;
	for (int i=0;i<n;i++){
		createElement(p);
		insertLast(Makanan,p);
	}
	updatePesanan(Makanan);
	sorting(Makanan);
	traversal(Makanan);
}



