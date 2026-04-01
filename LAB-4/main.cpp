#include <iostream>
#include <string>

using namespace std;

struct MoneyBundle{

string serialNumber;
string currentType; //tl usd
int billCounts[3]; //100 50 20
MoneyBundle* next;
};

MoneyBundle* top= NULL;

void push(string s,string c, int a, int b, int d){
 MoneyBundle* n = new MoneyBundle;
 n -> serialNumber = s;
 n -> currentType = c;
 n -> bills[0] = a;
 n -> bills[1] = b;
 n -> bills[2] = d;
 n -> text = top;
 top = n;

}

void displayMoney() {
    MoneyBundle* temp = top;
    while (temp != NULL) {
        cout << temp->serialNumber << " " << temp->currencyType << endl;
        temp = temp->next;
    }
}

struct customer {
string customerName;
string transactionType; // withdraw deposit

};

customer q[5];
int front =0 , count = 0, rear = -1;

void enqueue(string name, string type){
if (count == 5 ) return;
rear = (rear +1)%5;
q[rear].customerName=name;
q[rear].transactionType=type;
count++;
}

void dequeue() {
    if (count == 0) return;
    front = (front + 1) % 5;
    count--;
}

void displayQueue() {
int i = front;
    for (int c = 0; c < count; c++) {
        cout << q[i].customerName << " " << q[i].transactionType << endl;
        i = (i + 1) % 5;
    }
}


void pop() {
    if (top == NULL) return;
    MoneyBundle* temp = top;
    top = top->next;
    delete temp;
}


int main()
{
    push("S1","TL",5,7,3);
    push("S2","USD",4,8,9);

    enqueue("Nisa","Withdraw");
    enqueue("Faris","Deposit");

    cout<<"Before\n";
    displayMoney();
    displayQueue();

    if(count > 0 && top!= NULL){
        dequeue();
        pop();
    }

    cout<<"After";
    displayMoney();
    displayQueue();

    return 0;
}
