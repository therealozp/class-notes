#include <iostream>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_DOGS 100
#define RATE 35

class Dog{
    private:
      string name;
      string owner_full_name;
      int num_nights;
   
    public:
      Dog(){									//constructor
	num_nights = 0;
      }
      Dog(string new_name, string new_owner_name, int new_num_nights){            //constructor
	name = new_name;
	owner_full_name = new_owner_name;
	num_nights = new_num_nights;	
      }
      string get_name(){
		return name;
      }
      string get_owner_name(){
		return owner_full_name;
      }
      int get_num_nights(){
		return num_nights;
      }
    
};

int find_dog(int number, Dog list[], int nd);
void insert(Dog list[], int &nd);
void search(Dog list[], int nd);
void print(Dog list[], int nd);

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main() {
    char code;
    Dog dog_list[MAX_DOGS];
    string rest_line;
    int num_dogs = 0;

    for (;;) {
        cout << "Enter operation code: ";
        cin >> code;
        getline(cin, rest_line);


        switch (code) {
            case 'i':
                insert(dog_list, num_dogs);
                break;
            case 's':
                search(dog_list, num_dogs);
                break;
            case 'p':
                print(dog_list, num_dogs);
                break;
            case 'q':
                return 0;
            case 'c':
                cost(dog_list, num_dogs);
            default:
                cout << "Illegal code" << std::endl;
        }

        std::cout << std::endl;
     
    }
   
    return 0;
}

/**********************************************************
 * find_dog: Looks up a dog in the  array            .    *
 *            Returns the array index if the dog          *
 *            is found; otherwise, returns -1.            *
 **********************************************************/

int find_dog(string dog_name, string owner_name, Dog list[], int nd) {
    for (int i = 0; i < nd; i++) {
        if (list[i].get_name() == dog_name && list[i].get_owner_name() == owner_name) {
            return i;
        }
    }
    return -1;
}

/**********************************************************
 * insert: Prompts the user for information about a new   *
 *         dog and then inserts the dog into the array    *
 *         Prints an error message and returns            *
 *         prematurely if the  array is full.             *
 *********************************************************/

void insert(Dog list[], int &nd) {
    string dog_name, owner_name;
    int nights;
    if (nd == MAX_DOGS) {
        cout << "Database is full; can't add more dogs." << std::endl;
        return;
    }

    cout << "Enter dog name: ";
    getline(cin, dog_name);
    cout << "Enter owner full name: ";
    getline(cin, owner_name);
    cout << "Enter number of nights for boarding: ";
    cin >> nights;
    list[nd] = Dog(dog_name, owner_name, nights);
    nd++;
}

/**********************************************************
 * search: Prompts the user to enter a dog's name, and    *
 *         owner name, then look up the dog in the array. *
 *         If the dog exists, prints the number of night; *
 *         if not, prints an error message.               *
 **********************************************************/
void search(Dog list[], int nd) {
    string dog_name, owner_name;
    cout << "Enter dog name: ";
    getline(cin, dog_name);
    cout << "Enter owner full name: ";
    getline(cin, owner_name);
    int i = find_dog(dog_name, owner_name, list, nd);
    if (i >= 0) {
        cout << "Dog found. Staying for "<<list[i].get_num_nights()<<" nights"<<endl;
    } else {
        cout << "Dog not found." << std::endl;
    }
}

/**********************************************************
 * print: Prints all dogs  in the array, showing name,    *
 *        owner name, and number of nights.               *
 **********************************************************/
void print(Dog list[], int nd)
{
  int i;

  cout<< setw(15)<<left<<"Dog Name"<<setw(25)<<"Owner Name"<<left<<setw(8)<< "#of nights"<<endl;
  for (i = 0; i < nd; i++)
    cout << setw(15)<<left<<list[i].get_name() <<setw(25)<<left<<list[i].get_owner_name()<<setw(8)<<left<< list[i].get_num_nights() <<endl;
}

void cost(Dog db[], int nd) {
    string dog_name, owner_name;
    cout << "What is your name? "; 
    cin >> owner_name;
    cout << "What is your dog's name? ";
    cin >> dog_name; 
    int index = find_dog(dog_name, owner_name, db, nd); 
    if (index == -1) {
        cout << "Dog not found." << endl;
        return; 
    }

    int cost = db[index].get_num_nights() * RATE; 
    cout << dog_name << " has stayed with " << owner_name << " for " << db[index].get_num_nights() << " nights. Charges to pay: " << cost << endl;
    return; 
}