#include<iostream>
using namespace std;

class Worker{
    protected:
    int workerID;
    string workerName;
    int basePay;

    public:
    virtual void showDetails() = 0;
    virtual int computePay() = 0;
    friend int operator+(Worker & w1, Worker & w2);

    ~Worker(){}
};

class FullTimeDeveloper : virtual public worker{
    protected:
    string teamName;
    int performanceBonus;
    int yearsExperiance;

    public:
    FullTimeDeveloper(int id, string name, int pay,string Tname,int bonus, int experiance){
        workerID = id;
        workerName = name;
        basePay = pay;
        teamName = Tname;
        performanceBonus = bonus;
        yearsExperiance= experiance;
    }
    int computePay() override{
        return basePay+performanceBonus;
    }
     void showDetails() override {
        cout << "--- Full Time Developer ---" << endl;
        cout << "ID: " << workerID << endl;
        cout << "Name: " << workerName << endl;
        cout << "Team: " << teamName << endl;
        cout << "Years Experience: " << yearsExperience << endl;
        cout << "Total Pay: " << computePay() << endl;
    }
    ~FullTimeDeveloper(){}
};

class FreelanceDeveloper : virtual public Worker {
private:
    int projectCount;
    int ratePerProject;

public:
    FreelanceDeveloper(int id, string name, int base,
                       int projects, int rate) {
        workerID = id;
        workerName = name;
        basePay = base;
        projectCount = projects;
        ratePerProject = rate;
    }
    int computePay() override {
        return projectCount * ratePerProject;
    }
    void showDetails() override {
        cout << "--- Freelance Developer ---" << endl;
        cout << "ID: " << workerID << endl;
        cout << "Name: " << workerName << endl;
        cout << "Projects: " << projectCount << endl;
        cout << "Rate/Project: " << ratePerProject << endl;
        cout << "Total Pay: " << computePay() << endl;
    }

    ~FreelanceDeveloper() {}
};
class TechnicalLead : public FullTimeDeveloper, public FreelanceDeveloper {
private:
    int leadershipAllowance;

public:
    TechnicalLead(int id, string name, int base,
                  string team, int bonus, int years,
                  int projects, int rate, int allowance)
    : Worker(id, name, base),                        // virtual base directly initialize karo
      FullTimeDeveloper(id, name, base, team, bonus, years),
      FreelanceDeveloper(id, name, base, projects, rate),
      leadershipAllowance(allowance) {}

    int computePay() override {
        return basePay + performanceBonus + 
               (projectCount * ratePerProject) + 
               leadershipAllowance;
    }

    void showDetails() override {
        cout << "--- Technical Lead ---" << endl;
        cout << "ID: " << workerID << endl;
        cout << "Name: " << workerName << endl;
        cout << "Team: " << teamName << endl;
        cout << "Years Experience: " << yearsExperience << endl;
        cout << "Projects: " << projectCount << endl;
        cout << "Leadership Allowance: " << leadershipAllowance << endl;
        cout << "Total Pay: " << computePay() << endl;
    }

    ~TechnicalLead() {}
};
int main() {
    Worker* workers[3];

    workers[0] = new FullTimeDeveloper(1, "Ali", 50000, 
                                        "Backend", 10000, 3);

    workers[1] = new FreelanceDeveloper(2, "Sara", 0, 
                                         5, 8000);

    workers[2] = new TechnicalLead(3, "Ahmed", 60000, 
                                    "Core", 15000, 5, 
                                    3, 7000, 20000);

  
    cout << "========== All Workers ==========" << endl;
    for(int i = 0; i < 3; i++) {
        workers[i]->showDetails();        // runtime polymorphism
        cout << "Pay: " << workers[i]->computePay() << endl;
        cout << "---------------------------------" << endl;
    }

    cout << "\n========== Pay Combination ==========" << endl;

    int combined = *workers[0] + *workers[1];
    cout << "Ali + Sara combined pay: " << combined << endl;

    combined = *workers[0] + *workers[2];
    cout << "Ali + Ahmed combined pay: " << combined << endl;

    for(int i = 0; i < 3; i++) {
        delete workers[i];
    }

    return 0;
}