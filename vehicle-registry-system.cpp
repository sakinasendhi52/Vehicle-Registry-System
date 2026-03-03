// Vehicle Registry System

//header file
#include<iostream>
#include<cstring>
using namespace std;

//base class
class Vehicle{
    private:
        int vehicleId, year;
        char manufacturer[50],model[50],fuelType[30],batteryCapacity[10],topSpeed[10],flightRange[20],type[15];
        

    public:
        static int totalVehicles;    //static variable declaration
        //constructor
        Vehicle(){
            vehicleId=0;
            strcpy(manufacturer,"");
            strcpy(model,"");
            year=0;
            strcpy(fuelType,"");
            strcpy(batteryCapacity,"");
            strcpy(topSpeed,"");
            strcpy(flightRange,"");
            strcpy(type,"");
        }

        //getters and setters
        void setVehicle(){
            cout<<"ENTER VEHICLE ID : ";
            cin>>vehicleId;
            cout<<"ENTER MANUFACTURER : ";
            cin.ignore();
            cin.getline(manufacturer,50);
            cout<<"ENTER MODEL : ";
            cin.getline(model,50);
            cout<<"ENTER YEAR : ";
            cin>>year;
            cin.ignore();
        }

        void setFuelType(const char* fuelType){
            strcpy(this->fuelType,fuelType);
        }
        void setBatteryCapacity(const char* batteryCapacity){
            strcpy(this->batteryCapacity,batteryCapacity);
        }
        void setTopSpeed(const char* topSpeed){
            strcpy(this->topSpeed,topSpeed);
        }
        void setFlightRange(const char* flightRange){
            strcpy(this->flightRange,flightRange);
        }
        void setType(const char* type){
            strcpy(this->type,type);
        }
        void getVehicle(){
            cout<<"ID                : "<<vehicleId<<endl;
            cout<<"Manufacturer      : "<<manufacturer<<endl;
            cout<<"Model             : "<<model<<endl;
            cout<<"Year              : "<<year<<endl;
        }
        void getElectricCar(){
            getVehicle();
            cout<<"Fuel Type         : "<<fuelType<<endl;
            cout<<"Battery Capacity  : "<<batteryCapacity<<endl;
        }
        void getSportsCar(){
            getElectricCar();
            cout<<"Top Speed         : "<<topSpeed<<endl;
        }
        void getSedan(){
            getVehicle();
            cout<<"Fuel Type         : "<<fuelType<<endl;
        }
        void getSUV(){
            getVehicle();
            cout<<"Fuel Type         : "<<fuelType<<endl;
        }
        void getFlyingCar(){
            getVehicle();
            cout<<"Fuel Type         : "<<fuelType<<endl;
            cout<<"Flight Range      : "<<flightRange<<endl;
        }
        int getVehicleId(){
            return vehicleId;
        }
        string getType(){
            return type;
        }
        //destructor
        virtual ~Vehicle(){}
};

//derived classes
class Car : virtual public Vehicle{              //Single Inheritance from Vehicle
    public:
        void addCar(){
            char fuelType[30];
            cout<<"ENTER FUEL TYPE : ";
            cin.getline(fuelType,30);
            setFuelType(fuelType);
        }
};
class ElectricCar : public Car{              //Multilevel Inheritance from Car
    public:
        void addElectricCar(){
            char batteryCapacity[10];
            addCar();
            cout<<"ENTER BATTERY CAPACITY : ";
            cin.getline(batteryCapacity,10);
            setBatteryCapacity(batteryCapacity);
            setType("Electric Car");
        }
};
class Aircraft : virtual public Vehicle{              //Base Class for Multiple Inheritance 
    public :
        void addFlightRange(){
            char flightRange[20];
            cout<<"ENTER FLIGHT RANGE : ";
            cin.getline(flightRange,20);
            setFlightRange(flightRange);
        }
};
class FlyingCar : public Car, public Aircraft{             //Multiple Inheritance from Car and Aircraft
    public:
        void addFlyingCar(){
            addCar();
            addFlightRange();
            setType("Flying Car");
        }
}; 
class SportsCar : public ElectricCar{                     //Multilevel Inheritance from ElectricCar
    public:
        void addSportsCar(){
            char topSpeed[10];
            addElectricCar();
            cout<<"ENTER TOP SPEED : ";
            cin.getline(topSpeed,10);
            setTopSpeed(topSpeed);
            setType("Sports Car");
        }
};
class Sedan : public Car{                    //Hierarchical Inheritance from Car
    public:
        void addSedan(){
            addCar();
            setType("Sedan");
        }  
};
class SUV : public Car{                    //Hierarchical Inheritance from Car
    public:    
        void addSUV(){
            addCar();
            setType("SUV");
        }
};
class VehicleRegistry{
    private:
        Vehicle vehicles[100];               //Manages an array of Vehicle objects

