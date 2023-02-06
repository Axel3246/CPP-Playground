// thread example
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <windows.h>
using namespace std;

void connectNode(){

    cout << "Connecting Node MCU's to Wifi Module" << endl;
    cout << endl;
}

void connectedNode(int x){

    for(int i=1; i<x; i++){
    cout << "Node MCU #" << i << " has succesfully connected to Wifi Module" << endl;
    cout << endl;
}
}

void temp_Sensor(){

    cout << "Obtaining data from temperature sensors" << endl;
    int randArray[10];
    
    for(int i=0;i<10;i++){
        randArray[i]=rand()%100;
    }

    cout << "Data obtained temperature sensors is: ";
    for(int i=0;i<10;i++){
        cout << randArray[i] << "C" << " ";
    }
    cout << endl;
}

void foto_Sensor(){
    cout << endl;
    cout << "Obtaining data from light sensors" << endl;
    int randArray[10];
    
    for(int i=0;i<10;i++){
        randArray[i]=rand()%50;
    }

    cout << "Data obtained light sensors is: ";
    for(int i=0;i<10;i++){
        cout << randArray[i] << "cd" << " ";
    }
    //cout << endl;
}

void ultrasonik_Sensor(){
    cout << endl;
    cout << "Obtaining data from Ultrasonic sensors" << endl;
    int randArray[10];
    
    for(int i=0;i<10;i++){
        randArray[i]=rand()%150;
    }

    cout << "Data obtained Ultrasonic sensors is: ";
    for(int i=0;i<10;i++){
        cout << randArray[i] << "m" << " ";
    }
    cout << endl;
}

void proximity_Sensor(){
    cout << endl;
    cout << "Obtaining data from Proximity sensors" << endl;
    int randArray[10];
    
    for(int i=0;i<10;i++){
        randArray[i]=rand()%65;
    }

    cout << "Data obtained Proximity sensors is: ";
    for(int i=0;i<10;i++){
        cout << randArray[i] << "mm" << " ";
    }
    cout << endl;
}

void button_Buzzer(){
    cout << endl;
    cout << "Obtaining data from button + buzzer actuators" << endl;
    int randArray[10];
    
    for(int i=0;i<10;i++){
        randArray[i]=rand()%2;
    }

    cout << "Data obtained is: ";
    for(int i=0;i<10;i++){
        cout << randArray[i] << " ";
    }
    cout << endl;

}

int main(){

    system("cls");

    thread connecting(connectNode);
    cout << endl;
    thread connected(connectedNode, 6);
    connecting.join(); 
    connected.join();

    Sleep(200);
    cout << "Obtaning data from Node MCUs connected sensors..." << endl;

    thread temperature(temp_Sensor);
    cout << endl;
    thread luminosidad(foto_Sensor); 
    cout << endl;
    temperature.join();
    cout << endl;
    luminosidad.join();
    
    Sleep(200);

    thread semaforo(ultrasonik_Sensor);
    thread estacionamiento(proximity_Sensor); 
    semaforo.join();
    cout << endl;
    estacionamiento.join();
    
    thread buzzer(button_Buzzer);
    buzzer.join();
    cout << endl;
}

