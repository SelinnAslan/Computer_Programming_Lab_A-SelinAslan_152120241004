#include <iostream>
#include <string>

using namespace std;

struct Package {
    string packageID;
    string destinationCity;
    int dimensions[3];
    Package* next;
};
struct Courier {
    string courierName;
    string vehicleType;
};
Package* stackTop = nullptr;

const int QUEUE_SIZE = 5;
Courier courierQueue[QUEUE_SIZE];
int front = -1;
int rear = -1;

void pushPackage(string id, string city, int l, int w, int h) {
    Package* newPackage = new Package();
    newPackage->packageID = id;
    newPackage->destinationCity = city;
    newPackage->dimensions[0] = l;
    newPackage->dimensions[1] = w;
    newPackage->dimensions[2] = h;

    newPackage->next = stackTop;
    stackTop = newPackage;
    cout << "Paket eklendi: " << id << endl;
}
void popPackage() {
    if (stackTop == nullptr) return;

    Package* temp = stackTop;
    stackTop = stackTop->next;
    delete temp;
}
bool isQueueFull() {
    return (front == (rear + 1) % QUEUE_SIZE);
}

bool isQueueEmpty() {
    return (front == -1);
}

void enqueueCourier(string name, string vehicle) {
    if (isQueueFull()) {
        cout << "Kurye sirasi dolu!" << endl;
        return;
     }
    if (front == -1) front = 0;

    rear = (rear + 1) % QUEUE_SIZE;
    courierQueue[rear].courierName = name;
    courierQueue[rear].vehicleType = vehicle;
    cout << "Kurye kayit edildi: " << name << endl;
}
void dequeueCourier() {
    if (isQueueEmpty()) return;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % QUEUE_SIZE;
    }
}
void dispatch() {
    if (stackTop == nullptr) {
        cout << "Hata: Gonderilecek paket yok!" << endl;
        return;
    }
    if (isQueueEmpty()) {
        cout << "Hata: Bekleyen kurye yok!" << endl;
        return;
    }
   cout << ">>> DISPATCH: " << courierQueue[front].courierName << " adli kurye "
         << stackTop->packageID << " nolu paketi aldi." << endl;

    popPackage();
    dequeueCourier();
} void display() {
    cout << "\n--- MEVCUT DURUM ---" << endl;


    cout << "PAKET STACK'I:" << endl;
    Package* temp = stackTop;
    if (temp == nullptr) cout << " (Bos)" << endl;
    while (temp != nullptr) {
        cout << "[" << temp->packageID << " - " << temp->destinationCity << "] -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    cout << "KURYE SIRASI:" << endl;
    if (isQueueEmpty()) {
        cout << " (Bos)" << endl;
    } else {
        int i = front;
        while (true) {
            cout << "[" << courierQueue[i].courierName << " (" << courierQueue[i].vehicleType << ")] ";
            if (i == rear) break;
            i = (i + 1) % QUEUE_SIZE;
        }
        cout << endl;
    }
    cout << "--------------------" << endl;
}int main() {

    pushPackage("P001", "eskisehir", 10, 20, 30);
    pushPackage("P002", "balikesir", 15, 15, 15);

    enqueueCourier("selin", "Motosiklet");
    enqueueCourier("zeynep", "Kamyonet");

    display();

    dispatch();

    display();

    return 0;
}
