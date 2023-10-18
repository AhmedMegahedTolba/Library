typedef enum{
   ADD_BOOK=1,
   PRINT_LIBRARY,
   BORROW_BOOK,
   DELETE_BOOK,
   EXIT

}status_t;
typedef struct{
    char book_name[50];
    char author_name[50];
    int publication_year;
    int num_of_copies;;
    float price;
    char* status;


}book_t;

typedef struct{

book_t books[100];
}library_t;
