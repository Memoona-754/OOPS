#include<iostream>
using namespace std;

class Medicine{
    protected:
    string name;
    int price;

    public:
    Medicine(string n, int p){
        name = n;
        price = p;
    }
    virtual void displayDetails() = 0;
    virtual ~Medicine(){}
};

class PrescriptionMedicine : virtual public Medicine {
    public:
    string docName;
    string patientName;
    int prescriptionDate;
       
    PrescriptionMedicine(string n, int p, string dN, string pN, int pD)
        : Medicine(n, p),         
          docName(dN), 
          patientName(pN),        
          prescriptionDate(pD){}

    void displayDetails() override{
        cout << "The name of Medicine is: " << name << endl;
        cout << "The price is: "            << price << endl;
        cout << "The doctor is: "           << docName << endl;
        cout << "The patient is: "          << patientName << endl;
        cout << "The prescription date is " << prescriptionDate << endl;
    }
    virtual ~PrescriptionMedicine(){}
};

class OTCMedicine : virtual public Medicine {
    public:
    int maxDailyDosage;
    int ageRestriction;
       
    OTCMedicine(string n, int p, int maxD, int ageR)
        : Medicine(n, p), 
          maxDailyDosage(maxD), 
          ageRestriction(ageR){}

    void displayDetails() override{
        cout << "The name of Medicine is: " << name << endl;
        cout << "The price is: "            << price << endl;
        cout << "The max dosage is: "       << maxDailyDosage << endl;
        cout << "The restricted age is "    << ageRestriction << endl;
    }
    virtual ~OTCMedicine(){}
};

class HybridMedicine : public PrescriptionMedicine, public OTCMedicine{
    public:
    HybridMedicine(string n, int p, string dN, string pN, int pD, int maxD, int ageR)
        : Medicine(n, p),
          PrescriptionMedicine(n, p, dN, pN, pD),
          OTCMedicine(n, p, maxD, ageR){}

    void displayDetails() override{
        cout << "The name of Medicine is: " << name << endl;
        cout << "The price is: "            << price << endl;
        cout << "The doctor is: "           << docName << endl;
        cout << "The patient is: "          << patientName << endl;
        cout << "The prescription date is " << prescriptionDate << endl;
        cout << "The max dosage is: "       << maxDailyDosage << endl;
        cout << "The restricted age is "    << ageRestriction << endl;
    }
    virtual ~HybridMedicine(){}
};

int main(){
    Medicine* M[3];

    M[0] = new PrescriptionMedicine("Panadol",   40, "Ali",  "Alia", 2);
    M[1] = new OTCMedicine         ("Bruffen",   30, 4, 5);
    M[2] = new HybridMedicine      ("Gravinate", 60, "Zara", "Sana", 3, 4, 6);

    for(int i = 0; i < 3; i++){
        M[i]->displayDetails();   
        cout << "-------------------" << endl;
    }

    for(int i = 0; i < 3; i++){
        delete M[i];
    }

    return 0;
}