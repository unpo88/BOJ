#include <cstdio>

int N;

int A[26][2];

void preorder(int node){
    if(node == -1){
        return;
    }
    printf("%c", (node + 'A'));
    preorder(A[node][0]);
    preorder(A[node][1]);
}

void inorder(int node){
    if(node == -1){
        return;
    }

    inorder(A[node][0]);
    printf("%c", (node + 'A'));
    inorder(A[node][1]);
}

void postorder(int node){
    if(node == -1){
        return;
    }

    postorder(A[node][0]);
    postorder(A[node][1]);
    printf("%c", (node + 'A'));
}

int main(){
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        char root, left, right;

        scanf("\n%c %c %c", &root, &left, &right);

        A[root - 'A'][0] = left != '.' ? left - 'A' : -1;
        A[root - 'A'][1] = right != '.' ? right - 'A' : -1;
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);
    printf("\n");

    return 0;
}