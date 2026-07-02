#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Note
{
public:
    string title;
    string content;
    void addNote();
};

void Note :: addNote()
{
    cin.ignore();
    cout << "Enter the title of the note: ";
    getline(cin, title);
    cout << "Enter the data: ";
    getline(cin, content);
    ofstream file("notes.txt", ios::app);
    file << title << "|" << content << endl;
}

void searchNote()
{
    ifstream file("notes.txt");

    string searchTitle;

    cout << "Enter title: ";
    getline(cin, searchTitle);

    string line;
    bool found = false;

    while(getline(file, line))
    {
        stringstream ss(line);

        string title, content;

        getline(ss, title, '|');
        getline(ss, content);

        if(title == searchTitle)
        {
            cout << "\n========== NOTE FOUND ==========\n";
            cout << "Title   : " << title << endl;
            cout << "Content : " << content << endl;
            cout << "===============================\n";

            found = true;
        }
    }

    if(!found)
    {
        cout << "\nNo note found with title \"" << searchTitle << "\".\n";
    }

    file.close();
}


void viewNotes()
{
    ifstream file("notes.txt");

    string line;

    while(getline(file, line))
    {
        stringstream ss(line);

        string title, content;

        getline(ss, title, '|');
        getline(ss, content);

        cout << "=============================\n";
        cout << "Title   : " << title << endl;
        cout << "Content : " << content << endl;
        cout << "=============================\n\n";
    }

    file.close();
}

void menu_print()
{
    string menu =
        "=============================\n"
        "      CLI NOTES MANAGER\n"
        "=============================\n"
        "1. Add Note\n"
        "2. View Notes\n"
        "3. Search Note\n"
        "4. Delete Note\n"
        "5. Exit\n";
    cout << menu;
}

int main()
{
    while (true)
    {
        int choice;
        menu_print();
        cin >> choice;
        if (choice == 1)
        {
            Note n;
            n.addNote();
        }
        else if (choice == 2)
        {
            cout << "List of all existing notes: " << endl;
            viewNotes();
            cout << endl;
        }
        else if (choice == 3)
        {
            searchNote();

        }
        else if (choice == 4)
        {
            // Delete note
        }
        else if (choice == 5)
        {
            cout << "Thanks for using CLI Note Editor" << endl;
            break;
        }
        else
        {
            cout << "Please enter a valid choice" << endl;
        }
    }

    return 0;
}
