int main(){
     Medicine *M [3];

     M[0]= new PrescriptionMedicine("Panadol",40,"Ali","Alia", 2);
     M[1]= new OTCMedicine("bruffen",30,"Ahad","Sara",5);
     M[2]= new HybridMedicine("Gravinate",60,"Zara","Sana",3);

     for (int i=0;i<3;i++){
        Medicine->displayDetails();
     }
} 