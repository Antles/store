/*
 * .cpp
 *
 *  Date: 08/17/2024
 *  Author: Austin Antles
 *  Purpose: Code for the Store Application that allows a user to see frequency of words in a file.
 */

#include <iostream>
#include "Store.h"
using namespace std;

int main()
{
  // Create an instance of the Store class
  Store s = Store();

  // Main program loop, continues while keep_running is true
  while (s.get_keep_running())
  {
    // Display menu options to the user
    s.print_options();

    // Variable to store user's menu choice
    int option;

    // Get user input for menu option
    cin >> option;

    // Switch statement to handle different menu options
    switch (option)
    {
    case 1:
      // Option 1: Print store information
      s.print();
      break;
    case 2:
      // Option 2: Print histogram of store data
      s.print_histogram();
      break;
    case 3:
      // Option 3: Exit the program by setting keep_running to false
      s.set_keep_running(false);
      break;
    default:
      // Handle invalid menu options
      cout << "Invalid option" << endl;
    }
  }

  // End of program
  return 0;
}
