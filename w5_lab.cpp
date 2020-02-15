// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Book.h"
#include "Book.h"

using namespace sdds;

// ws books.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Book library[7];
	{
		// TODO: load the collection of books from the file "argv[1]".
		//       - read one line at a time, and pass it to the Book constructor
		//       - store each book read into the array "library"
		//       - lines that start with "#" are considered comments and should be ignored
            //read file to count number of records present
         // Process the file
      int i = 0;
      ifstream file;
      file.open(argv[1]);
      string bookText;
      if (file.good()) {
         while (getline(file, bookText)) {
            if (bookText[0] != '#') {
               library[i] = Book(bookText);
                  i++;
            }
         }
      }
   }
	double usdToCadRate = 1.3;
	double gbpToCadRate = 1.5;

	// TODO: create a lambda expression that fixes the price of a book accoding to the rules
	//       - the expression should receive a single parameter of type "Book&"
	//       - if the book was published in US, multiply the price with "usdToCadRate"
	//            and save the new price in the book object
	//       - if the book was published in UK between 1990 and 1999 (inclussive),
	//            multiply the price with "gbpToCadRate" and save the new price in the book object
   auto fixedPrice = [&](Book& B) {
      double price = 0;
      if (B.country() == "US") {
         price = B.price() *= usdToCadRate;
      }
      else if (B.country() == "UK" && B.year() >= 1990 && B.year() <= 1999) {
         price = B.price() *= gbpToCadRate;
      }
      return price;
   };

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content\n";
	std::cout << "-----------------------------------------\n";
	for (auto& bookText : library)
		std::cout << bookText;
	std::cout << "-----------------------------------------\n\n";

	// TODO: iterate over the library and update the price of each book
	//         using the lambda defined above.
   for (auto& bookText : library) {
      fixedPrice(bookText);
   }

	std::cout << "-----------------------------------------\n";
	std::cout << "The library content (updated prices)\n";
	std::cout << "-----------------------------------------\n";
	for (auto& bookText : library)
		std::cout << bookText;
	std::cout << "-----------------------------------------\n";

	return 0;
}
