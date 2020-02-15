
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

using namespace std;
namespace sdds {
   class Book
   {
   private:
      string m_author;
      string m_title;
      string m_country;
      size_t m_year;
      double m_price;
      string m_description;
   public:
      Book();
      Book(const string& strBook);
      void trim(string& strBook);
      const string& title() const;
      const string& country() const;
      const size_t& year() const;
      double& price();
      friend ostream& operator<<(ostream& os, const Book& B);
   };
}

#endif //SDDS_BOOK_H
