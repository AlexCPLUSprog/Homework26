#include <iostream>
#include <string>
using namespace std;

struct movies {
	string title = "empty";
	int year = 0;
	string genre = "empty";
	unsigned int duration = 0;
	unsigned int price = 0;
};

// ������� 1
void show_movie(movies &M){
	cout << "�������� ������: " << M.title << endl;
	cout << "��� ������ ������: " << M.year << endl;
	cout << "���� ������: " << M.genre << endl;
	cout << "����������������� ������ � �������: " << M.duration << endl;
	cout << "���� �� ���� ������: " << M.price << endl;
}

// ������� 2
movies expensive(movies& S, movies& L, movies &K) {
	movies max;
	if (S.price > L.price && S.price > K.price)
		max = S;
	else
		if (L.price > S.price && L.price > K.price)
			max = L;
		else
			if (K.price > S.price && K.price > L.price)
				max = K;
	
	return max;
}

// ������� 3
movies update_info(movies &M) {
	int l;
	cout << "��������, ����� ���������� � ������ ���������� ��������:\n1. ��������;\n2. ��� ������;\n3. ����;\n4. �����������������;\n5. ���� �� ����.\n���� -> ";
	cin >> l;
	switch (l) {
	case 1: cout << "������� ����� �������� ������: ";
		cin >> M.title; break;
	case 2: cout << "������� ����� ��� ������ ������: ";
		cin >> M.year; break;
	case 3: cout << "������� ����� ���� ������: ";
		cin >> M.genre; break;
	case 4: cout << "������� ����� ����������������� ������: ";
		cin >> M.duration; break;
	case 5: cout << "������� ����� ���� �� ���� ������: ";
		cin >> M.price; break;
	default: cout << "������. �� �� �����" << endl;
	}
	cout << "���������� ���������.\n\n";

	return M;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// ������� 1
	cout << "������� 1.\n";
	movies Shawshenk{
		"The Shawshank Redemption", 1994, "Drama", 142, 399
	};
	show_movie( Shawshenk );
	cout << endl;

	// ������� 2
	cout << "������� 2.\n����� � ����� ������� ����� �� ����:\n\n";
	movies Interstellar{
		"Interstellar", 2014, "fantasy, drama, adventure", 169, 299
	};

	movies Gentlemen{
		"The Gentlemen" , 2019, "��������, �������, ������", 113, 499
	};
	
	movies max = expensive(Shawshenk, Interstellar, Gentlemen);
	show_movie(max);
	cout << endl;

	// ������� 3
	cout << "������� 3.\n";
	show_movie(Interstellar);
	cout << endl;
	update_info(Interstellar);
	cout << endl;
	show_movie(Interstellar);
	cout << endl;
	return 0;
}