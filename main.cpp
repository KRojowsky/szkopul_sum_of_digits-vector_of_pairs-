#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> my_pair;

bool sort_sec(const my_pair & left, const my_pair & right)
{
	return left.second > right.second;
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int number_of_digits, digit;
	cin >> number_of_digits;
	
	vector <my_pair> V_P;
	
	for(int i = 1; i <= number_of_digits; ++i)
	{
		cin >> digit;
		V_P.push_back(make_pair(i, digit));
	}
	
	stable_sort(V_P.begin(), V_P.end(), sort_sec);
	
	cout << '\n';
	
	for(int i = number_of_digits - 1; i >= 0; --i)
	{
		cout << V_P[i].first << " " << V_P[i].second << '\n';
	}
	
	cout << '\n';
	
	int actu = V_P[number_of_digits - 1].first;
	int sum = 9;
	
	for(int i = number_of_digits - 2; i >= 0; --i)
	{
		if(((V_P[i].first != actu + 1) || (V_P[i].first != actu - 1)) 
		&& (V_P[i].second))
		{
			V_P[i].second = 9;
			sum += V_P[i].second;
		}
		
		else
		{
			sum += V_P[i].second;
		}
		
		actu = V_P[i].first;
	}
	
	cout << '\n';
	
	for(int i = number_of_digits - 1; i >= 0; --i)
	{
		cout << V_P[i].first << " " << V_P[i].second << '\n';
	}
	
	cout << '\n';
	
	cout << sum;
}
