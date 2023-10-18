#include "library.h"
static int c=0;
int string_cmp(char*str1,char*str2)
{

    char c1,c2;
    int i=0;
    int flag=0;//equal
    for(i=0; (str1[i]&&flag==0)||(str2[i]&&flag==0); i++)
    {
        c1=str1[i];
        c2=str2[i];
        if(c1>='A'&&c1<='Z')
        {
            c1=c1-'A'+'a';
        }
        if(c2>='A'&&c2<='Z')
        {
            c2=c2-'A'+'a';
        }

        if((c1<c2)||str1[i]==0)
        {
            flag=1;//srt1 less than str2
        }
        else if((c1>c2)||str2[i]==0)
        {
            flag=2;///srt1 bilg than str2
        }


    }
    return flag;
}
void Add_book(library_t*lib)
{
    printf("\n");
    int flag=0;
    int book_id;
    if(c>99)
    {
        printf("max books shouldn't exceed 100");
        for(int j=0; j<100000000000; j++);
        c=99;
    }
    else
    {
        printf("enter name of book:");
        scanf("%s",lib->books[c].book_name);
        for(int i=0; (i<c)&&flag==0; i++)
        {
            if(string_cmp(lib->books[c].book_name,lib->books[i].book_name)==0)
            {
                flag=1;
                book_id=i;

            }
        }
        if(flag==1)
        {
            printf("the book is alreay exist\n");

            (lib->books[book_id].num_of_copies)++;
        }
        else
        {
            printf("enter name of author:");
            scanf("%s",lib->books[c].author_name);
            printf("enter publication year:");
            scanf("%d",&(lib->books[c].publication_year));
            (lib->books[c].num_of_copies)++;
            printf("enter price:");
            scanf("%f",&(lib->books[c].price));
            //printf("enter status:");
            //scanf("%s",lib->books[c].status);
            lib->books[c].status="avilable";

            c++;


        }
    }





}
void Print_library(library_t*lib)
{
    int i=0;
    if(c==0)
    {
        printf("No Books In library\n");
        //for(int j=0;j<1000000000;j++);
    }
    for(i=0; i<c; i++)
    {

        printf("\nBook Name: %s\n",lib->books[i].book_name);
        printf("Author Name: %s\n",lib->books[i].author_name);
        printf("Publication year: %d\n",lib->books[i].publication_year);
        printf("num of copies: %d \n",lib->books[i].num_of_copies);
        printf("pric: %f \n",lib->books[i].price);
        printf("status: %s \n",lib->books[i].status);
        printf("===========================================\n");


    }

}
void Borrow_book(library_t*lib)
{
    int i=0;
    int flag=0;
    char book[50];
    int book_id;
    printf("Enter Book to borrow:");
    scanf("%s",book);

    for(i=0; (i<c)&&flag==0; i++)
    {

        if(string_cmp(book,lib->books[i].book_name)==0)
        {

            flag=1;
            book_id=i;

        }

    }
    if(flag==1)
    {
        if(lib->books[book_id].num_of_copies==0)
        {
            printf("%s is not avilable now\n",book);
            lib->books[book_id].num_of_copies=0;
        }
        else
        {
            printf("\n%s is exist\n",book);

            (lib->books[book_id].num_of_copies)--;
            if(lib->books[book_id].num_of_copies==0)
            {
                lib->books[book_id].status="Not avilable";
            }

        }

    }
    else
    {
        printf("%s is not exist",book);
    }




}

void Delet_book(library_t*lib)
{
    int i=0;
    int flag=0;
    int book_id;
    char book[50];
    printf("Enter Book to Delete:");
    scanf("%s",book);

    for(i=0; (i<c)&&flag==0; i++)
    {

        if(string_cmp(book,lib->books[i].book_name)==0)
        {

            flag=1;
            book_id=i;

        }

    }
    if(flag==1)
    {
        for(int j=book_id; j<c; j++)
        {
            lib->books[j]=lib->books[j+1];
        }
        c--;
        printf("%s deleted sucessfuly\n",book);
    }
    else
    {
        printf("%s is not exist",book);
    }

}
/*
void Exit(void)
{
    return 0;
}
*/
void Menu(void)
{
    printf("\nEnter 1 to add book\n");
    printf("Enter 2 to print library\n");
    printf("Enter 3 to borrow book\n");
    printf("Enter 4 to delete book\n");
    printf("Enter 5 to exit\n");
}

