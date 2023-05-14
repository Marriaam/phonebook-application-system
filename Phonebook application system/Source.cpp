#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void add_contact() {
	ofstream contact;
	contact.open("contacts.txt", ios::app);
	string first_name;
	string last_name;
	string email;
	char gender;
	string phone_number;
	cout << "First name: ";
	cin >> first_name;
	cout << "Last name: ";
	cin >> last_name;
	cout << "Phone Number: ";
	cin >> phone_number;
	cout << "Gender (m/f): ";
	cin >> gender;
	cout << "Email: ";
	cin >> email;
	contact << first_name << ' ' << last_name << "\n" << phone_number << "\n" << gender << "\n" << email << endl << endl;
	contact.close();
	cout << endl << "Contact added successfully!!" << endl << endl;
}

void show_contacts() {
	string first_name;
	string last_name;
	string email;
	char gender;
	string phone_number;
	bool found = false;
	ifstream contact;
	contact.open("contacts.txt");
	while ((contact >> first_name >> last_name >> phone_number >> gender >> email) && !contact.eof()) {
		found = true;
		cout << "Name: " << first_name << ' ' << last_name << '\n' << "Phone Number: " << phone_number << '\n' << "Gender: " << gender << '\n' << "Email: " << email << endl << endl;
	}
	if (found == false) {
		cout << " NO CONTACTS TO SHOW " << endl << endl;
	}
}

void search_contact() {
	string first_name;
	string last_name;
	string email;
	string phone_number;
	string gender;
	bool found = false;
	ifstream contact;
	contact.open("contacts.txt");
	int SearchBy;
	string x, y;
	cout << "Enter the number of the search method chosen: " << endl << "1.Name" << endl << "2.Phone number" << endl << "3.Email" << endl << "4.Gender" << endl;
	cout << " Method : ";
	cin >> SearchBy;
	cout << "Search for : ";
	if (SearchBy == 1) {
		cin >> x >> y;
	}
	else {
		cin >> x;
	}
	while (contact >> first_name >> last_name >> phone_number >> gender >> email) {
		switch (SearchBy) {
		case 1:
			while ((first_name == x) && (last_name == y)) {
				cout << endl << "     *Name is found*" << '\n' << endl;
				cout << "Name: " << first_name << ' ' << last_name << endl << "Phone number: " << phone_number
					<< '\n' << "Email: " << email << '\n' << "Gender: " << gender << '\n' << endl;
				found = true;
				break;
			}
			break;
		case 2:
			while (phone_number == x) {
				cout << endl << "     *Phone number is found* " << '\n' << endl;
				cout << "Name: " << first_name << ' ' << last_name << '\n' << "Phone number: " << phone_number << '\n' << "email: " << email << '\n' << "gender: " << gender << '\n' << endl;
				found = true;
				break;
			}
			break;
		case 3:
			while (email == x) {
				cout << endl << "     *Email is found* " << '\n' << endl;
				cout << "Name: " << first_name << ' ' << last_name << '\n' << "Phone number: " << phone_number << '\n' << "email: " << email << '\n' << "gender: " << gender << '\n' << endl;
				found = true;
				break;
			}
			break;
		case 4:
			if (gender == x) {
				cout << endl << "     *Gender is found* " << '\n' << endl;
				cout << "Name: " << first_name << ' ' << last_name << '\n' << "Phone number: " << phone_number << '\n' << "email: " << email << '\n' << "gender: " << gender << '\n' << endl;
				found = true;
			}
			break;
		}
	}
	if (found == false) {
		cout << endl << "      Contact is not found!" << endl << endl;
	}
}
void update_contact() {
	ifstream contact;
	ofstream temp;
	contact.open("contacts.txt");
	temp.open("temp.txt");
	string first_name;
	string last_name;
	string email;
	char gender;
	string phone_number;
	bool found = false;
	string new_first_name;
	string new_last_name;
	string new_email;
	char new_gender;
	string new_phone_number;
	string contact_tobe_edited_firstname, contact_tobe_edited_lastname;
	cout << "Enter the contact you want to edit : ";
	cin >> contact_tobe_edited_firstname >> contact_tobe_edited_lastname;
	while ((contact >> first_name >> last_name >> phone_number >> gender >> email) && (!contact.eof())) {  //3shan lw el file msh f a5ro
		if ((first_name == contact_tobe_edited_firstname) && (last_name == contact_tobe_edited_lastname)) {
			found = true;
			cout << "Enter the update for the contact: " << '\n';
			cout << "Name: "; cin >> new_first_name >> new_last_name;
			cout << "Phone number: "; cin >> new_phone_number;
			cout << "Gender: "; cin >> new_gender;
			cout << "Email: "; cin >> new_email;
			temp << new_first_name << ' ' << new_last_name << "\n" << new_phone_number << "\n" << new_gender << "\n" << new_email << endl << endl;
		}
		else {
			temp << first_name << ' ' << last_name << "\n" << phone_number << "\n" << gender << "\n" << email << endl << endl;
		}
	}
	if (found == false) {
		cout << "Contact is not found" << endl << endl;
	}
	else {
		cout << "Contact updated successfully!!" << endl << endl;
	}
	temp.close();
	contact.close();
	remove("contacts.txt");
	rename("temp.txt", "contacts.txt");
}

void delete_contact() {
	ifstream contact;
	ofstream temp;
	contact.open("contacts.txt");
	temp.open("temp.txt");
	string first_name;
	string last_name;
	string email;
	char gender;
	string phone_number;
	bool found = false;
	string contact_tobe_deleted_firstname, contact_tobe_deleted_lastname;
	cout << "Enter the contact you want to delete : ";
	cin >> contact_tobe_deleted_firstname >> contact_tobe_deleted_lastname;
	while ((contact >> first_name >> last_name >> phone_number >> gender >> email) && (!contact.eof())) {
		if ((first_name == contact_tobe_deleted_firstname) && (last_name == contact_tobe_deleted_lastname)) {
			found = true;
			cout << endl << "     Contact deleted successfully!!" << endl << endl;
			continue;
		}
		else {
			temp << first_name << ' ' << last_name << "\n" << phone_number << "\n" << gender << "\n" << email << endl << endl;

		}
	}

	if (found == false) {
		cout << "Contact is not found" << endl << endl;
	}
	temp.close();
	contact.close();
	remove("contacts.txt");
	rename("temp.txt", "contacts.txt");
}

int main()
{
	int choice;
	do {
		cout << "*Phonebook menu*" << endl;
		cout << "1.Add new contacts" << '\n' << "2.Show saved contacts" << '\n' << "3.Search for contacts" << '\n' << "4.Edit contact information" << '\n' << "5.Delete contact" << '\n' << "6.Exit" << '\n';
		cout << "Enter the number of the operation: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			add_contact();
			break;
		case 2:
			show_contacts();
			break;
		case 3:
			search_contact();
			break;
		case 4:
			update_contact();
			break;
		case 5:
			delete_contact();
			break;
		}
	} while (choice != 6);
	return 0;
}

