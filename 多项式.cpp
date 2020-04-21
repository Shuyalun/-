#include<iostream>
using namespace std;

class Duoxiang
{
	protected:
		double xishu;
		int zhishu;
	
	public:
		Duoxiang(Duoxiang &r):zhishu(r.get_zhishu),xishu(r.get_xishu){}
		Duoxiang * Next = NULL;
		Duoxiang(double a, int n);
		int get_zhishu(void) { return zhishu; }
		double get_xishu(void) { return xishu; }
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
		friend Shi* operator + (const Shi &a, const Shi &b);
		friend Shi* operator - (const Shi &a, const Shi &b);
};
/*
	write by 王波 2020/4/20
	多项式相加函数
	返回结果多项式的 Shi*
	*/

Shi* operator + (const Shi &a, const Shi &b)
{
	Shi * result=new Shi;
	Duoxiang *p = NULL, *q = NULL, *temp = NULL, *r = result->head;
	double sum;
	p = a.Gethead;
	q = b.head;
	while (p&&q)
	{
		if (p->get_zhishu == q->get_zhishu)
		{
			sum = p->get_xishu + q->get_xishu;
			if (sum != 0)
			{
				temp = new Duoxiang(sum, p->get_zhishu);
				r = temp;
				r = r->Next;
				p = p->Next;
				q = q->Next;
			}
		}
		else
		{
			if (p->get_zhishu < q->get_zhishu)
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
	p = a.Gethead;
	q = b.head;
	while (p&&q)
	{
		if (p->get_zhishu == q->get_zhishu)
		{
			sum = p->get_xishu - q->get_xishu;
			if (sum != 0)
			{
				temp = new Duoxiang(sum, p->get_zhishu);
				r = temp;
				result->end = r;
				r = r->Next;
				p = p->Next;
				q = q->Next;
			}
		}
		else
		{
			if (p->get_zhishu < q->get_zhishu)
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