    public:
        //Methods for adding, displaying, and searching vehicles

        //add vehicle
        void addVehicle(){
            int choice=0;
            if(Vehicle::totalVehicles>=100){
                cout<<endl<<"================== DATA CANNOT BE INSERTED =================="<<endl<<endl;
            }
            else{
                cout<<endl<<"========================= ADD DATA =========================="<<endl<<endl;
                cout<<"------------------------ TYPES OF CAR -----------------------"<<endl;
                cout<<"1. Electric Car     2. Sports Car"<<endl;
                cout<<"3. Sedan Car        4. SUV"<<endl;
                cout<<"       5. Flying Car"<<endl;
                cout<<"Which car you want to add ? "<<endl;
                cin>>choice;
                cin.ignore();
                switch(choice){
                    case 1:{
                        ElectricCar e;
                        e.setVehicle();
                        e.addElectricCar();
                        vehicles[Vehicle::totalVehicles] = e;
                        Vehicle::totalVehicles++;
                        cout<<"----------------------- CAR DATA ADDED ----------------------"<<endl<<endl;
                        break;
                    }
                    
                    case 2:{
                        SportsCar s;
                        s.setVehicle();
                        s.addSportsCar();
                        vehicles[Vehicle::totalVehicles] = s;
                        Vehicle::totalVehicles++;
                        cout<<"----------------------- CAR DATA ADDED ----------------------"<<endl<<endl;
                        break;
                    }

                    case 3:{
                        Sedan s;
                        s.setVehicle();
                        s.addSedan();
                        vehicles[Vehicle::totalVehicles] = s;
                        Vehicle::totalVehicles++;
                        cout<<"----------------------- CAR DATA ADDED ----------------------"<<endl<<endl;
                        break;
                    }
            
                    case 4:{
                        SUV s;
                        s.setVehicle();
                        s.addSUV();
                        vehicles[Vehicle::totalVehicles] = s;
                        Vehicle::totalVehicles++;
                        cout<<"----------------------- CAR DATA ADDED ----------------------"<<endl<<endl;
                        break;
                    }

                    case 5:{
                        FlyingCar f;
                        f.setVehicle();
                        f.addFlyingCar();
                        vehicles[Vehicle::totalVehicles] = f;
                        Vehicle::totalVehicles++;
                        cout<<"----------------------- CAR DATA ADDED ----------------------"<<endl<<endl;
                        break;
                    }

                    default:
                        cout<<endl<<"----------------------- INVALID CHOICE ----------------------"<<endl<<endl;
                        break;
                }
            }
        }

