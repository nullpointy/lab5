

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Book.h"

using namespace std;

namespace sdds {
  
   Book::Book() {
      m_author = "";
      m_title = "";
      m_country = "";
      m_year = 0;
      m_price = 0;
      m_description = "";
   }
   
   Book::Book(const string& strBook) {
      string bookText = strBook;

      //format: AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
      //author
      m_author = bookText.substr(0, bookText.find(','));
      trim(m_author);

      //title
      string title = bookText.erase(0, bookText.find(',') + 1);
      m_title = title.substr(0, title.find(','));
      trim(m_title);

      //country
      string country = title.erase(0, title.find(',') + 1);
      m_country = country.substr(0, country.find(','));
      trim(m_country);

      //price
      string price = country.erase(0, country.find(',') + 1);
      m_price = stod(price.substr(0, price.find(',')));
      
      //year
      string year = price.erase(0, price.find(',') + 1);
      m_year = stoi(year.substr(0, year.find(',')));

      //description
      string description = price.erase(0, price.find(',') + 1);
      m_description = description.substr(0, description.find('.')+1);
      trim(m_description);
   }

   void Book::trim(string& strBook) {
      strBook.erase(0, strBook.find_first_not_of(" "));
      strBook.erase(strBook.find_last_not_of(" ") + 1);
   }

   const string& Book::title() const {
      return m_title;
   }
   
   const string& Book::country() const {
      return m_country;
   }
   
   const size_t& Book::year() const {
      return m_year;
   }
   
   double& Book::price() {
      return m_price;
   }
   
   ostream& operator<<(ostream& os, const Book& B) {
      os << setw(20) << B.m_author << " | "
         << setw(22) << B.m_title << " | "
         << setw(5) << B.m_country << " | "
         << setw(4) << B.m_year << " | " 
         << setw(6) << fixed << setprecision(2) << B.m_price << " | "
         << B.m_description << endl;
      return os;
   }

}
