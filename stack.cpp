/*This is a stack implemented with linked list in mind*/

/*
	methods 
		push(T item); O(1)
		pop(); O(1)
		peek(); O(1)
		isEmpty(); O(1)
		size(); O(1)
*/

#include <iostream>

using namespace std;

template <typename T>
class stack{
public:

		struct Node{
				T data;
				Node *next;
			};

		stack(){
			len = 0;
			head = NULL;
		}
		void push(T item){
			Node *tmp = new Node;
			tmp->data = item;
			tmp->next = head;
			head = tmp;
			len++;
		}
		
		T pop(){
			T item = head->data;
		 	head = head->next	;
			len--;
			return item;
		} 

		int size(){return len;}
		bool isEmpty(){
			if(len ==0) return true;
			return false;
		}
		T peek(){
			if(head!=NULL) 
				return head->data;
			else 
				cerr<<"Stack empty, can't peek"<<endl;
			return -1;
		}



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
	Node *head;
};
int main(){
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.print();
	cout<<"Size:"<<s.size()<<endl;
	cout<<"Peek:"<<s.peek()<<endl;
	cout<<"Empty:"<<s.isEmpty()<<endl;
	
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;

	cout<<"Size:"<<s.size()<<endl;
	cout<<"Peek:"<<s.peek()<<endl;
	cout<<"Empty:"<<s.isEmpty()<<endl;
}
