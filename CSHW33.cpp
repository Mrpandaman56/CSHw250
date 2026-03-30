#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Player {
    string firstName;
    string lastName;
    int heightCM;
    string hometown;
};

class HashTable {
private:
    static const int SIZE = 10;
    vector<list<Player>> table;

    int hashFunction(string lastName) {
        int sum = 0;
        for (char c : lastName) {
            sum += c;
        }
        return sum % SIZE;
    }

public:
    HashTable() {
        table.resize(SIZE);
    }

    void insert(Player p) {
        int index = hashFunction(p.lastName);
        table[index].push_back(p);
    }

    Player* search(string lastName) {
        int index = hashFunction(lastName);
        for (auto &player : table[index]) {
            if (player.lastName == lastName) {
                return &player;
            }
        }
        return nullptr;
    }

    vector<Player> getAllPlayers() {
        vector<Player> all;
        for (auto &bucket : table) {
            for (auto &player : bucket) {
                all.push_back(player);
            }
        }
        return all;
    }
};

int feetInchesToCM(int feet, int inches) {
    return (feet * 30.48) + (inches * 2.54);
}

int main() {
    HashTable team;

    team.insert({"Mar", "Caneves Bufi", feetInchesToCM(5,5), "Mallorca, Spain"});
    team.insert({"Kateryna", "Kryuchkova", feetInchesToCM(6,1), "Kyiv, Ukraine"});
    team.insert({"Monica", "Martinez Blucher", feetInchesToCM(5,7), "White Plains, NY"});
    team.insert({"Chanelle", "Russell", feetInchesToCM(5,7), "Kingston, Jamaica"});
    team.insert({"Shreethika", "Vangala", feetInchesToCM(5,11), "Hyderabad, India"});
    team.insert({"Sun", "Zhuoxuan", feetInchesToCM(5,5), "Beijing, China"});

    int choice;
    do {
        cout << "\n1. Search by Last Name\n";
        cout << "2. List Players by Height\n";
        cout << "3. Average Height\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string last;
            cout << "Enter last name: ";
            cin.ignore();
            getline(cin, last);

            Player* result = team.search(last);
            if (result) {
                cout << result->firstName << " " << result->lastName << "\n";
                cout << "Height: " << result->heightCM << " cm\n";
                cout << "Hometown: " << result->hometown << "\n";
            } else {
                cout << "Player not found\n";
            }
        }

        else if (choice == 2) {
            vector<Player> players = team.getAllPlayers();

            sort(players.begin(), players.end(), [](Player a, Player b) {
                return a.heightCM < b.heightCM;
            });

            for (auto &p : players) {
                cout << p.firstName << " " << p.lastName
                     << " - " << p.heightCM << " cm\n";
            }
        }

        else if (choice == 3) {
            vector<Player> players = team.getAllPlayers();
            double sum = 0;

            for (auto &p : players) {
                sum += p.heightCM;
            }

            cout << "Average Height: " << sum / players.size() << " cm\n";
        }

    } while (choice != 4);

    return 0;
}
