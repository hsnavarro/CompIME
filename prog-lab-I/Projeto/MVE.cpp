#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

// Used for debugging
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

// The 'first' and 'second' statements have plenty use in this program, so the 'st' and 'nd' macros are used to abbreviate it
#define st first
#define nd second

struct aluno{
    int code;
    // The variable cpf is taken as a string to make possible to the user write input using the XXX.XXX.XXX-XX model
    string cpf, name;
    // These operators are necessary to compare elements from the struct, making possible to use a set with them
    bool operator < (const aluno &b) const { return code < b.code;}
    bool operator == (const aluno &b) const{
        return code == b.code and cpf == b.cpf and name == b.name;
    }
};

struct disciplina{
    int code, credit;
    string name, professor;
    // These operators are necessary to compare elements from the struct, making possible to use a set with them
    bool operator < (const disciplina &b) const { return code < b.code;}
    bool operator == (const disciplina &b) const {
        return code == b.code and credit == b.credit and name == b.name and professor == b.professor;
    }
};

set<aluno> students;
set<disciplina> disciplines;
map<int, aluno> student_id;
map<int, disciplina> discipline_id;
map<pair<disciplina, double>, set<aluno>> discipline_to_student;
map<pair<aluno, double>, set<disciplina>> student_to_discipline;

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);

    char c;
    cout << "Do you want to recover any information? (Y/N)" << endl;
    cin >> c;
    if(c == 'Y') {
        ifstream file1("register.txt");
        if(!file1.is_open()) cout << "Error opening file!" << endl;
        else {
            file1.seekg(0, file1.end);
            int len = file1.tellg();
            // Checking if the file is empty
            if (len == 0) cout << "The register is empty!" << endl;
            else {
                file1.seekg(0, file1.beg);
                int sz, key, a, b;
                double f;
                string c, d;
                // Copying set<aluno> students from register
                file1 >> sz;
                while (sz--) {
                    file1 >> a >> c >> d;
                    aluno x = {a, c, d};
                    students.insert(x);
                }
                // Copying set<disciplina> disciplines from register
                file1 >> sz;
                while (sz--) {
                    file1 >> a >> b >> c >> d;
                    disciplina x = {a, b, c, d};
                    disciplines.insert(x);
                }
                // Copying map<int, aluno> student_id from register
                file1 >> sz;
                while (sz--) {
                    file1 >> key >> a >> c >> d;
                    aluno x = {a, c, d};
                    student_id[key] = x;
                }
                // Copying map<int, disciplina> discipline_id from register
                file1 >> sz;
                while (sz--) {
                    file1 >> key >> a >> b >> c >> d;
                    disciplina x = {a, b, c, d};
                    discipline_id[key] = x;
                }
                // Copying map<pair<disciplina, double>, set<aluno>> discipline_to_student from register
                file1 >> sz;
                while (sz--) {
                    file1 >> a >> b >> c >> d >> f;
                    disciplina x = {a, b, c, d};
                    pair<disciplina, double> key = {x, f};
                    int sz2, aa;
                    string cc, dd;
                    file1 >> sz2;
                    while (sz2--) {
                        file1 >> aa >> cc >> dd;
                        aluno y = {aa, cc, dd};
                        discipline_to_student[key].insert(y);
                    }
                }
                // Copying map<pair<aluno, double>, set<disciplina>> student_to_discipline from register
                file1 >> sz;
                while (sz--) {
                    file1 >> a >> c >> d >> f;
                    aluno x = {a, c, d};
                    pair<aluno, double> key = {x, f};
                    int sz2, aa, bb;
                    string cc, dd;
                    file1 >> sz2;
                    while (sz2--) {
                        file1 >> aa >> bb >> cc >> dd;
                        disciplina y = {aa, bb, cc, dd};
                        student_to_discipline[key].insert(y);
                    }
                }
            }
            file1.close();
        }
    }
    while(1) {
        // Welcome Menu
        cout << "\nWelcome to the registration system, what do you want to do:" << endl;
        cout << "1. Insert Operation" << endl;
        cout << "2. Remove Operation" << endl;
        cout << "3. Query Operation" << endl;
        cout << "4. Terminate program" << endl;
        char esc;
        cin >> esc;
        if(esc != '1' and esc != '2' and esc != '3' and esc != '4'){
          cout << "Option not recognized!" << endl;
          continue;
        }
        if (esc == '1') {
            // Insert Menu
            cout << "You're in the insert menu, choose one of the options below:" << endl;
            cout << "1. Insert a student" << endl;
            cout << "2. Insert a discipline" << endl;
            cout << "3. Insert a discipline-student relation" << endl;
            cout << "4. Back to main menu" << endl;
            char esc2;
            cin >> esc2;    
          if(esc2 != '1' and esc2 != '2' and esc2 != '3' and esc2 != '4'){
            cout << "Option not recognized!" << endl;
            continue;
          }
            if (esc2 == '1') {
                int a;
                string b, s;
                cout << "Provide the following informations: code, social security number and name (model for multiple names: name1-name2)" << endl;
                cin >> a >> b >> s;
                aluno x = {a, b, s};
                if(students.count(x)) cout << "This student is already registered!" << endl;
                students.insert(x);
                student_id[a] = x;
            }
            if (esc2 == '2') {
                int a, b;
                string s1, s2;
                cout << "Provide the following informations: code, credit, name of the discipline and name of the professor (model for multiple names: name1-name2)" << endl;
                cin >> a >> b >> s1 >> s2;
                disciplina x = {a, b, s1, s2};
                if(disciplines.count(x)) cout << "This discipline is already registered!" << endl;
                disciplines.insert(x);
                discipline_id[a] = x;
            }
            if (esc2 == '3') {
                int a, b;
                double p;
                cout << "Provide the following informations: code of the discipline, code of the student and the period" << endl;
                cin >> a >> b >> p;
                disciplina x1 = discipline_id[a];
                aluno x2 = student_id[b];
                // Setting the student-to-discipline relationship
                if(student_to_discipline[{x2, p}].count(x1)) cout << "This discipline-student relation is already registered!" << endl;
                student_to_discipline[{x2, p}].insert(x1);
                // Setting the discipline-to-student relationship
                discipline_to_student[{x1, p}].insert(x2);
            }
            if (esc2 == '4') continue;
        }
        if (esc == '2') {
            // Remove menu
            cout << "You're in the remove menu, choose one of the options below:" << endl;
            cout << "1. Remove a student" << endl;
            cout << "2. Remove a discipline" << endl;
            cout << "3. Remove a discipline-student relation" << endl;
            cout << "4. Back to main menu" << endl;
            char esc2;
            cin >> esc2;
            if(esc2 != '1' and esc2 != '2' and esc2 != '3' and esc2 != '4'){
              cout << "Option not recognized!" << endl;
              continue;
            }
            if (esc2 == '1') {
                int a;
                cout << "Provide the following information: code of the student" << endl;
                cin >> a;
                aluno x = student_id[a];
                if(!students.count(x)) cout << "This student isn't registered!" << endl;
                student_id.erase(a);
                students.erase(x);

                // It's necessary to use auxiliar structures to erase elements from student_to_discipline and discipline_to_student maps
                map<pair<disciplina, double>, set<aluno>> aux1;
                map<pair<aluno, double>, set<disciplina>> aux2;

                aux1 = discipline_to_student;
                aux2 = student_to_discipline;
                for (auto key : discipline_to_student) aux1[key.st].erase(x);
                for(auto key : student_to_discipline) if(key.st.st == x) aux2.erase(key.st);
                discipline_to_student = aux1;
                student_to_discipline = aux2;
                // Clearing the auxiliar structures after using them
                aux1.clear(), aux2.clear();
            }

            if (esc2 == '2') {
                int a;
                cout << "Provide the following information: code of the discipline" << endl;
                cin >> a;
                disciplina x = discipline_id[a];
                if(!disciplines.count(x)) cout << "This discipline isn't registered!" << endl;
                discipline_id.erase(a);
                disciplines.erase(x);

                map<pair<disciplina, double>, set<aluno>> aux1;
                map<pair<aluno, double>, set<disciplina>> aux2;

                aux1 = discipline_to_student;
                aux2 = student_to_discipline;
                for(auto key : student_to_discipline) aux2[key.st].erase(x);
                for(auto key : discipline_to_student) if(key.st.st == x) aux1.erase(key.st);
                discipline_to_student = aux1;
                student_to_discipline = aux2;
                aux1.clear(), aux2.clear();
            }

            if (esc2 == '3') {
                int a, b;
                double p;
                cout << "Provide the following informations: code of the discipline, code of the student and the period" << endl;
                cin >> a >> b >> p;
                disciplina x1 = discipline_id[a];
                if(!disciplines.count(x1)) cout << "This discipline isn't registered!" << endl;
                aluno x2 = student_id[b];
                if(!students.count(x2)) cout << "This student isn't registered!" << endl;
                // Erasing the student-to-discipline and discipline-to-student relationships
                if(!student_to_discipline[{x2, p}].count(x1)) cout << "This student-discipline relation isn't registered!" << endl;
                student_to_discipline[{x2, p}].erase(x1);
                discipline_to_student[{x1, p}].erase(x2);
            }
            if (esc2 == '4') continue;
        }

        if (esc == '3') {
            // Query Menu
            cout << "You're in the query menu, choose one of the options below:" << endl;
            cout << "1. Query a student" << endl;
            cout << "2. Query a discipline" << endl;
            cout << "3. Back to main menu" << endl;

            char esc2;
            cin >> esc2;
            if(esc2 != '1' and esc2 != '2' and esc2 != '3'){
              cout << "Option not recognized!" << endl;
              continue;
            }
            if (esc2 == '1') {
                int a;
                double p;
                cout << "Provide the following informations: code of the student and the period" << endl;
                cin >> a >> p;
                aluno x1 = student_id[a];
                cout << "The student is registered in the following disciplines:" << endl;
                pair<aluno, double> key = {x1, p};
                for (auto x : student_to_discipline[key]) cout << x.code << " " << x.name << " ";
                cout << endl;
            }
            if (esc2 == '2') {
                int a;
                double p;
                cout << "Provide the following informations: code of the discipline and the period" << endl;
                cin >> a >> p;
                disciplina x1 = discipline_id[a];
                cout << "The discipline have the following students registered on it:" << endl;
                pair<disciplina, double> key = {x1, p};
                for (auto x : discipline_to_student[key]) cout << x.code << " " << x.name << " ";
                cout << endl;
            }
            if (esc2 == '3') continue;
        }
        if (esc == '4') {
            char a;
            cout << "Do you want to safe the info? (Y/N)" << endl;
            cin >> a;
            if(a == 'Y') {
                cout << "Saving the info . . ." << endl;
                ofstream file2("register.txt");
                if (!file2.is_open()) cout << "Error opening file!" << endl;
                else {
                    // Writing all the info from the structures defined before main in a manner that is easy to recover afterwards
                    file2 << students.size() << endl;
                    for (auto p : students) file2 << p.code << " " << p.cpf << " " << p.name << endl;
                    file2 << disciplines.size() << endl;
                    for (auto p : disciplines)
                        file2 << p.code << " " << p.credit << " " << p.name << " " << p.professor << endl;
                    file2 << student_id.size() << endl;
                    for (auto p : student_id) {
                        int key = p.st;
                        aluno x = p.nd;
                        file2 << key << " " << x.code << " " << x.cpf << " " << x.name << endl;
                    }
                    file2 << discipline_id.size() << endl;
                    for (auto p : discipline_id) {
                        int key = p.st;
                        disciplina x = p.nd;
                        file2 << key << " " << x.code << " " << x.credit << " " << x.name << " " << x.professor << endl;
                    }
                    file2 << discipline_to_student.size() << endl;
                    for (auto p : discipline_to_student) {
                        disciplina x = p.st.st;
                        double per = p.st.nd;
                        set <aluno> aux = p.nd;
                        file2 << x.code << " " << x.credit << " " << x.name << " " << x.professor << " " << per << endl;
                        file2 << aux.size() << endl;
                        for (auto y : aux) file2 << y.code << " " << y.cpf << " " << y.name << endl;
                    }
                    file2 << student_to_discipline.size() << endl;
                    for (auto p : student_to_discipline) {
                        aluno x = p.st.st;
                        double per = p.st.nd;
                        set <disciplina> aux = p.nd;
                        file2 << x.code << " " << x.cpf << " " << x.name << " " << per << endl;
                        file2 << aux.size() << endl;
                        for (auto y : aux)
                            file2 << y.code << " " << y.credit << " " << y.name << " " << y.professor << endl;
                    }
                    file2.close();
                }
            }
            return 0;
        }
    }
    return 0;
}
