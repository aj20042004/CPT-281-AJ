#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>
#include "Movie_Management_System.h"
#include "Status.h"
#include "Date.h"
#include "Movie.h"

using namespace std;

int main() {

	// Creating a movie management system object
	Movie_Management_System movie_mange_system_obj;

	movie_mange_system_obj.load_from_file("Test 1.txt");

	int choice_number;
	bool loop_switch = true;

	while (loop_switch) {

		cout << "Welcome to the Movie Management System" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "1. Display Movies" << endl;
		cout << "2. Add Movies" << endl;  // Need to fix the order
		cout << "3. Edit release dates" << endl;
		cout << "4. Edit movie description" << endl;
		cout << "5. Start showing movies in the theater" << endl;  // Question - Do I need to print the details in the output screen or in the output file ?
		cout << "6. Number of movies before a date" << endl; // earlier than and equal to okay ?
		cout << "7. Save to file" << endl;
		cout << "8. Exit\n" << endl;

		cout << "Enter the choice number: ";
		cin >> choice_number;
	    cout << endl;

		if (choice_number == 1) {
			movie_mange_system_obj.display_movies();
			cout << endl;
		}

		else if (choice_number == 2) {
			
			string movie_name_str, release_date_str, description_str, receive_date_str, status_str;
			Date obj_release_date;
			Date obj_receive_date;
			Status status;
			
			cout << "Please enter a movie name to add: ";
			cin >> movie_name_str;  // Need to read the entire line
			cout << endl;

			cout << "Please enter a release date (format: MM/DD/YYYY - 01/09/2023) to add: ";
			cin >> release_date_str;
			cout << endl;

			cout << "Please enter a description to add: ";
			cin >> description_str;
			cout << endl;

			cout << "Please enter a receive date (format: MM/DD/YYYY - 01/09/2023) to add: ";
			cin >> receive_date_str;
			cout << endl;

			cout << "Please enter a status to add: ";
			cin >> status_str;
			cout << endl;

			if (status_str == "released") {
				status = RELEASED;
			}
			else {
				status = RECEIVED;
			}


			if (obj_release_date.parse_from_string(release_date_str)) {
				// Successfully parsed the release date
			}
			else {
				cout << "Error in parsing the release date" << endl;
				continue;
			}


			if (obj_receive_date.parse_from_string(receive_date_str)) {
				// "Successfully parsed the receive date"
			}
			else {
				cout << "Error in parsing the release date" << endl;
				continue;
			}

			Movie new_movie(movie_name_str, obj_release_date, description_str, obj_receive_date, status);
			movie_mange_system_obj.add_movie(new_movie);
			cout << endl;
		}


		else if (choice_number == 3) {
			
			string edit_movie_name, release_date_str;
			Date edit_new_release_date;

			cout << "Enter the movie name to edit: ";
			cin >> edit_movie_name;
			cout << endl;

			cout << "Enter the new release date (format: MM/DD/YYYY - 01/09/2023) to change: ";
			cin >> release_date_str;
			cout << endl;

			edit_new_release_date.parse_from_string(release_date_str);

			movie_mange_system_obj.edit_coming_movie_releaseDate(edit_movie_name,edit_new_release_date);

			cout << endl;
		}


		else if (choice_number == 4) {

			string edit_movie_name, edit_new_description;

			cout << "Enter the movie name to edit: ";
			cin >> edit_movie_name; // read the line
			cout << endl;

			cout << "Enter the new description to change: ";
			cin >> edit_new_description;
			cout << endl;

			movie_mange_system_obj.edit_coming_movie_description(edit_movie_name, edit_new_description);

			cout << endl;
		}

		else if (choice_number == 5) {

			string specified_release_date_str;
			Date specified_release_date;

			cout << "Enter the specified release date (format: MM/DD/YYYY - 01/09/2023) to display the movies: " << endl;
			cin >> specified_release_date_str;
		
			specified_release_date.parse_from_string(specified_release_date_str);

			movie_mange_system_obj.start_showing_movie(specified_release_date);

			cout << endl;
		}

		else if (choice_number == 6) {

			string specified_release_date_str_cnt;
			Date specified_release_date_cnt;
			
			cout << "Enter the specified release date (format: MM/DD/YYYY - 01/09/2023): " << endl;
			cin >> specified_release_date_str_cnt;
			cout << endl;

			specified_release_date_cnt.parse_from_string(specified_release_date_str_cnt);

			cout << "The Total number of movies: " << movie_mange_system_obj.count_coming_movies_before_date(specified_release_date_cnt);
			cout << endl;
			cout << endl;
		}

		else if (choice_number == 7) {
			movie_mange_system_obj.save_to_file("output.txt");
		}

		else if (choice_number == 8) {
			cout << endl;
			cout << "Thank you" << endl;
			loop_switch = false;
		}

	}
	
	// Questions: Date logic , time complexity, edit date / description - can I use movie name to search , valid date ? 

	system("pause");
	return 0;
}
