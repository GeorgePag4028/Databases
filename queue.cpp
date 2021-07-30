/*This is a queue implemented with linked list in mind*/

/*
	methods 
	  enqueue(T item); O(1)
		dequeue(); O(1)
		peek(); O(1)
		size(); O(1)
*/

#include <iostream>

using namespace std;

template <typename T>
class queue{
public:

		struct Node{
				T data;
				Node *next;
			};

		queue(){
			len =0;
			head =NULL;
			tail =NULL;
		}

		void enqueue(T item){
		 	Node *tmp = new Node;
			tmp->data = item;
			tmp->next = NULL;

			if(head == NULL) {
				head = tmp;
				tail = tmp;
			}
			else {
				tail->next = tmp;
				tail = tmp;
			}
			len++;
		}
		
		T dequeue(){
			T item = head->data;
			head = head->next;
			len--;
			return item;
		}

		T peek(){return head->data;}
		int size(){return len;}

		void print(){
			if (head == NULL) cout<<"[]"<<endl;
			else {
				Node *tmp= head;	
				cout<<"[";
				cout<<tmp->data;
				while(tmp->next!=NULL){
					tmp = tmp->next;
					cout<<","<<tmp->data;
				}
				cout<<"]"<<endl;
			}
		}

private:
	int len;
	Node *head,*tail;
};
int main(){
	queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.print();
	q.enqueue(4);
	q.print();
	q.enqueue(5);
	q.print();
	cout<<q.dequeue()<<endl;
	q.print();
	cout<<q.dequeue()<<endl;
	q.print();
	cout<<q.dequeue()<<endl;
	cout<<"Size:"<<q.size()<<endl;
}
