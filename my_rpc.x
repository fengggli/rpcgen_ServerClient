const MAXLEN = 255;
typedef struct intnode *intlist;      /* a link in the listing */  
struct intnode  
{ 
    int v;       /* name of directory entry */  
    intlist next;        /* next entry   */  
}; 

struct coupled_int_list
{
    intlist a;
    intlist b;
};

struct matrix
{
    int data<MAXLEN>;
    int d1;
    int d2;
};
struct coupled_matrix
{
    matrix a;
    matrix b;
};


 
/* The directory program definition */  
 
program CLOCKPROG  
{ 
    version MYVERS 
    { 
        string GETTIME()=1;	
        intlist MERGE(coupled_int_list l) = 2;
        string REVERSE(string s) = 3;
        string READDIR(string s) = 4;
        matrix ADDMATRIX(coupled_matrix m) = 5;
    } = 1; 
} = 0x31111111; 
