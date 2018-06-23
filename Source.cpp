#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
struct employee //declaration struct
{
	string name;    //members variables of struct
	long social_number;
	string job;
	double payment;
	int age;
};
void list(employee array[], int size) // list function
{
	cout << setw(26) << setiosflags(ios::left) << "Name";             //show word (Name) 
	cout << setw(17) << setiosflags(ios::left) << "Social number";    //show word (Social number) 
	cout << setw(19) << setiosflags(ios::left) << "Job";              //show word (Job)
	cout << setw(13) << setiosflags(ios::left) << "Payment($)";       //show word (Payment($))
	cout << setw(5) << setiosflags(ios::left) << "Age" << endl;       // show word (Age) 
	for (int i = 0; i < size; i++)                                    // for loop to show list of employees 
	{
		cout << setw(26) << setiosflags(ios::left) << array[i].name;            // show the name of employee
		cout << setw(17) << setiosflags(ios::left) << array[i].social_number;   // show the social number of employee
		cout << setw(19) << setiosflags(ios::left) << array[i].job;             // show the job of employee
		cout << setw(13) << setiosflags(ios::left) << array[i].payment;         // show the payment of employee
		cout << setw(5) << setiosflags(ios::left) << array[i].age << endl;      // show the age of employee
	}
}
void add(employee array[], int& size)     //add function
{
	int number;           //declaration number of employee you want to add
	int m = 1;            //declaration counter
	cout << "enter the number of employee :  ";
	cin >> number;     //read the number of employee you want to add
	size += number;    //increase size
	for (int i = size - number; i < size; i++)   //loop to enter the data of employee
	{
		cout << endl;
		cout << " name" << m << "   :  ";
		cin.ignore();
		getline(cin, array[i].name);       //enter the name
		cout << endl;
		cout << "social number" << m << "   :  ";
		cin >> array[i].social_number;      //enter the social number
		cout << endl;
		cout << " job" << m << "   :  ";
		cin.ignore();
		getline(cin, array[i].job);        //enter the job
		cout << endl;
		cout << " payment" << m << "   :  ";
		cin >> array[i].payment;          //enter the payment
		cout << endl;
		cout << " age" << m << "   :  ";
		cin >> array[i].age;              //enter the age
		cout << endl;
		m++;

	}
	cout << endl;
	cout << "  it has just been added  " << m - 1 << "  employment successfully" << endl;
	cout << endl;
	cout << endl;
	char another;          //declaration to continue or not
	cout << "you want to add another employment y or n :  ";
	cin >> another;         //read variable to continue or not
	if (another == 'y' || another == 'Y')    //continue
		add(array, size);           //call function
	else                                     //not continue
	{
		cout << "you are leaving the add function bye bye." << endl;
	}
}
void delete_employee(employee array[], int &size) //delete function
{
	int social_number; // declaration social_number
	char other;        //declaration variable for another delete
	cout << "Enter Social Number" << endl;
	cin >> social_number;  //read the social_number
	for (int i = 0; i <= size; i++) {
		if (i == size) {                  //for wrong social_number
			cout << "\t\t\t Wrong social_number" << endl;
			break;                       //leave the loop
		}
		if (social_number == array[i].social_number)
		{                                           //shift the data
			for (int j = i; j < size - 1; j++) {
				array[j].name = array[j + 1].name;
				array[j].job = array[j + 1].job;
				array[j].age = array[j + 1].age;
				array[j].social_number = array[j + 1].social_number;
				array[j].payment = array[j + 1].payment;
			}
			size--; //decreasing the size of array 
			cout << endl;
			cout << "\t\t\t the emplyee was removed" << endl;
			break;          //leave loop
		}
		else {
			continue;
		}
	}
	cout << "are you want to do delete another employee y or any alphabet to end delete" << endl; //ask for delete another employee
	cin >> other;      //read variable to continue or not
	if (other == 'y' || other == 'Y')      //continue
		delete_employee(array, size);  //delete another employee
	else         //not continue
	{
		cout << "\t\t thank you for using our program" << endl;
	}

}
void search(employee array[], int size) { //search function 
	int choice;      //declaration the method of the research
	long id;         //declaration id 
	string name;     //declaration name
	char other;      //declaration for another search
	cout << "Enter 1 to search with id or 2 to search with employee name" << endl;    //choice the method of the research
x: cin >> choice;                //read the method of the research
	if (choice == 1) {            // search with ID
		cout << "Enter The ID " << endl;     //ask the ID
		cin >> id;                           //read the ID
		for (int i = 0; i <= size; i++) {
			if (i == size) {                  //for wrong ID
				cout << "Wrong Id" << endl << "Please, Enter Right ID";
				cin >> id;                           //read the ID again
				i = -1;                               //for wrong ID , search again
			}
			if (id == array[i].social_number) {
				cout << array[i].name << "\t"         //show the data of the employee
					<< array[i].social_number << "\t"
					<< array[i].job << "\t"
					<< array[i].payment << "\t"
					<< array[i].age << endl;
				break;                             //leave the loop
			}
		}
	}
	else if (choice == 2) {  //search with name
		cout << "Enter the employee name" << endl;    //ask the name
		cin.ignore();
		getline(cin, name);                    //read the name
		for (int i = 0; i < size; i++) {
			if (i == size) {                    //for wrong name
				cout << "Wrong name" << endl << "Please, Enter Right Name";
				cin.ignore();
				getline(cin, name);                    //read the name again
				i = -1;                               //for wrong Name , search again
			}
			if (name == array[i].name) {
				cout << array[i].name << "\t"         //show the data of the employee
					<< array[i].social_number << "\t"
					<< array[i].job << "\t"
					<< array[i].payment << "\t"
					<< array[i].age << endl;
				break;                                  //leave the loop
			}
		}
	}
	else
	{
		cout << "Wrong number , Please,Enter 1 or 2" << endl;
		goto x;                                  //Choose and search again
	}
	cout << "Press y to continue" << endl << "Press any alphabet to exit";  //ask for another saerch
	cin >> other;
	if (other == 'y' || other == 'Y') {         //do another research
		search(array, size);            //call function
	}
	else
	{
		cout << "The End of search" << endl;
	}
}
void modify(employee array[], int size)//modify function
{
	char ch;                           //declaration to continue or not 
	int i;                             //declaration index of the array
	long id;                            //declaration id
	cout << "Enter The ID " << endl;     //ask the ID
	cin >> id;                           //read the ID
	for (i = 0; i <= size; i++) {
		if (i == size) {                  //for wrong ID
			cout << "Wrong Id" << endl << "Please, Enter Right ID";
			cin >> id;                           //read the ID again
			i = -1;                               //for wrong ID , search again
		}
		if (id == array[i].social_number) {
			cout << array[i].name << "\t"         //show the data of the employee
				<< array[i].social_number << "\t"
				<< array[i].job << "\t"
				<< array[i].payment << "\t"
				<< array[i].age << endl;
			break;                             //leave the loop
		}
	}
	int num;                               //declaration the variable of the switch
	do
	{
		cout << "Which do you want to modify?" << endl << endl << "A)Enter 1 to modify name" << endl << "B)Enter 2 to modify Id" << endl <<
			"C)Enter 3 to modify Job" << endl << "D)Enter 4 to modify Payment" << endl << "E)Enter 5 to modify Age" << endl << "Enter 0 to exit" << endl;
		cin >> num;                              //read the variable of the switch
		switch (num)                             //declaration switch
		{
		case 1: {
			cout << "Enter The name" << endl;
			cin.ignore();
			getline(cin, array[i].name);               //read the name of the employee
			break;
		}
		case 2: {
			cout << "Enter The ID" << endl;
			cin >> array[i].social_number;          //read the social number of the employee
			break;
		}
		case 3: {
			cout << "Enter The Job" << endl;
			cin.ignore();
			getline(cin, array[i].job);                      //read the job of the employee
			break;
		}
		case 4: {
			cout << "Enter The Payment" << endl;
			cin >> array[i].payment;                   //read the payment of the employee
			break;
		}
		case 5: {
			cout << "Enter The Age" << endl;
			cin >> array[i].age;                        //read the age of the employee
			break;
		}
		case 0: {
			cout << "\t\t\t\tTHE END\n" << endl;        //exit 
			break;
		}
		}
		cout << "Press y to continue modification for this employee" << endl << "Press any alphabet to end modification";
		cin >> ch;                      //read the alphabet to continue or not
	} while (ch == 'y' || ch == 'Y');       //continue
	cout << "\t\t\t\tThe employee data is modified" << endl << endl;
	cout << "Press y to modify other employee" << endl << "Press any alphabet to end modification";
	cin >> ch;                          //read the alphabet to continue or not
	if (ch == 'y' || ch == 'Y')
	{
		modify(array, size);             //continue
	}
	else
	{
		cout << "\t\t\t\tThe End of modification " << endl << endl;
	}
}
void payment(employee array[], int size) //payment function
{
	double index;
	long id;           //declaration id
	cout << "you want to calculate the payment for a certain employee" << endl;
	cout << "Enter The ID " << endl;     //ask the ID
	cin >> id;                           //read the ID
	for (int i = 0; i <= size; i++) {
		if (i == size) {                  //for wrong ID
			cout << "Wrong Id" << endl << "Please, Enter Right ID";
			cin >> id;                           //read the ID again
			i = -1;                               //for wrong ID , search again
		}
		if (id == array[i].social_number) {
			cout << array[i].name << "\t"         //show the data of the employee
				<< array[i].social_number << "\t"
				<< array[i].job << "\t"
				<< array[i].payment << "\t"
				<< array[i].age << endl;
			index = array[i].payment;
			break;                             //leave the loop
		}
	}
	double insurance, taxed;            //declaration insurance and taxed
	double total;                       //declaration total
	insurance = index * 2 / 100;        //discount the insurance
	taxed = index * 10 / 100;           //discount the taxed
	total = index - insurance - taxed;  //caculate the total of discount
	cout << "total salary = " << total << endl;
}
void average(employee array[], int size)    //average function
{
	double sum = 0;            //declaration sum with initial value
	for (int i = 0; i < size; i++)       //loop to cacugate tne average
	{
		sum += array[i].payment;       //calculate the average of employee payment
	}
	cout << "the average is  :  " << sum / size << endl;
}
void main()
{
	system("color 79");            //color of the system
	int size;                      //declaration dynamic array size
	ifstream myfile;                        // read from file stream
	myfile.open("data.txt");                // open file stream
	myfile >> size;                           // read size of array from file stream
	employee *array = new employee[100];     // allocation for dynamic array
	for (int i = 0; i<size; i++)               // for loop to read data of employees from file stream
	{
		myfile.ignore();                     // will consume the new line before taking the new input
		getline(myfile, array[i].name);     // read a whole line into name of employee from file stream 
		myfile >> array[i].social_number;    // read social number of employee from file stream
		myfile.ignore();                     // will consume the new line before taking the new input
		getline(myfile, array[i].job);        // read a whole line into job of employee from file stream
		myfile >> array[i].payment >> array[i].age;   // read payment and age of employee from file stream
	}
	myfile.close();                        // close file stream
	char ch;                         //declaration variable to continue or not
	cout << setw(52) << "Welcom to Company's program\n\n" << endl;
	int x;                         //declaration the variable of the switch
	do {
		cout << "Enter 1 to List all employees\n" << endl
			<< "Enter 2 to Add New Employee\n" << endl
			<< "Enter 3 to Delete an employee\n" << endl
			<< "Enter 4 to Modify employee information\n" << endl
			<< "Enter 5 to Calculate the payment for a certain employee\n" << endl
			<< "Enter 6 to Calculate the average payment for all employees\n" << endl
			<< "Enter 7 to Search for an employee\n" << endl
			<< "Enter 0 to exit\n" << endl;
		cin >> x;                             //read the variable of the switch
		switch (x)                            //declaration switch
		{
		case 1: {
			list(array, size);         //caling function
			break;
		}
		case 2: {
			add(array, size);            //calling function
			break;
		}
		case 3: {
			delete_employee(array, size);         //caling function
			break;
		}
		case 4: {
			modify(array, size);                //caling function
			break;
		}
		case 5: {
			payment(array, size);         //caling function
			break;
		}
		case 6: {
			average(array, size);              //caling function
			break;
		}
		case 7: {
			search(array, size);        //caling function
			break;
		}
		case 0: {
			cout << "\t\t\t\tTHE END\n" << endl;     //exit
			exit(0);
		}
		}
		cout << "Press y to continue" << endl << "Press any alphabet to end program";
		cin >> ch;            //read the alphabet to continue or not
	} while (ch == 'y' || ch == 'Y');       //continue
	cout << "\t\t\t\tThe End" << endl << endl;
	ofstream file;                 // write in file stream
	file.open("data.txt");         // open file stream
	file << size << endl;              // write the size of employee in file stream
	for (int i = 0; i<size; i++)      // for loop to write data of employees in file stream
	{
		file << array[i].name << endl           // write name of employee in file stream
			<< array[i].social_number << endl     // write social number of employee in file stream
			<< array[i].job << endl               // write job of employee in file stream
			<< array[i].payment << endl           // write payment of employee in file stream
			<< array[i].age << endl;              // write age of employee in file stream
	}
	file.close();                            // close file stream
	delete[] array;                          //deallocation
	system("pause");
}