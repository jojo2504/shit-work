#include "stdio.h"
#include <stdbool.h>
#include <stdlib.h>

struct Book{
    char* name;
    char* author;
    char* genre;
    int ISBN;
    bool borrowed;
};

struct Library{   
    struct Book books[10000];
    int bookCount;
};

void addBook(struct Library *library, char *_name, char *_author, char *_genre, int _ISBN){
    struct Book newBook = {_name, _author, _genre, _ISBN};
    if (library->bookCount < 10000){
        library->books[library->bookCount] = newBook;
        library->bookCount++;
        printf("There are still %d slots available\n", 10000-library->bookCount);
    }
    else{
        printf("There are no more spaces in this Library\n");
    }
};  

void checkBookByISBN(struct Library *library, int ISBN){

}

void checkBookByName(struct Library *library, char *_name){
    for (int i = 0; i < library->bookCount; ++i){
        if (library->books[i].name == _name){
            printf("Book Found\n");
            return;
        }
    }
    printf("Book does not exist\n");
}

void checkBookByAuthor(struct Library *library, char *_author){
    for (int i = 0; i < library->bookCount; ++i){
        if (library->books[i].author == _author){
            printf("Book Found\n");
            return;
        }
    }
    printf("Book does not exist\n");
}

void borrowBook(struct Library *library, int _ISBN){

    for (int i = 0; i < library->bookCount; ++i){
        if (library->books[i].ISBN = _ISBN){
            if (library->books[i].borrowed){
                printf("Can't take a already taken book\n");
                return;
            }
            library->books[i].borrowed = true;
            printf("Book with ISBN %d has been borrowed\n", _ISBN);
            return;
        }
    }
    printf("Book with ISBN %d doesn't exist, thus can't be borrowed\n", _ISBN);
}

void returnBook(struct Library *library, int _ISBN){
    for (int i = 0; i < library->bookCount; ++i){
        if (library->books[i].ISBN = _ISBN){
            if (!library->books[i].borrowed){
                printf("Can't return a non taken book\n");
                return;
            }
            library->books[i].borrowed = false;
            printf("The book with IBSN %d has been returned\n", _ISBN);
            return;
        }
    }
    printf("Book with ISBN %d doesn't exist, thus can't be returned\n", _ISBN);
}

void printAllAvailableBooks(struct Library *library){
    for (int i = 0; i < library->bookCount; ++i){
        if (!library->books[i].borrowed){
            printf("Book number %d:\n", i);
            printf("\tname: %s\n", library->books[i].name);
            printf("\tauthor: %s\n", library->books[i].author);
            printf("\tgenre: %s\n", library->books[i].genre);
            printf("\tISBN: %d\n", library->books[i].ISBN);
            //printf("\tborrowedState: %d\n", library->books[i].borrowed);
        }
    }
}

void run(struct Library *library){
    int input;
    char* name = malloc(100 * sizeof(char));
    char* author = malloc(100 * sizeof(char));
    char* genre = malloc(100 * sizeof(char));
    int ISBN;

    bool running = true;
    while (running){
        printf("Select action:\n");
        scanf("%d", &input);

        switch (input){      
            case 1:
                printf("Adding a book..\n");
                scanf("%s", name);
                scanf("%s", author);
                scanf("%s", genre);
                scanf("%d", &ISBN);
                addBook(library, name, author, genre, ISBN);
                break;
            
            case 2:
                printf("Borrowing a book by ISBN.. \n");
                scanf("%d", &input);
                borrowBook(library, input);
                break;

            case 3:
                printf("Returning a book by ISBN.. \n");
                scanf("%d", &input);
                returnBook(library, input);
                break;

            case 4:
                printf("Printing all avaiblables books..\n");
                printAllAvailableBooks(library);
                break;

            case 5:
                printf("Checking if book by name exists..\n");
                scanf("%s", name);
                checkBookByName(library, name);
                break;

            case 6:
                printf("Checking if author by name exists..\n");
                scanf("%s", author);
                checkBookByAuthor(library, author);
                break;
            
            default:
                printf("Input error found, exiting program..");
                running = false;
                break;
        }
    }
}

void saveLibrary(struct Library *library){

}


int main(){
    
    /*struct Library library = {.bookCount=0};
    char *filename = "test.txt";

    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < 10; i++)
        fprintf(fp, "This is the line #%d\n", i + 1);

    fclose(fp);

    run(&library);*/
    
    char* a = "BA";
    printf("%s", a);

    return 0;
}