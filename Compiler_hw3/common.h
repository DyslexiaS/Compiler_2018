#ifndef COMMON_H
#define COMMON_H
#include <stdbool.h>
/* Strcuct */
typedef union _DATA{
    int     idata;
    double  fdata;
    char    sdata[101];
}DATA;

typedef struct _INT_FLOAT{
    int     type;
    int     index;
    DATA    data;
}INT_FLOAT;

typedef struct _Variable{
    char    id[100];
    int     index;
    INT_FLOAT  Val;
}Variable;

struct Table{
    int index;
    int depth;
    Variable Var[1001];
    struct Table* prev;
    struct Table* next;
};
typedef struct _FuncName{
    int type;
    char name[20];
}FuncName;

#define CONST -1
#define STACK_SIZE 10
#endif
