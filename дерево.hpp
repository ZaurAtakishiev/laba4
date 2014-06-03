#include "элемент.hpp"

class Tree          /// Êëàññ "äåðåâî"
{
public:
	Tree();
	~Tree();
	void Add_El(int Num, int Val);  /// Ìåòîä äîáàâëåíèÿ óçëà ê äåðåâó	
	void Print_Tree()   const;
	int  Get_Data(int Num) const;

private:
	void Print_Direct(El* Elem) const;
	void Print_Reverse(El* Elem) const;
	void Print_Symmetrical(El* Elem) const;
	void Delete_Tree(El* Elem);
	El* Find_El(El* Elem,int Num) const;

private:
	El* Root;  /// óêàçàòåëü íà êîðåíü äåðåâà
};