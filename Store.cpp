#include "Store.h"
#include <fstream>
#include <string>

// Constructor
Store::Store()
{
  data = map<string, int>();                     // Initialize empty map
  keep_running = true;                           // Set initial state to keep running
  process("CS210_Project_Three_Input_File.txt"); // Process initial input file
}

// Private method to add or increment a key in the data map
void Store::add(string key)
{
  if (data.find(key) != data.end())
  {
    data[key] += 1; // Increment count if key exists
  }
  else
  {
    data[key] = 1; // Initialize count to 1 if new key
  }
}

// Print the contents of the data map
void Store::print()
{
  map<string, int>::iterator it = data.begin();

  while (it != data.end())
  {
    cout << it->first << " " << it->second << endl;
    ++it;
  }
}

// Print a histogram representation of the data
void Store::print_histogram()
{
  map<string, int>::iterator it = data.begin();

  while (it != data.end())
  {
    cout << it->first << " ";
    for (int i = 0; i < it->second; i++)
    {
      cout << "*";
    }
    cout << endl;
    ++it;
  }
}

// Print the available options for the user
void Store::print_options()
{
  cout << "Options:" << endl;
  cout << "1. Print data" << endl;
  cout << "2. Print histogram" << endl;
  cout << "3. Quit" << endl;
}

// Setter for keep_running flag
void Store::set_keep_running(bool value)
{
  keep_running = value;
}

// Getter for keep_running flag
bool Store::get_keep_running()
{
  return keep_running;
}

// Process input file and update data map
void Store::process(string file)
{
  ifstream input(file);
  string word;

  if (input.is_open())
  {
    while (input >> word)
    {
      add(word);
    }
    input.close();
  }

  // Write processed data to frequency.dat
  ofstream output("frequency.dat");
  map<string, int>::iterator it = data.begin();
  while (it != data.end())
  {
    output << it->first << " " << it->second << endl;
    ++it;
  }
  output.close();
}
