#include <iostream>
#include <cstring>

using namespace std;

class Book
{
private:
    char * title;
    char * isbn;
    int price;

public:
    Book(char * mytitle, char * myisbn, int myprice) : price(myprice)
    {
        title = new char[strlen(mytitle) + 1];
        strcpy(title, mytitle);

        isbn = new char[strlen(myisbn) + 1];
        strcpy(isbn, myisbn);
    }

    Book(const Book& ref) : price(ref.price)
    {
        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);

        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
        
    }

    Book& operator=(const Book& ref)
    {
        delete []title;
        delete []isbn;

        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);

        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);

        price = ref.price;
        return *this;

    }

    void ShowBookInfo()
    {
        cout << "Book Title : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "Price : " << price << endl;
    }

    ~Book()
    {
        delete []title;
        delete []isbn;
    }

};

class EBook : public Book
{
private:
    char * DRMKey;

public:
    EBook(char * mytitle, char * myisbn, int myprice, char * myDRMKey) : Book(mytitle, myisbn, myprice)
    {
        DRMKey = new char[strlen(myDRMKey) + 1];
        strcpy(DRMKey, myDRMKey);
    }

    EBook(const EBook& ref) : Book(ref)
    {
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
    }

    EBook& operator=(const EBook& ref)
    {
        Book::operator=(ref);
        delete []DRMKey;
        DRMKey = new char[strlen(ref.DRMKey) + 1];
        strcpy(DRMKey, ref.DRMKey);
        return *this;
    }


    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "DRMKey : " << DRMKey << endl;
    }

    ~EBook()
    {
        delete []DRMKey;
    }

};


int main(void)
{
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Good C++ Ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();

    EBook clone = ebook;
    clone.ShowEBookInfo();
    return 0;
}