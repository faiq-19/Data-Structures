// #include<iostream>
// #include<fstream>
// #include<vector>
// #include<sstream>
// using namespace std;

// int pos = 0;

// class Node
// {
// 	public:
// 		string Food_ID;
// 		string Deal_name;
// 		string description;
// 		int quantity;
// 		int price;
// 		int position;
// 		Node *left;
// 		Node *right;
		
// 		Node()
// 		{
// 			Food_ID = "";
// 			Deal_name = "";
// 			description = "";
// 			quantity = -1;
// 			price = 0;
// 			position = 0;
// 			left = NULL;
// 			right = NULL;
// 		}
		
// 		Node(int pos, string f_ID, string D_name, string desc, int qty, int price)
// 		{
// 			position = pos;
// 			Food_ID = f_ID;
// 			Deal_name = D_name;
// 			description = desc;
// 			quantity = qty;
// 			this->price = price;
// 			left = NULL;
// 			right = NULL;
// 		}
// };

// class BST
// {
// 	public:
// 		Node *root;
	
// 	void appendNode(string f_ID, string D_name, string desc, int qty, int price)
// 		{
// 			pos++;
// 			if(!root)
// 			{
// 				root = new Node(pos, f_ID, D_name, desc, qty, price);
// 				return;
// 			}
// 			Node *temp = root;
// 			Node *parent;
// 			int side=-1;
// 			while(temp != NULL)
// 			{
// 				parent = temp;
// 				if(D_name == temp->Deal_name)
// 				{
// 					temp->quantity++;
// 					pos--;
// 					return;
// 				}
// 				else if(pos >= temp->position)
// 				{
// 					side = 0;
// 					temp = temp->right;
// 				}
// 				else if(pos < temp->position)
// 				{
// 					side = 1;
// 					temp = temp->left;
// 				}
// 			}
			
// 			if(side == 0)
// 			{
// 				parent->right = new Node(pos, f_ID, D_name, desc, qty, price);
// 			}
// 			else if(side == 1)
// 			{
// 				parent->left = new Node(pos, f_ID, D_name, desc, qty, price);
// 			}
// 		}
		
// 		void deleter(int sno)
// 		{
// 			Node *temp = root;
// 			while(temp != NULL)
// 			{
// 				if(sno == temp->position)
// 				{
// 					temp->quantity = 0;
// 					return;
// 				}
// 				else if(sno > temp->position)
// 				{
// 					temp = temp->right;
// 				}
// 				else if(sno < temp->position)
// 				{
// 					temp = temp->left;
// 				}
// 			}		
// 		}
		
// 		void inorder(Node *n)
// 		{
// 			if(!n)
// 			{
// 				return;
// 			}
// 			inorder(n->left);
// 			cout << n->Food_ID << ") " << n->Deal_name << " " << n->quantity << "qty. " << n->price << "Rs" << endl;
// 			inorder(n->right);
// 		}
		
// 		void print()
// 		{
// 			if(!root)
// 			{
// 				cout << "NO TREE EXISTS!";
// 				return;
// 			}
// 			inorder(root);
// 		}
		
// 		void file_putter()
// 		{
// 			if(!root)
// 			{
// 				cout << "NO TREE EXISTS!";
// 				return;
// 			}
// 			fstream fout;
// 			fout.open("BUDGET_BITES.txt",ios::out);
// 			traverse(root,fout);
// 		}
		
// 		void traverse(Node *n,fstream &fout)
// 		{
// 			if(!n)
// 			{
// 				return;
// 			}
// 			traverse(n->left,fout);
// 			if(n->quantity!=0)
// 			{
// 				fout << n->Food_ID << ";" << n->Deal_name << ";" << n->description << ";" << n->quantity << ";" << n->price << "\n";
// 			}
// 			traverse(n->right,fout);
// 		}
// };

// BST tree;

// void file_reader()
// {
	
// 	fstream fin;
// 	fin.open("BUDGET_BITES.txt",ios::in);
// 	string line,word;
// 	int qty,price;
// 	vector<string> lost;
	
