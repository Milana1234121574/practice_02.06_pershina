#include "DayProgram.h"

DayProgram::DayProgram() {}

DayProgram::~DayProgram() {}

void DayProgram::setDate(string date) {
	this->date = date;
}

string DayProgram::getDate() const& {
	return date;
}

void DayProgram::show() {
	vector<TVprogram*>::iterator it;
	for (it = programs.begin(); it != programs.end(); it++) {
		cout << (*it)->toString();
		cout << endl;
	}
}

void DayProgram::add() {
	int menu = -1;
	cout << "1 - Add educational program\n2 - Add movie\n3 - Add show\n4 - Add kids show" << endl;
	cin >> menu;
	switch (menu) {
		case 1: {
			string t1, t2;
			int h, m;
			cout << "Enter the branch of science: " << endl;
			cin >> ws;
			getline(cin, t1);
			cout << "Enter name:" << endl;
			cin >> ws;
			getline(cin, t2);
			cout << "Enter hours:" << endl;
			cin >> h;
			cout << "Enter minutes:" << endl;
			cin >> m;
			try {
				vector<TVprogram*>::iterator it;
				for (it = programs.begin(); it != programs.end(); it++) {
					if ((*it)->getTime() == Time_(h, m, 0)) {
						throw;
					}
				}
			}
			catch (string temp) {
				temp = "The show is already booked for this time";
				cout << temp << endl;
			}
			programs.push_back(new EducationalProgram(t1, t2, Time_(h, m, 0)));
			break;
		}
		case 2: {
			string t1, t2;
			int h, m, y;
			cout << "Enter description: " << endl;
			cin >> ws;
			getline(cin, t1);
			cout << "Enter name:" << endl;
			cin >> ws;
			getline(cin, t2);
			cout << "Enter hours:" << endl;
			cin >> h;
			cout << "Enter minutes:" << endl;
			cin >> m;
			cout << "Enter year:" << endl;
			cin >> y;
			try {
				vector<TVprogram*>::iterator it;
				for (it = programs.begin(); it != programs.end(); it++) {
					if ((*it)->getTime() == Time_(h, m, 0)) {
						throw;
					}
				}
			}
			catch (string temp) {
				temp = "The show is already booked for this time";
				cout << temp << endl;
			}
			programs.push_back(new Movie(t1, y, t2, Time_(h, m, 0)));
			break;
		}
		case 3: {
			string t1, t2;
			int h, m;
			cout << "Enter theme:" << endl;
			cin >> ws;
			getline(cin, t1);
			cout << "Enter name:" << endl;
			cin >> ws;
			getline(cin, t2);
			cout << "Enter hours:" << endl;
			cin >> h;
			cout << "Enter minutes:" << endl;
			cin >> m;
			try {
				vector<TVprogram*>::iterator it;
				for (it = programs.begin(); it != programs.end(); it++) {
					if ((*it)->getTime() == Time_(h, m, 0)) {
						throw;
					}
				}
			}
			catch (string temp) {
				temp = "The show is already booked for this time";
				cout << temp << endl;
			}
			programs.push_back(new Show(t1, t2, Time_(h, m, 0)));
			break;
		}
		case 4: {
			string t2;
			int h, m, mina, maxa;
			cout << "Enter min age:" << endl;
			cin >> mina;
			cout << "Enter max age:" << endl;
			cin >> maxa;
			cout << "Enter name:" << endl;
			cin >> ws;
			getline(cin, t2);
			cout << "Enter hours:" << endl;
			cin >> h;
			cout << "Enter minutes:" << endl;
			cin >> m;
			try {
				vector<TVprogram*>::iterator it;
				for (it = programs.begin(); it != programs.end(); it++) {
					if ((*it)->getTime() == Time_(h, m, 0)) {
						throw;
					}
				}
			}
			catch (string temp) {
				temp = "The show is already booked for this time";
				cout << temp << endl;
			}
			programs.push_back(new KidsShow(mina, maxa, t2, Time_(h, m, 0)));
			break;
		}
	}
}

void DayProgram::findby() {
	int menu = -1;
	cout << "1 - find by type of program\n2 - find by name of program\n3 - find by time of program" << endl;
	cin >> menu;
	switch (menu) {
		case 1: {
			vector<TVprogram*>::iterator it;
			string type;
			cout << "Enter type to find:" << endl;
			cin >> ws;
			getline(cin, type);
			for (it = programs.begin(); it != programs.end(); it++) {
				if ((*it)->type() == type) {
					cout << (*it)->toString();
				}
			}
			break;
		}
		case 2: {
			vector<TVprogram*>::iterator it;
			string name;
			cout << "Enter name to find:" << endl;
			cin >> ws;
			getline(cin, name);
			for (it = programs.begin(); it != programs.end(); it++) {
				if ((*it)->getname() == name) {
					cout << (*it)->toString();
				}
			}
			break;
		}
		case 3: {
			vector<TVprogram*>::iterator it;
			int h, m;
			cout << "Enter hours: " << endl;
			cin >> h;
			cout << "Enter minutes: " << endl;
			cin >> m;
			for (it = programs.begin(); it != programs.end(); it++) {
				if ((*it)->getTime() == Time_(h, m, 0)) {
					cout << (*it)->toString();
				}
			}
			break;
		}
	}
}

void DayProgram::mysort() {
	sort(programs.begin(), programs.end(), compare);
}

bool compare(const TVprogram* lhs, const TVprogram* rhs) {
	return lhs->getTime() < rhs->getTime();
}

void DayProgram::save(ofstream& file) {
	if (file.is_open()) {
		vector<TVprogram*>::iterator it;
		bool temp = false;
		for (it = programs.begin(); it != programs.end(); it++) {
			cout << (*it)->toString() << endl;
			cout << "This ?" << endl;
			cin >> temp;
			if (temp) {
				file << (*it)->type() << endl;
				file << (*it)->getTime() << endl;
				file << (*it)->getname() << endl;
				break;
			}
		}
	}
}

void DayProgram::load(ifstream& file) {
	string name, temp;
	int h, m;
	getline(file, name);
	file >> h;
	file >> temp;
	file >> m;
}