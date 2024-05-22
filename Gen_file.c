#include <stdio.h>
#include <stdlib.h>

// Простая функция для генерации случайных чисел
unsigned int next = 1;

int my_rand() {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void my_srand(unsigned int seed) {
    next = seed;
}

int main() {
    int size, length, width, num_obstacles, seed;
    printf("Введите размер летательного аппарата (квадрат): ");
    scanf("%d", &size);
    printf("Введите размеры карты (длина и ширина): ");
    scanf("%d %d", &length, &width);
    printf("Введите количество препятствий: ");
    scanf("%d", &num_obstacles);
    printf("Введите начальное значение для генерации случайных чисел: ");
    scanf("%d", &seed);

    FILE *fp = fopen("map.txt", "w");
    if (!fp) {
        perror("Не удалось открыть файл");
        return 1;
    }

    my_srand(seed);
    for (int i = 0; i < num_obstacles; i++) {
        int x1 = my_rand() % width;
        int y1 = my_rand() % length;
        int x2 = my_rand() % width;
        int y2 = my_rand() % length;
        fprintf(fp, "%d %d %d %d\n", x1, y1, x2, y2);
    }

    fclose(fp);
    return 0;
}
