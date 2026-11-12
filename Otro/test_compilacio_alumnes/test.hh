#ifndef Test_hh
#define Test_hh

// Interface of the code given precompiled (test.o).
// It exchanges with the students' code the usual things that can break when
// objects come from another compiler: strings, vectors, maps, a class with
// virtual methods, exceptions and streams.

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


/**
 * Counts how many times each word is added.
 * The students' code derives from it.
 */
class Counter {

public:

  Counter (const string& name);

  virtual ~Counter ();

  /**
   * Adds a word. Derived classes can redefine it.
   */
  virtual void add (const string& word);

  /**
   * Returns how many times word has been added.
   */
  int count (const string& word) const;

  /**
   * Returns the different words added, in alphabetical order.
   */
  vector<string> words () const;

  string name () const;

private:

  string nm;
  map<string, int> freq;
};


/**
 * Returns the prime numbers smaller than n.
 */
vector<int> primes (int n);

/**
 * Returns a/b. Throws runtime_error if b is 0.
 */
int safe_div (int a, int b);

/**
 * Writes a short report of the counter to os.
 */
void print_report (ostream& os, const Counter& c);

/**
 * Returns a description of the compiler used for test.o.
 */
string compiled_with ();


#endif
