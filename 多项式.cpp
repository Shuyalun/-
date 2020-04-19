#include<iostream>
using namespace std;
class Duoxiang
{
	protected:
    		double xishu;
    		int zhishu;
    		Duoxiang * Next=null;
	public:
		Duoxiang(double a,int n);
};
class Shi
{
	protected:
		Duoxiang *head;
		Duoxiang *end;
	public:
		Duoxiang *Gethead()
		{
			return head;
		}
	  	Duoxiang *Getend()
		{
			return end;
		}
};
