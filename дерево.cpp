#include "дерево.hpp"

//! Ðåàëèçàöèÿ ìåòîäîâ Êëàññà "Äåðåâî"
Tree::Tree()
{
	Root = new El;
}


El* Tree::Find_El(El* Elem,int Num) const
{
	El* temp = nullptr;
	if (Num)
		Num--;
	if( !Num ) return Elem;
	else
	{
		for(int itr = 0; itr < Elem->childVector.size(); itr++)
		{
			if(temp) break;
			temp =	Find_El(Elem->c_Vector[itr], Num);	
		}
	}
	return temp;
}

void Tree::Add_El(int Num, int Val)
{ 
	if (Num < 0) return;
	if (!Num) Root->data = Val;
	else 
	{
		El* leaf = new El(Val);

		leaf->parent = Find_El(Root, Num);
		leaf->parent->c_Vector.push_back(leaf);
	}
	return;
}

int Tree::Get_Data(int Num) const
{
	El* leaf = Find_El(Root, Num);
	return leaf->data;
}

void Tree::Print_Direct(El* Elem) const
{
	cout<<Elem->data<<endl;
	for(int itr = 0; itr < Elem->c_Vector.size(); itr++)
	{
		Print_Direct(Elem->c_Vector[itr]);	
	}
	return;
}

void Tree::Print_Reverse(El* Elem) const
{
	for(int itr = 0; itr < Elem->c_Vector.size(); itr++)
	{
		Print_Reverse(Elem->c_Vector[itr]);			
	}
	cout<<Elem->data<<endl;
	return;
}

void Tree::Print_Symmetrical(El* Elem) const
{

	for(int itr = 0; itr < Elem->c_Vector.size(); itr++)
	{
		Print_Symmetrical(Elem->c_Vector[itr]);
		if( !itr ) 
			cout<<Elem->data<<endl;
	}
	if ( !(Elem->c_Vector.size()) )
		cout<<Elem->data<<endl;
	return;
}
void Tree::Print_Tree() const
{
	cout<<"---------Direct  Bypass-----------"<<endl;
	Print_Direct(Root);
	cout<<"---------Reverse  Bypass-----------"<<endl;
	Print_Reverse(Root);
	cout<<"---------Symmetrical  Bypass-----------"<<endl;
	Print_Symmetrical(Root);
	return;
}

void Tree::Delete_Tree(El* Elem)
{
	for(int itr = 0; itr < Elem->c_Vector.size(); itr++)
	{
		Delete_Tree(Elem->c_Vector[itr]);
		delete Elem->c_Vector[itr];
	}
	return;
}

Tree::~Tree()
{
	Delete_Tree(Root);
	delete Root;
}