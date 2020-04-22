#include<iostream>
using namespace std;

class Duoxiang
{
protected:
	double xishu;
	int zhishu;

public:
	//Duoxiang(Duoxiang &r):zhishu(r.get_zhishu),xishu(r.get_xishu){}
	Duoxiang * Next = NULL;
	Duoxiang() { zhishu = 0; xishu = 0; }
	Duoxiang(double a, int n) { xishu = a; zhishu = n; }
	int get_zhishu(void) { return zhishu; }
	double get_xishu(void) { return xishu; }
};

class Shi
{
protected:
	Duoxiang *head;
	Duoxiang *end;
public:
	Duoxiang * Gethead()
	{
		return head;
	}
	Duoxiang *Getend()
	{
		return end;
	}
	Shi() { head = new Duoxiang; end = head; }
	friend istream & operator >> (istream &out, Shi &l);
	friend Shi* operator + (const Shi &a, const Shi &b);
	friend Shi* operator - (const Shi &a, const Shi &b);
	friend ostream & operator << (ostream &out, Shi &l);
};

/*
write by 王波 2020/4/22
多项式相加函数
返回结果多项式的 Shi*
*/
istream & operator >> (istream &in, Shi &l)
{
	int x, z; char c; Duoxiang*p;
	while (1)
	{
		in >> x >> z; c = getchar();
		p = new Duoxiang(x, z);
		l.end->Next = p;
		l.end = p;
		if (c == '\n')break;
	}
	return in;
}

Shi* operator + (const Shi &a, const Shi &b)
{
	Shi * result = new Shi;
	Duoxiang *p = NULL, *q = NULL, *temp = NULL, *r = result->head;
	double sum;
	p = a.head;
	q = b.head;
	while (p&&q)
	{
		if (p->get_zhishu() == q->get_zhishu())
		{
			sum = p->get_xishu() + q->get_xishu();
			if (sum != 0)
			{
				temp = new Duoxiang(sum, p->get_zhishu());
				r = temp;
				r = r->Next;
				p = p->Next;
				q = q->Next;
			}
		}
		else
		{
			if (p->get_zhishu() < q->get_zhishu())
			{
				temp = new Duoxiang(*p);
				r = temp;
				r = r->Next;
				p = p->Next;
			}
			else
			{
				temp = new Duoxiang(*q);
				r = temp;
				r = r->Next;
				q = q->Next;
			}
		}

	}
	if (p == NULL&&q != NULL)
	{
		while (q != NULL)
		{
			temp = new Duoxiang(*q);
			q = q->Next;
			r = temp;
			r = r->Next;
		}
	}
	if (p != NULL&&q == NULL)
	{
		while (p != NULL)
		{
			temp = new Duoxiang(*p);
			p = p->Next;
			r = temp;
			r = r->Next;
		}
	}
	return result;
}
Shi* operator - (const Shi &a, const Shi &b)
{
	Shi * result = new Shi;
	Duoxiang *p = NULL, *q = NULL, *temp = NULL, *r = result->head;
	double sum;
	p = a.head;
	q = b.head;
	while (p&&q)
	{
		if (p->get_zhishu() == q->get_zhishu())
		{
			sum = p->get_xishu() - q->get_xishu();
			if (sum != 0)
			{
				temp = new Duoxiang(sum, p->get_zhishu());
				r = temp;
				result->end = r;
				r = r->Next;
				p = p->Next;
				q = q->Next;
			}
		}
		else
		{
			if (p->get_zhishu() < q->get_zhishu())
			{
				temp = new Duoxiang(*p);
				r = temp;
				result->end = r;
				r = r->Next;
				p = p->Next;
			}
			else
			{
				temp = new Duoxiang(*q);
				r = temp;
				result->end = r;
				r = r->Next;
				q = q->Next;
			}
		}

	}
	if (p == NULL&&q != NULL)
	{
		while (q != NULL)
		{
			temp = new Duoxiang(*q);
			q = q->Next;
			r = temp;
			result->end = r;
			r = r->Next;
		}
	}
	if (p != NULL&&q == NULL)
	{
		while (p != NULL)
		{
			temp = new Duoxiang(*p);
			p = p->Next;
			r = temp;
			result->end = r;
			r = r->Next;
		}
	}
	return result;
}
ostream & operator << (ostream &out, Shi &l)
{
	Duoxiang *p=l.head->Next;
	while(p)
	{
		if(p->get_zhishu==0)
		{
			out<<p->get_xishu();
		}
		else if(p->get_zhishu==1)
		{
			if(p->get_xishu()==1)
			{
				out<<"x";
			} 
			else
			{
				out<<p->get_xishu()<<"x";
			}
		}
		else
		{
			if(p->get_xishu()==1)
			{
				out<<"x"<<p->get_zhishu();
			} 
			else
			{
				out<<p->get_xishu()<<"x"<<p->get_zhishu();
			}
		}
		if(p->Next)
		{
			if(p->Next->get_xishu()>0) 
			{
				out<<"+";
			}
		}
		p=p->Next;
	}
	return out;
}
int main()
{
	return 0;
}
