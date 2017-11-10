#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<cstring>
using namespace std;

char A[100];
map<char, int> priority;

void calpri()
{
	char op[6] = { '+','-','*','/','(','#' };
	for (int i = 0; i<6; i++)
		switch (op[i])
		{
		case '#':
			priority[op[i]] = -1;
			break;
		case '+':
		case '-':
			priority[op[i]] = 1;
			break;
		case '*':
		case '/':
			priority[op[i]] = 2;
			break;
		case '(':
			priority[op[i]] = 0;
			break;
		default:
			break;
		}
	return;
}

char operate(char a, char op, char b)
{
	int A = a - '0', B = b - '0';
	switch (op)
	{
	case '+':return A + B + '0';
	case '-':return A - B + '0';
	case '*':return A*B + '0';
	case '/':return A / B + '0';
	}
}

char calcu()
{
	stack<char> OPR;
	stack<char> OPN;
	OPR.push('#');
	char c = A[0];
	for (int i = 0; c != '#' || OPR.top() != '#';)
	{

		if (c == ')')
		{
			while (OPR.top() != '(')
			{
				char a1 = OPN.top();
				OPN.pop();
				char a2 = OPN.top();
				OPN.pop();
				char op = OPR.top();
				OPR.pop();
				OPN.push(operate(a2, op, a1));
			}
			OPR.pop();
			c = A[++i];
			continue;
		}
		if ('0' <= c&&c <= '9')
		{
			OPN.push(c);
			c = A[++i];
			continue;
		}
		if (c == '(')
		{
			OPR.push(c);
			c = A[++i];
			continue;
		}
		else
		{
			if (priority[c] <= priority[OPR.top()] && OPN.size() >= 2)
			{
				char a1 = OPN.top();
				OPN.pop();
				char a2 = OPN.top();
				OPN.pop();
				char op = OPR.top();
				OPR.pop();
				OPN.push(operate(a2, op, a1));
			}
			else
			{
				OPR.push(c);
				c = A[++i];
			}
		}
	}
	return OPN.top();
}

int main()
{
	calpri();
	cin >> A;
	cout << "ans is " << calcu() << endl;
	return 0;
}
