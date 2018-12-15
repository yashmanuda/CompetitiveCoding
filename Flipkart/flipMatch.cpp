#include <bits/stdc++.h>
using namespace std;

struct Person{
    pair<int,int> Location;
    string Name;
    vector<string> Hobbies;
    int score;
};

struct Database{
    vector<string> allHobies;
    vector<int> Popularity;
    vector<Person> ListOfPeople;
};

float getDistanceBetween(Person a, Person b){
    float dist = sqrt( (a.Location.first - b.Location.first)*(a.Location.first - b.Location.first) + (a.Location.second-b.Location.first)*(a.Location.second-b.Location.first)  );
    return dist;
}

Person getPerson(string name, pair<int, int> location, vector<string> hobbies ){
    Person person;
    person.Location = location;
    person.Name = name;
    person.Hobbies = hobbies;
    return person;

}

Database getDatabase(vector<Person> listOfPeople){
    Database database;
    database.ListOfPeople = listOfPeople;
    return database;
}


Person getPersonByName(Database database, string name){
    Person temp;
    for(vector<Person>::iterator it = database.ListOfPeople.begin(); it != database.ListOfPeople.end(); ++it){
        temp = *it;
        if(temp.Name == name){
            return temp;
        }
    }
    return temp;
}


vector<string> getPeopleWithinDistance(Database database, string name, float distance){
    vector<string> listOfPeopleWithinDistance;
    Person givenPerson = getPersonByName(database,name);

    for(vector<Person>::iterator it = database.ListOfPeople.begin(); it != database.ListOfPeople.end(); ++it ){
        if((*it).Name != givenPerson.Name && getDistanceBetween(*it,givenPerson) < distance){
            listOfPeopleWithinDistance.push_back((*it).Name);
        }
    }

    return listOfPeopleWithinDistance;
}

int getNumCommonHobbies(Person a, Person b){
    unordered_map<string, int> listOfHobbies;
    int count = 0;
    for(vector<string> :: iterator it = a.Hobbies.begin(); it != a.Hobbies.end(); ++it){
        listOfHobbies[(*it)]++;
    }
    for(vector<string> :: iterator it = b.Hobbies.begin(); it != b.Hobbies.end(); ++it){
        listOfHobbies[(*it)]++;
    }

    for(auto i : listOfHobbies){
        if(i.second >= 2){
            count++;
        }
    }
    return count;
}

void setPopularity(Database database){
    return;
}

// atleast x common hobbies, within distance
vector<string> getPeopleDistanceNumHobbies(Database database, string name, float distance, int numHobbies){
    // sort on the basis of number of common hobbies
    vector<string> namesOfPeople;
    Person givenPerson = getPersonByName(database,name);

    for(vector<Person>::iterator it = database.ListOfPeople.begin(); it != database.ListOfPeople.end(); ++it){
        if(((*it).Name != givenPerson.Name) && (getNumCommonHobbies(givenPerson,(*it)) >= numHobbies) && (getDistanceBetween(*it,givenPerson) < distance  ) ){
            namesOfPeople.push_back((*it).Name);
        }
    }
    return namesOfPeople;
}

vector<string> getPeopleDistanceSortedHobbies(Database database, string name, float distance, int numHobbies){
    vector<string> namesOfPeople;
    Person givenPerson = getPersonByName(database,name);
    multimap<int,string> mapOfPeople;

    int tempCommonHobbies = 0;

    for(vector<Person>::iterator it = database.ListOfPeople.begin(); it != database.ListOfPeople.end(); ++it ){
        if( (*it).Name != givenPerson.Name && getDistanceBetween(*it,givenPerson) < distance  && (getNumCommonHobbies(givenPerson,(*it) ) >=  numHobbies)){
            mapOfPeople.insert( pair<int,string>( getNumCommonHobbies(givenPerson,(*it) ),(*it).Name));
        }
    }

    for(map<int,string>::reverse_iterator it = mapOfPeople.rbegin();  it != mapOfPeople.rend() ; ++it){
        if((*it).first > 0){
            namesOfPeople.push_back((*it).second);
        }
    }
    return namesOfPeople;

}

int main(){
    int numPeople = 7;
    string people[] = {"PersonA","PersonB", "PersonC", "PersonD","PersonE","PersonF","PersonG"};
    vector<pair<int,int>> allLocations {{0,0},{3,4},{5,4},{6,3},{7,4},{9,13},{0,0}};
    vector<vector<string>> allHobbies { {"Running","Biking","Trekking","Reading"},{"Sketching","Music","Painting"},{"Running","Trekking","Biking"},{"Sketching","Biking"},{"Running","Reading","Trekking"},{"Running","Trekking","Traveling"},{"Painting"}};
    vector<Person> listOfPeopleInDatabase;

    for(int i = 0; i < numPeople; i++){
        Person temp = getPerson(people[i],allLocations.at(i),allHobbies.at(i));
        listOfPeopleInDatabase.push_back(temp);
    }
    Database database = getDatabase(listOfPeopleInDatabase);

    string name = "PersonA";
    float dis = 15.0;
    int numH = 2;

    vector<string> part1 = getPeopleWithinDistance(database,name,dis);
    for(auto it = part1.begin(); it != part1.end(); ++it){
        cout << *it << " ";
    }

    cout << endl << endl;

    vector<string> part2 = getPeopleDistanceNumHobbies(database,name,dis,numH);
    for(auto it = part2.begin(); it != part2.end(); ++it){
        cout << *it <<" ";
    }

    cout << endl << endl;

    vector<string> part3 = getPeopleDistanceSortedHobbies(database,name,dis, numH);
    for(auto it = part3.begin(); it != part3.end(); ++it){
        cout <<*it <<" ";
    }

    return 0;
}
