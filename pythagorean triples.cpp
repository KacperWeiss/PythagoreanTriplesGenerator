#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>

/*!
 * \file pythagorean triples.cpp
 *
 * File includes short program that generates pithagorean triples based on 2 integers.
 */

using namespace std;

void menu() // Short function that displays menu
{
  cout << "n - shows and adds a new pythagorean triple to file\n"
       << "r - removes last file and replace it with new one\n"
       << "s - saves last file and create new one to work with\n"
       << "m - shows menu again\n"
       << "q - ends a program (not saved files will be lost)\n";
}

int main()
{
  fstream _file;
  string name = "List of pythagorean triples";	//default name for a file with resaults
  int v,u;
  char choice;
  int pythagoreanTriple[3];
    cout << "It's pythagorean triples generator!"<< endl
         << "If u write 2 different intiger numbers it will generate a pythagorean triple for you!\nEnjoy!\n\n";
  menu();

  while (true)
  {
    cout << "Your choice? (m - menu) > _\b";
    cin >> choice;
    if(strchr("nrsmq", choice))
    {
      if (choice == 'n') // Creates new pythagorean triple
      {
        cout << "Give me your first number!\n";
	cin >> v;
	cout << "Give me your second number!\n";
	cin >> u;
	pythagoreanTriple[0]=pow(u,2)-pow(v,2);
	pythagoreanTriple[1]=2*u*v;
	pythagoreanTriple[2]=pow(u,2)+pow(v,2);
	cout << "Your pythagorean triple is: " << (pythagoreanTriple[0]>=0 ? pythagoreanTriple[0] : -pythagoreanTriple[0]) <<"^2 + " 
             << pythagoreanTriple[1] <<"^2 = " << pythagoreanTriple[2] <<"^2\n";

	_file.open(name+string(".dat"), ios::app);
	if (!_file.is_open())
	  cerr << "Opening of file \"" << name << "\" failed" << endl;
	_file << "(" << (pythagoreanTriple[0]>=0 ? pythagoreanTriple[0] : -pythagoreanTriple[0]) << ","
	      << pythagoreanTriple[1] << "," << pythagoreanTriple[2] << ")\n";
	_file.close();
      }
      else if (choice == 'r') // removes last file with resaults
      {
	system("rm -f *.dat"); // removes last file with resaults
	cout << "New name: ";
	cin >> name;
	_file.open(name+string(".dat"), ios::app); // creates new file for resaults
	if (!_file.is_open())
	  cerr << "Opening of file \"" << name << "\" failed" << endl;
	_file.close();
      }
      else if (choice == 's') // creates a folder (if it's not already existing) for saved resaults
      {
	system("mkdir -p saved\n cp *.dat saved");
	system("rm -f *.dat");
	cout << "New name: ";
	cin >> name;
	_file.open(name+string(".dat"), ios::app);
	if (!_file.is_open())
	  cerr << "Opening of file \"" << name << "\" failed" << endl;
	_file.close();
      }
      else if (choice == 'm')
      {
	menu();
      }
      else if (choice == 'q')
      {
	cout << "Thank You for using this program!\n";
	break;
      }
    }
    else // if someone chose non-existing option it will show error allert and menu 
    {
      cin.clear();
      cin.ignore(10000, '\n');
      cerr << "Incorrect order\n";
      choice = ' ';
      menu();
    }
  }
system("rm -f *.dat");
}
