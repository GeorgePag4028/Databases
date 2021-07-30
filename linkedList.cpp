#include <iostream>

using namespace std;
//This is a LinkedList 
/*Methods : 
		append(<typename T> item); O(1)
		print(void); O(N)
		getHead(void); O(1)
		getTail(void);	O(1)
		deleteFirst(void); O(1)
		deleteLast(void); O(N)
		deleteIndex(int index); O(index)
		findIdex(int index);	O(index)
		findItem(<typename T> item); O(N) - find the first occurance of the item 
		replaceIndex(int index); O(index)
		replaceItem(<typename T> item); O(N) - replace the first occurance of the item
		reverse(void); O(N)
		size(void); O(N)
	*/
template <typename T>
class LinkedList{
	public:
		struct Node{
			 T data;
			 Node* next;
		};

		LinkedList(){
			head = NULL;
			tail = NULL;
		}

		void append(T item){
			Node *tmp = new Node;
			tmp->data =item;
			tmp->next =NULL;

			if (head == NULL){
				head = tmp ;
				tail = tmp;
			}
			else {
				tail-> next = tmp;
				tail=tail->next;
			}
		}

	void print(){
		if(head == NULL) cout<<"empty"<<endl;
		else{
			Node *tmp = head;
			cout<<"[";
			cout<<tmp->data;
			while(tmp->next != NULL){
				tmp = tmp->next;
				cout<<","<<tmp->data;
			}
			cout <<"]"<<endl;
		}
	}
	int size(){
		if(head == NULL) return 0;
		int counter =1;
		Node *tmp = head;
		while(tmp->next != NULL){
			tmp = tmp->next;
			counter++;
		} 

		return counter;
	}
	//check head==NULL
	T getHead(){
		return head->data;
	}
	T getTail(){
		return tail->data;
	}

	T deleteFirst(){
		T item = head->data;
		head = head->next;

		return item;
	}
	T deleteLast(){
		Node *tmp = head;
		while(tmp->next->next !=NULL) tmp = tmp->next;
		T item = tmp->next->data;
		tmp->next = NULL;
		tail = tmp;
		return item;
	}
	T deleteIndex(int index){
		Node *tmp = head;
		for(int i=0;i<index-1;i++){
			tmp = tmp->next;
		}
		T item = tmp->next->data;
		tmp->next = tmp->next->next;
		return item;
	}
	T findIndex(int index){
		Node *tmp=head;
		for(int i =0;i<index;i++){
			tmp = tmp->next;
		}
		return tmp->data;
	}

	void replaceIndex(int index,T value){
		Node *tmp = head;
		for(int i=0;i<index;i++){
			tmp = tmp->next;
		}
		tmp->data = value;
	}

	int findItem(T item){
		Node *tmp=head;
		int counter =0;
		while(tmp!=NULL){
			if (tmp->data == item) return counter;
			counter++;
			tmp = tmp->next;
		}
		return -1;
	}
	void replaceItem(T item,T value){
		Node *tmp=head;
		while(tmp != NULL){
			if(tmp->data == item){
				tmp->data = value;
				break;
			}
			tmp=tmp->next;
		}
		if(tmp==NULL) 
		{
			cerr<<"Error: on replaceItem"<<endl;
			cerr<<"This item:'"<<item<<"' is not on the list"<<endl;
			}
	}

	void reverse(){
		Node* current = head;
		Node *prev = NULL;
		Node *next = NULL;
		tail = head;
		while(current != NULL){
			next = current->next;
			current->next = prev;

			prev = current;
			current = next;
		}

		head = prev;

	}
	private: 
		Node *head,*tail; 
		
};
int main (){
	LinkedList <char> ll;
	ll.print();
	ll.append('a');
	ll.append('b');
	ll.print();
	ll.append('v');
	ll.print();
	cout<<ll.getHead()<<endl;
	cout<<ll.getTail()<<endl;
	cout<<ll.deleteFirst()<<endl;
	ll.print();
	cout<<ll.deleteLast()<<endl;
	ll.print();
	cout<<ll.deleteFirst()<<endl;
	ll.print();
	ll.append('a');
	ll.append('b');
	ll.append('c');
	ll.print();
	cout<<ll.findIndex(1)<<endl;
	cout<<ll.findIndex(2)<<endl;
	cout<<ll.findIndex(0)<<endl;
 	cout<<ll.size()<<endl;
	cout<<ll.findItem('b')<<endl;
	cout<<ll.findItem('a')<<endl;
	cout<<ll.findItem('B')<<endl;
	cout <<ll.deleteIndex(1)<<endl;
	ll.print();
	cout<<ll.size()<<endl;
	ll.replaceIndex(1,'r');
	ll.print();
	ll.replaceItem('a','t');
	ll.print();
	ll.replaceItem('y','i');
	ll.print();
	ll.reverse();
	ll.print();
	return 0;
}
