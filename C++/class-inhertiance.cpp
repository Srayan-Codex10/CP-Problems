#include <iostream>
#include <vector>

using namespace std;

class Person
{
protected:
    string first_name;
    string last_name;
    int id;

public:
    Person(string fname, string lname, int id)
    {
        first_name = fname;
        last_name = lname;
        id = id;
    }

    void display()
    {
        cout << "Name: " << last_name << ", " << first_name << "\nID: " << id << endl;
    }
};

class Student : public Person
{
private:
    vector<int> testScores;

public:
    Student(string fname, string lname, int id, vector<int> score) : Person(fname, lname, id)
    {
        testScores = score;
    }

    char calculate()
    {
        float sum = 0;
        for (const int &s : testScores)
        {
            sum += s;
        }
        float avg = sum / testScores.size();

        if (avg >= 90)
        {
            return 'O';
        }
        else if (avg >= 80)
        {
            return 'E';
        }
        else if (avg >= 70)
        {
            return 'A';
        }
        else if (avg >= 55)
        {
            return 'P';
        }
        else if (avg >= 40)
        {
            return 'D';
        }
        else
        {
            return 'T';
        }
    }
};

int main()
{
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for (int i = 0; i < numScores; i++)
    {
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student *s = new Student(firstName, lastName, id, scores);
    s->display();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}