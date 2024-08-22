#include <iostream>
#include <string>
#include <map>
using namespace std;

class Store
{
private:
  // A map to store data, where keys are strings and values are integers
  map<string, int> data;

  // Boolean flag to control the main program loop
  bool keep_running;

  // Private method to add or increment a key in the data map
  void add(string key);

public:
  // Constructor for the Store class
  Store();

  // Method to print the contents of the data map
  void print();

  // Method to print a histogram representation of the data
  void print_histogram();

  // Method to display available options to the user
  void print_options();

  // Setter method for the keep_running flag
  void set_keep_running(bool value);

  // Getter method for the keep_running flag
  bool get_keep_running();

  // Method to process data from a file
  void process(string file);
};
