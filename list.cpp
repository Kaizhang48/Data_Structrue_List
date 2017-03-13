//written by Kai Zhang

#include"iostream"
using std::cout; using std::cin; using std::endl;
class node {
public:
	node() = default;
	int content;
	node* pnext;
};
void freemry(node *);

int main() {
	int input;
	cout << "enter the first number: " << endl;
	cin >> input;
	node*head;
	head = new node;
	head->content = input;
	head->pnext = nullptr;
	node* temp;
	node* tail;
	tail = head;
	while (input!=-9){
		cin >> input;
		if (input == -9) {
			break;
		}
	    temp = new node;
		temp->content = input;
		temp->pnext = nullptr;
		tail->pnext = temp;
		tail = temp;
	}
	
	int flag = 0;
	int target;
	cout << "enter a integer that you want ot find: " << endl;
	cin >> target;
	auto runner = head;
	while (runner != nullptr) {
		if (runner->content == target && flag==0) {
			flag = 1;
			runner = runner->pnext;
			continue;
		}
		cout << runner->content<<" ";
		runner = runner->pnext;
	}
	cout << endl;
	freemry(head);
	return 0;
	
}
void freemry(node *runner) {
	if (runner != nullptr) {
		freemry((*runner).pnext);
		delete runner;
	}
}