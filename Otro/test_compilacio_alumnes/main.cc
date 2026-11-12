// Code compiled by the students, linked with the precompiled object test.o.

#include "test.hh"


// A class derived from a class of the precompiled object.
struct LowerCounter : public Counter {

  LowerCounter () : Counter("lower") { }

  // Redefines a virtual method of the precompiled class.
  void add (const string& word) override {
    string w = word;
    for (char& c : w) c = tolower(c);
    Counter::add(w);
  }
};


int main () {
  int errors = 0;
  auto check = [&](bool ok, const string& what) {
    cout << (ok ? "  ok     " : "  ERROR  ") << what << endl;
    if (not ok) ++errors;
  };

  cout << "test.o was compiled with: " << compiled_with() << endl;

  LowerCounter c;
  Counter* p = &c;   // Virtual call through a pointer to the base class.
  for (string w : { "Apple", "pear", "APPLE", "Pear", "apple" }) p->add(w);
  check(c.count("apple") == 3 and c.count("pear") == 2, "virtual methods and maps");
  check(c.words() == vector<string>({ "apple", "pear" }), "vectors of strings");

  vector<int> v = primes(30);
  check(v == vector<int>({ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 }), "vectors of ints");

  bool caught = false;
  try { safe_div(1, 0); }
  catch (const runtime_error& e) { caught = (string(e.what()) == "division by zero"); }
  check(caught and safe_div(7, 2) == 3, "exceptions");

  print_report(cout, c);

  if (errors == 0) cout << "Everything works: the precompiled object can be used on this computer." << endl;
  else cout << errors << " error(s): the precompiled object does not work well on this computer." << endl;
  return errors == 0 ? 0 : 1;
}
