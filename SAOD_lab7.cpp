#include <iostream>
#include <vector>

//Имеется n монет, среди которых одна фальшивая (легче или тяжелее других монет).
// Дополнительно дается одна настоящая.
//Имеются весы, с помощью которых можно сравнить различные
//группы монет.Разработать алгоритм и программу, позволяющую при
//минимальном числе сравнений определить фальшивую монету(если она есть) .

using namespace std;

// Функция для определения фальшивой монеты
int findFakeCoin(vector<int>& coins, int left, int right) {
    if (left == right) // Если осталась одна монета, то это фальшивая
        return left;

    if (left + 1 == right) { // Если остались две монеты, сравниваем их
        cout << "Сравните монеты " << left + 1 << " и " << right + 1 << " (нумерация с 1): ";
        int weight;
        cin >> weight;

        if (weight == -1) return left; // Первая монета легче
        else if (weight == 1) return right; // Вторая монета легче
        else return -1; // Монеты равны
    }

    int mid = (left + right) / 2;

    // Разделяем монеты на две группы
    int leftGroupStart = left;
    int leftGroupEnd = mid;
    int rightGroupStart = mid + 1;
    int rightGroupEnd = right;
    int weight; 

    // Сравниваем веса двух групп
    do {
        cout << "Сравните группы монет " << leftGroupStart + 1 << "-" << leftGroupEnd + 1 << " и "
            << rightGroupStart + 1 << "-" << rightGroupEnd + 1 << " (нумерация с 1, введите 1 - правая группа или 2 - левая группа): ";
        cin >> weight;

        if (weight != 1 && weight != 2) {
            cout << "Неверный ввод! Пожалуйста, введите 1 или 2.\n";
        }
    } while (weight != 1 && weight != 2);

    if (weight == -1) // Левая группа легче
        return findFakeCoin(coins, leftGroupStart, leftGroupEnd);
    else if (weight == 1) // Правая группа легче
        return findFakeCoin(coins, rightGroupStart, rightGroupEnd);
    else // Монеты равны, фальшивая в дополнительной настоящей монете
        return -1;
}

int main() {

    system("chcp 1251");
    int n; // Количество монет
    cout << "Введите количество монет: ";
    cin >> n;

    vector<int> coins(n + 1); // Создаем вектор для монет (индексация с 1)
    for (int i = 1; i <= n; ++i)
        coins[i] = i;

    // Выводим содержимое вектора монет
    cout << "Содержимое вектора монет: ";
    for (int i = 1; i <= n; ++i)
        cout << coins[i] << " ";

    cout << endl; // Переход на новую строку после вывода всех монет

    int fakeCoinIndex = findFakeCoin(coins, 1, n);

    if (fakeCoinIndex == -1)
        cout << "Фальшивой монеты нет.\n";
    else
        cout << "Фальшивая монета под индексом " << fakeCoinIndex + 1 << " (нумерация с 1).\n";

    return 0;
}
