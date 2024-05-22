#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "astar.h"

int main() {
    // Генерация карты
    system("./Gen_file");

    // Инициализация начальной и конечной точек
    Point start = {0, 0};
    Point goal = {10, 10};

    // Запуск алгоритма A*
    aStarSearch(start, goal);

    return 0;
}
