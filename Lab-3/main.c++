#include <iostream>
using namespace std;

struct song{
    string title;
    string artist;
    int ratings[3];
    song* next;
    song* prev;
};
song* head=nullptr;
song* tail=nullptr;
song* current=nullptr;

void addsong(string title,string artist,int r1,int r2,int r3){
    song* newsong=new song;
    newsong->title=title;
    newsong->artist=artist;
    newsong->ratings[0]=r1;
    newsong->ratings[1]=r2;
    newsong->ratings[2]=r3;
    newsong->next=nullptr;
    newsong->prev=nullptr;

if(head==nullptr){
    head=tail=current=newsong;
}else{
    tail->next=newsong;
    newsong->prev=tail;
    tail=newsong;
}}
void nextsong(){
    if(current!=nullptr && current->next!=nullptr){
            current=current->next;
    }else{
        cout<< "no next song\n";
    }}

void prevsong(){
    if(current!=nullptr && current->prev !=nullptr){
            current=current->prev;
    }else{
        cout<< "no previous song\n";
    }}

void removecurrent(){
    if(current==nullptr){
            return;
    }
    song* temp=current;

    if(head==tail){
       head=tail=current=nullptr;
    }
    else if(current==head){
       head=head-> next;
       head->prev=nullptr;
       current=head;
    }
    else if(current==tail){
       tail=tail->prev;
    tail->next=nullptr;
    current=tail;
    }else{
        current->prev->next=current->next;
        current->next->prev=current->prev;
        current=current->next;
    }
    delete temp;
}

void display(){
    song* temp =head;
    cout<<"playlist";

     while (temp != nullptr) {
        if (temp == current)
            cout << "-> ";
            cout << temp->title << " - " << temp->artist << " | Ratings: ";

        for (int i = 0; i < 3; i++) {
            cout << temp->ratings[i] << " ";
        }
            cout << endl;
            temp = temp->next;
}}
int main() {

    addsong("let it happen", "tame impala", 8, 9, 7);
    addsong("saygimdan", "Bengu", 6, 7, 8);
    addsong("havaalani", "hande yener", 9, 9, 10);

    display();

    cout << "\nNext song:\n";
    nextsong();
    display();

    cout << "\nNext song:\n";
    nextsong();
    display();

    cout << "\nPrevious song:\n";
    prevsong();
    display();

    cout << "\nRemoving current song:\n";
    removecurrent();
    display();

    return 0;
}