        //display all vehicle
        void displayVehicle(){
            if(Vehicle::totalVehicles==0){
                cout<<endl<<"==================== NO DATA TO DISPLAY ====================="<<endl<<endl;
            }
            else{
                cout<<endl<<"===================== DISPLAY ALL DATA ======================"<<endl<<endl;
                for(int i=0; i<Vehicle::totalVehicles; i++){
                    cout<<endl<<"------------------------ CAR DATA "<<i+1<<" ------------------------"<<endl<<endl;
                    if(vehicles[i].getType()=="Electric Car"){
                        cout<<"    | ELECTRIC CAR |"<<endl;
                        vehicles[i].getElectricCar();
                    }
                    else if(vehicles[i].getType()=="Sports Car"){
                        cout<<"    | SPORTS CAR |"<<endl;
                        vehicles[i].getSportsCar();
                    }
                    else if(vehicles[i].getType()=="Sedan"){
                        cout<<"    | SEDAN |"<<endl;
                        vehicles[i].getSedan();
                    }
                    else if(vehicles[i].getType()=="SUV"){
                        cout<<"   | SUV |"<<endl;
                        vehicles[i].getSUV();
                    }
                    else if(vehicles[i].getType()=="Flying Car"){
                        cout<<"    | FLYING CAR |"<<endl;
                        vehicles[i].getFlyingCar();
                    }

                    cout<<endl<<"------------------------------------------------------------"<<endl;
                }
            }
        }
        
        //search vehicle by ID
        void searchVehicle(int id){
            int match=0;
            for(int i=0; i<Vehicle::totalVehicles; i++){
                if(vehicles[i].getVehicleId()==id){
                    match=1;
                    cout<<endl<<"----------------------- CAR "<<id<<" DATA -----------------------"<<endl<<endl;
                    if(vehicles[i].getType()=="Electric Car"){
                        cout<<"    | ELECTRIC CAR |"<<endl;
                        vehicles[i].getElectricCar();
                    }
                    else if(vehicles[i].getType()=="Sports Car"){
                        cout<<"    | SPORTS CAR |"<<endl;
                        vehicles[i].getSportsCar();
                    }
                    else if(vehicles[i].getType()=="Sedan"){
                        cout<<"    | SEDAN |"<<endl;
                        vehicles[i].getSedan();
                    }
                    else if(vehicles[i].getType()=="SUV"){
                        cout<<"   | SUV |"<<endl;
                        vehicles[i].getSUV();
                    }
                    else if(vehicles[i].getType()=="Flying Car"){
                        cout<<"    | FLYING CAR |"<<endl;
                        vehicles[i].getFlyingCar();
                    }
                    cout<<endl<<"------------------------------------------------------------"<<endl<<endl;
                }
                
            }
            if(match==0){
                cout<<endl<<"------------------------------------------------------------"<<endl;
                cout<<endl<<"------------------ NO DATA FOUND WITH "<<id<<" ID ---------------"<<endl<<endl;
            }
        }
};

int Vehicle::totalVehicles=0;    //static variable initialization

//main function
int main(){
    int choice=0;
    VehicleRegistry manage;    //object

    //heading
    cout<<"============================================================="<<endl;
    cout<<"------------------ VEHICLE REGISTRY SYSTEM ------------------"<<endl;
    cout<<"============================================================="<<endl<<endl;

    //do while loop for menu
    do{
        cout<<"--------------- VEHICLE REGISTRY SYSTEM MENU ----------------"<<endl;
        cout<<"1 . ADD A VEHICLE"<<endl;
        cout<<"2 . DISPLAY ALL VEHICLE"<<endl;
        cout<<"3 . SEARCH VEHICLE BY ID"<<endl;
        cout<<"4 . EXIT"<<endl<<endl;

        cout<<"ENTER YOUR CHOICE : ";
        cin>>choice;

        switch(choice){
            case 1:
                //add vehicle 
                manage.addVehicle();
                break;

            case 2:
                //display vehicle
                manage.displayVehicle();
                break;

            case 3:
                //search car by ID
                int id;
                cout<<endl<<"===================== SEARCH CAR BY ID ======================"<<endl<<endl;
                cout<<"ENTER CAR ID : ";
                cin>>id;
                manage.searchVehicle(id);
                break;
            
            case 4:
                //exit
                cout<<endl<<"------------------------- THANK YOU -------------------------";
                break;

            default:
                //default
                cout<<endl<<"----------------------- INVALID CHOICE -----------------------"<<endl<<endl;
                break;
        }
    }
    while(choice!=4);

    return 0;
}