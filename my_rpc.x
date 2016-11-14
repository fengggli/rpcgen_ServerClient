const MAXNAMELEN = 255;   /* maximum length of a directory entry */  
 
typedef string nametype<MAXNAMELEN>;    /* a directory entry */  

 
typedef struct namenode *namelist;      /* a link in the listing */  
 
/* A node in the directory listing */  
 
struct namenode  
{ 
    nametype name;       /* name of directory entry */  
    namelist next;        /* next entry   */  
}; 
                         /* The result of a READDIR operation. */  
union readdir_res switch (int errno)  
{ 
    case 0:  
        namelist list;  /* no error : return directory listing */  
    default:  
        void;         /* error  occurred: nothing else to return */  
}; 


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

struct coupled_matrix
{
    int a<>;
    int b<>;
    int d1;
    int d2;
};


 
/* The directory program definition */  
 
program CLOCKPROG  
{ 
    version MYVERS 
    { 
        string GETTIME()=1;	
        intlist MERGE(coupled_int_list l) = 2;
        string REVERSE(string s) = 3;
        readdir_res  READDIR(nametype) = 4; 
        int ADDMATRIX(coupled_matrix m) = 5;
    } = 1; 
} = 0x31111111; 
