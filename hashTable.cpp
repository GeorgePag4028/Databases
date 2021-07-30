#include <iostream>

using namespace std;
/* HashTable :
	-- array based hash table 
	   with hash function h(k)=integet %size--
*/
class hashTable{
	public:
		hashTable(int size){
			tableSize =size;
			table = new int(size);
			for(int i=0;i<size;i++){
				*(table+i) =0;
			}
		}

		void print(){
			for (int i=0;i<tableSize;i++){
				cout<<"HashTable["<<i<<"]:"<<*(table+i)<<endl;
			}
		}

		void add(int item){
			*(table+item%tableSize)=item;
		}
	private:
		int tableSize;
		int *table;
};
int main(){
	hashTable h(5);
	h.print();
	cout<<endl;
	h.add(1);
	h.add(2);
	h.print();
	cout<<endl;
	h.add(6);
	h.print();
}
