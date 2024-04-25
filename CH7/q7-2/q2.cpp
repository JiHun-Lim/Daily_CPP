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
    void ShowBookInfo()
    {
        cout << "Book Title : " << title << endl;
        cout << "ISBN : " << isbn << endl;
        cout << "Price : " << price << endl;
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

    void ShowEBookInfo()
    {
        ShowBookInfo();
        cout << "DRMKey : " << DRMKey << endl;
    }

};


int main(void)
{
    Book book("Good C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Good C++ Ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}