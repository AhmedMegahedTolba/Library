#include <stdio.h>
#include <stdlib.h>
#include"library.h"

int main()
{
    library_t lib;
    status_t order;
    /*
    //Print_library(&lib);
    Add_book(&lib);
    //Print_library(&lib);
    //Borrow_book(&lib);
    Add_book(&lib);
    Print_library(&lib);
    Delet_book(&lib);

    Print_library(&lib);
    Add_book(&lib);
    Print_library(&lib);
    */

    while(1)
    {


        Menu();
        scanf("%d",&order);

            system("cls");




        if(order==ADD_BOOK)
        {
            Add_book(&lib);


        }
        else if(order==PRINT_LIBRARY)
        {
            Print_library(&lib);
        }
        else if(order==BORROW_BOOK)
        {
            Borrow_book(&lib);

        }
        else if(order==DELETE_BOOK)
        {
            Delet_book(&lib);

        }
        else if(order==EXIT)
        {
           break;
        }
        else
        {
            printf("Wrong entery number\n");
        }



    }
    return 0;
}
