#include <bits/stdc++.h>
using namespace std;


struct node {
    int val;
    node *nxt;
    node() : nxt(NULL) {}
};

struct enclist {
    node *list;
    enclist() : list(NULL) {}

    void insert(int v) {
        node *n = (node*) malloc(sizeof(node));
        n->val = v;
        n->nxt = list;
        list = n;
    }

    void remove(int v) {
        node *ant = NULL;
        node *p = list;
        while (p and p->val != v) ant = p, p = p->nxt;
        if (p == NULL) return;
        if (ant == NULL) list = list->nxt;
        else ant->nxt = p->nxt;
        free(p);
    }

    bool search(int v){
        node *p;
        for(p = list; p != NULL; p = p -> nxt) if(p -> val == v) return true;
        return false;
    }

    void print(){
        node *p;
        for(p = list; p != NULL; p = p -> nxt) cout << p -> val << " ";
        cout << endl;
    }
};

int main(){
    enclist l;
    l.insert(1);
    l.insert(2);
    l.insert(3);
    l.print();

}
