#include <iostream>
#include <vector>
using namespace std;

class El      /// Êëàññ óçëà äåðåâà
{
public:
	El();
	El(int val);

public:
	int data;
	El* parent;
	vector<El*> c_Vector;  ///Ìàññèâ "äåòåé" óçëà äåðåâà

};