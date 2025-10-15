#include <iostream>
#include <string>
using namespace std;

class Athlete {
private:
    int m_height;
    char m_gender;

public:
    Athlete() {
        m_height = 0;
        m_gender = 'U';
    }
    Athlete(int height, char gender) {
        m_height = height;
        m_gender = gender;
    }

    int getHeight() {
        return m_height;
    }
    void setHeight(int height) {
        m_height = height;
    }

    char getGender() {
        return m_gender;
    }
    void setGender(char gender) {
        m_gender = gender;
    }
};

class Tennis : public Athlete {
private:
    int m_serveSpeed;

public:
    Tennis() {
        m_serveSpeed = 0;
    }
    Tennis(int serveSpeed) {
        m_serveSpeed = serveSpeed;
    }
    int getServeSpeed() {
        return m_serveSpeed;
    }
    void setServeSpeed(int serveSpeed) {
        m_serveSpeed = serveSpeed;
    }
};

class Golf : public Athlete {
    string m_clubType;

public:
    Golf() {
        m_clubType = "";
    }
    Golf(string clubType) {
        m_clubType = clubType;
    }
    string getClubType() {
        return m_clubType;
    }
    void setClubType(string clubType) {
        m_clubType = clubType;
    }
};
int main()
{
    Athlete sport(72, 'M');
    cout << "Athlete: " << sport.getHeight() << " "
         << sport.getGender() << endl;

    Tennis martina = Tennis();
    martina.setServeSpeed(100);
    martina.setGender('F');
    Tennis bjorn(150);
    bjorn.setGender('M');
    if (martina.getGender() == 'F')
        cout << "Martina serve speed: " << martina.getServeSpeed() << endl;

    Golf woods = Golf();
    woods.setGender('M');
    woods.setClubType("Taylor Made");
    cout << "Woods uses " << woods.getClubType() << " clubs" << endl;

    Golf thitikul = Golf();
    thitikul.setGender('F');
    thitikul.setClubType("Callaway");
    if (thitikul.getGender() == 'F')
        cout << "Thitikul uses " << thitikul.getClubType() << " clubs" << endl;

    return 0;
}
