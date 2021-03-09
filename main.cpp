//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include <string>
#include <iostream>
#include "catch.hpp"
using namespace std;
using Catch::Matchers::Equals;
//------------------------------

// Fix the following class
class Complex {
  private:
  int real;
  int imaginary;
  public:
  Complex(int real=0,int imaginary=0);
  int re();
  int im();
    void operator>>(string&) const;
    void operator<<(const string&);
};

Complex(int real, int imaginary)
{
  this->real = real;
  this->imaginary = imaginary;
}
int Complex::re()
{
  return this->real;
}
int Complex::im()
{
  return this->imaginary;
}
void Complex::operator>>(string& s) const
{
  s.append(to_string(this->real));
  if (this->imaginary > 0)
  {
    s.append("+");
  }
}
void Complex::operator<<(const string& s)
{
  if (s[0] == '-')
  {
    int re = s[1] - '0';
    this->real = -1 * re;
  }
  else
  {
    this->real = s[0] - '0'; 
  }
int ipos = s.find("i");
int bpos = ipos - 1;
int bsignpos = ipos - 2;
if (s[bsignpos] == '-')
  {
    this->imaginary = -1 * (s[bpos] - '0');
  }
    else
    {
    this->imaginary = s[bpos] - '0';
    }
}
int main()
{
  Complex c;
  cout << c.re() << c.re() << endl;
  string s = "-1-1i";
  c << s;
  cout << c.re() << c.re()<< endl;
  string s2 = " ";
  c >> s2;
  cout << s2 << endl;
}
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Complex c;
        REQUIRE( c.re() == 0 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c2" ) {
        Complex c{1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "c3" ) {
        Complex c{1,1};
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "o1" ) {
        Complex c; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("0+0i") );
    }
    SECTION( "o2" ) {
        Complex c{1, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("1+2i") );
    }
    SECTION( "o3" ) {
        Complex c{2, -2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("2-2i") );
    }
    SECTION( "o4" ) {
        Complex c{-2, 2}; std::string s{""};
        c >> s;
        REQUIRE_THAT( s, Equals("-2+2i") );
    }
    SECTION( "p1" ) {
        Complex c;
        c << "1+1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == 1 );
    }
    SECTION( "p2" ) {
        Complex c;
        c << "1-1i";
        REQUIRE( c.re() == 1 );
        REQUIRE( c.im() == -1 );
    }
    SECTION( "p3" ) {
        Complex c;
        c << "-1+0i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == 0 );
    }
    SECTION( "p4" ) {
        Complex c;
        c << "-1-2i";
        REQUIRE( c.re() == -1 );
        REQUIRE( c.im() == -2 );
    }
}
//------------------------------
