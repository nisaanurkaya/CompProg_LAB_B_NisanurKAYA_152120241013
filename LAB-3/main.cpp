#include <iostream>
#include <string>

using namespace std;

struct Page {

string url;
string title;

int accesstime[3];

Page* next;
Page* prev;

};

Page* head =nullptr;
Page* tail= nullptr;
Page* current= nullptr;

void visit(string url,string title,int h,int m,int s){
Page* newPage= new Page;
newPage->url = url;
newPage->title= title;
newPage->accesstime=h;
newPage->accesstime=m;
newPage->accesstime=s;
newPage->next=nullptr;
newPage->prev=nullptr;

}

if(head=NULL){

    head=tail=current=newPage;

}else{
    Page* temp=current->next;
    while(temp){
        Page* del= temp;
        temp= temp -> next;
        delete del;
    }
current->next=newPage;
newPage->current=prev;
tail=newPage;
current=newPage;
}

void goBack(){
if(current->prev){
    current=current->prev;
    cout << "Moved back to: " << current->title << endl;
}else{
cout << "No previous page" << endl;
    }
}

void goForward() {
    if (current->next) {
        current = current->next;
        cout << "Moved forward to: " << current->title << endl;
}else {
        cout << "No next page" << endl;
    }
}

void deleteCurrent() {
    if (!current) {
        cout << "No page to delete" << endl;
        return;
    }

Page* toDelete = current;
    if (current->prev) {
        current->prev->next = current->next;
    } else {
        head = current->next;
    }

if (current->next) {
        current->next->prev = current->prev;
        current = current->next; //
    } else {
        current = current->prev;
        tail = current;
    }
     delete toDelete;
    cout << "Page deleted" << endl;

}

void displayHistory(){
 Page* temp=head;

}




void cleanup() {
    Page* temp = head;
    while (temp) {
        Page* del = temp;
        temp = temp->next;
        delete del;
    }
    head = tail = current = nullptr;
    cout << "Memory cleaned. Exiting program" << endl;
}



int main()
{
    int choice;
    string url,title;
    int h,m,s;

    do{
        cout << "Browser History Manager\n";
        cout << "1 Visit Page\n 2 Back\n 3 Forward\n 4 Delete Current Page\n 5 Display History\n 6 Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
    }

     switch (choice) {
            case 1:
                cout << "Enter URL: "; cin >> url;
                cin.ignore();
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Access Time (HH MM SS): "; cin >> h >> m >> s;
                visit(url, title, h, m, s);
                break;
            case 2:
                goBack();
                break;
            case 3:
                goForward();
                break;
            case 4:
                deleteCurrent();
                break;
            case 5:
                displayHistory();
                break;
            case 6:
                cleanup();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 6);

    return 0;
}
