#include <iostream>
#include <string>

using namespace std;

struct Node {

string title;
Node* next;

};

Node* head =NULL;

void addSong(string song){

Node* newNode = new Node;
newNode->title = song;
newNode->next= head;
head = newNode;

}

void listSongs(){
if(head ==NULL){
    cout<< "Playlist is empty";
    return;

}
Node* temp= head;
int i=1;

while(temp != NULL){
    cout<< i<<temp->title<<endl;
    temp=temp->next;
    i++;

}
}

void searchSong(string song){

Node* temp=head;

while( temp != NULL){
    if(temp->title == song){
        cout<< "Song found in playlist";
        return;

    }
    temp= temp->next;
}

cout<< "Song not found";

}


int main()
{
   int choice;
   string song;

   do{
    cout<< "1. Add Song \n";
    cout<< "2. Search Song\n";
    cout<< "3. List Song\n";
    cout<< "4. Exit";
    cout<< "Choice.";
    cin>>choice;
    cin.ignore();

    switch(choice)
    {
    case 1:
        cout<< "Add song ";
        getline(cin,song);
        addSong(song);
        break;

    case 2:
        cout<< "Search song ";
        getline(cin,song);
        searchSong(song);
        break;

    case 3:
        listSongs();
        break;

    case 4:
        break;

    default:
        cout<< "Invalid choice";

    }while(choice != 4);
   }
   return 0;
}
