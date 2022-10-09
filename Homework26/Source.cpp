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

// Задание 1
void show_movie(movies &M){
	cout << "Название фильма: " << M.title << endl;
	cout << "Год выхода фильма: " << M.year << endl;
	cout << "Жанр фильма: " << M.genre << endl;
	cout << "Продолжительность фильма в минутах: " << M.duration << endl;
	cout << "Цена за диск фильма: " << M.price << endl;
}

// Задание 2
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

// Задание 3
movies update_info(movies &M) {
	int l;
	cout << "Выберите, какую информацию о фильме необходимо обновить:\n1. Название;\n2. Год выхода;\n3. Жанр;\n4. Продолжительность;\n5. Цена за диск.\nВвод -> ";
	cin >> l;
	switch (l) {
	case 1: cout << "Введите новое название фильма: ";
		cin >> M.title; break;
	case 2: cout << "Введите новый год выхода фильма: ";
		cin >> M.year; break;
	case 3: cout << "Введите новый жанр фильма: ";
		cin >> M.genre; break;
	case 4: cout << "Введите новую продолжительность фильма: ";
		cin >> M.duration; break;
	case 5: cout << "Введите новую цену за диск фильма: ";
		cin >> M.price; break;
	default: cout << "Ошибка. Не та цифра" << endl;
	}
	cout << "Информация обновлена.\n\n";

	return M;
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	// Задание 1
	cout << "Задание 1.\n";
	movies Shawshenk{
		"The Shawshank Redemption", 1994, "Drama", 142, 399
	};
	show_movie( Shawshenk );
	cout << endl;

	// Задание 2
	cout << "Задание 2.\nФильм с самой высокой ценой за диск:\n\n";
	movies Interstellar{
		"Interstellar", 2014, "fantasy, drama, adventure", 169, 299
	};

	movies Gentlemen{
		"The Gentlemen" , 2019, "криминал, комедия, боевик", 113, 499
	};
	
	movies max = expensive(Shawshenk, Interstellar, Gentlemen);
	show_movie(max);
	cout << endl;

	// Задание 3
	cout << "Задание 3.\n";
	show_movie(Interstellar);
	cout << endl;
	update_info(Interstellar);
	cout << endl;
	show_movie(Interstellar);
	cout << endl;
	return 0;
}