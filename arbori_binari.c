#include<stdio.h>
#include<stdlib.h>

typedef struct Nod {
	int cheie;
	struct Nod* left;
	struct Nod* right;
} Nod;

Nod* Creere_nod(int val) {
	Nod* arb = (Nod*)malloc(sizeof(Nod));
	arb->cheie = val;
	arb->left = NULL;
	arb->right = NULL;
	return arb;
}


Nod* Add(Nod* arb, int val) {
	if (arb == NULL) return Creere_nod(val);
	if (val > arb->cheie) { arb->right = Add(arb->right, val); }
	else if (val < arb->cheie) { arb->left = Add(arb->left, val); }
	return arb;
}

Nod* Caut_nod(Nod* arb, int x) {
	if (arb == NULL) return NULL;
	// comparam valorile si verificam daca e in arborele drept sau stag si se cauta recursiv
	if (x > arb->cheie) return Caut_nod(arb->right, x);
	else if (x < arb->cheie) return Caut_nod(arb->left, x);
	return arb;
}

Nod* minn(Nod* nod) {
	if(nod==NULL) return NULL;
	while (nod->left != NULL) { nod = nod->left; }
	return nod;
}

Nod* sterg(Nod* nod, int x) {
	// p1: trebuie gasit pozitia lui x , care dupa se va pune pe cheie
	if (nod == NULL) return NULL;
	if (x < nod->cheie) nod->left= sterg(nod->left, x);
	else if (x > nod->cheie) nod->right= sterg(nod->right, x);
	//p2: treatat cazul 1 cand nodul pe caare il stergem are 1 copil sau nu are
	else {
		if (nod->right == NULL) {
			Nod* temp = nod->drept;
			free(nod);
			return temp;
		}
		else if (nod->right== NULL) {
			Nod* temp = nod->left;
			free(nod);
			return temp;
		}
         // daca nu se intra incazul 1 , tratam cazul 2 cand nodul de sters are 2 fiii
		Nod* temp = minn(nod->right);
		// se gaseste val minimaa din stanga si se inlocuiesete cu val din x
		nod->cheie = temp->cheie;
		// se sterge val din arborele drept 
		nod->right = sterg(nod->right, temp->cheie);

	}
	return nod;
}

void preordine(Nod* nod) {
	if (nod == NULL) return;
	 
	printf("%d ", nod->cheie);
	preordine(nod->left);
	preordine(nod->right);
}

void inordine (Nod *nod){
	if(Nod==NULL) return NULL;
	inordinr(nod->left);
	printf("%d ", nod->cheie);
	inordine(nod->right);

}


void postordine(Nod* nod){
	 preordine(nod->left);
	  preordine(nod->right);
	  printf("%d  ", nod->cheie);
}
	





int main() {
	Nod* arb = NULL;
	arb = Creere_nod(10);
	arb=Add(arb, 7);
	arb=Add(arb, 5);
	arb=Add(arb, 9);
	arb=Add(arb, 11);
	Nod* x = Caut_nod(arb, 77);
	if (x == NULL) printf(" nu s a gasit valoarea 77 ");
	else printf(" s a gasit valorea 77");
	arb=sterg(arb, 11);
	preordine(arb);
	return 0;
}