#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

void menu()
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
  string name = "List of pythagorean triples";
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
      if (choice == 'n')
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
      else if (choice == 'r')
      {
	system("rm -f *.dat");
	cout << "New name: ";
	cin >> name;
	_file.open(name+string(".dat"), ios::app);
	if (!_file.is_open())
	  cerr << "Opening of file \"" << name << "\" failed" << endl;
	_file.close();
      }
      else if (choice == 's')
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
    else
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