// 	while(getline(fin,line))
// 	{
// 		stringstream str(line);
// 		while(getline(str,word,';'))
// 		{
// 			// in the file, elements in a line are seperated with ';' thus this inner while loop extracts every element in the line.
// 			lost.push_back(word);
// 		}
		
// 		//you can use stringstream method to convert strings to integers
// 		stringstream s1,s2;
// 		s1 << lost[3];
// 		s1 >> qty;
// 		s2 << lost[4];
// 		s2 >> price;
// 		tree.appendNode(lost[0],lost[1],lost[2],qty,price);
// 		lost.clear();
// 	}
	
// 	fin.close();
// }

// void delete_Item()
// {
// 	tree.print();
// 	int sno;
// 	cout << "/n/nEnter position number of the deal you want to delete";
// 	cin >> sno;
// 	if (sno > pos or sno < 1)
// 	{
// 		cout << "\nSAHI WAALA OPTION DAALO!\n";
// 		delete_Item();
// 	} 
// 	else
// 	{
// 		tree.deleter(sno);
// 	}
// }

// void add_Item()
// {
// 	string f_id,d_name,desc;
// 	int qty,price;
	
// 	cout << "\nEnter Food ID: ";
// 	//tried to use getline here but it won't work idky
// 	cin >> f_id;
// 	fflush(stdin);
	
// 	cout << "Enter Deal Name: ";
// 	getline(cin,d_name);
// 	fflush(stdin);
	
// 	cout << "Enter Description: ";
// 	getline(cin,desc);
// 	fflush(stdin);
	
// 	cout << "Enter Quantity: ";
// 	cin >> qty;
// 	cout << "Enter Price: ";
// 	cin >> price;
// 	tree.appendNode(f_id,d_name,desc,qty,price);
// }

// int main()
// {
// 	file_reader();
// 	bool running = true;
// 	int choice = -1;
// 	int ans = 1;
// 	while(ans==1)
// 	{
// 		cout << "\n\nDo you want to add a new deal (press 1) or remove an existing one (press 0)? ";
// 		cin >> choice;
		
// 		if(choice < 0 or choice > 1)
// 		{
// 			cout << "\nSAHI WAALA OPTION DAALO!";
// 			continue;
// 		}
		
// 		switch(choice)
// 		{
// 			case 0:
// 				delete_Item();
// 				break;
			
// 			case 1:
// 				add_Item();
// 				break;
// 		}
		
// 		cout << "\n\n\t\tDo you want to perform another operation? (press 1 for yes, anything else for no)";
// 		cin >> ans;
// 	}
// 	tree.print();
// 	tree.file_putter();
// 	return 0;
// }

#include<iostream>
using namespace std;

int stack[50];
int start = -1;

void push(int value)
{
    if(start == 50)
    {
        cout << "Stack Overflow";
        return;
    }
    start++;
    stack[start] = value;
}

int pop()
{
    if(start == -1)
    {
        cout << "Stack Underflow";
        return 0;
    }
    start--;

    return stack[start];
}

void display()
{
    cout << endl;

    for(int i = 0; i <= start; i++)
    {
        cout << stack[i] << " ";
    }

    cout << endl;
}

int find_max_index(int n)
{
    int max_index = 0;

    for(int i = 0; i < n; i++)
    {
        if(stack[max_index] > stack[i])
        {
            max_index = i;
        }
    }
    return max_index;
}

void flipPancake(int n)
{
    for(int i = 0; i <= n / 2; i++)
    {
        swap(stack[i], stack[i-1]);
    }
}

void sort_pancake()
{
    for(int i = 0; i <= start; i++)
    {
        int max_index = find_max_index(i);
        
        flipPancake(max_index);

        flipPancake(i);
    }
}

int main()
{
    push(5);
    push(2);
    push(7);
    push(6);
    push(8);
    push(4);
    push(1);
    push(9);

    display();

    sort_pancake();

    display();
}