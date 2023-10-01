/*
Rảnh rỗi, Tí đang ngồi chơi Pokemon Go, một game đã không còn mấy thịnh hành. Vì
vậy, bắt pokemon dễ như ăn kẹo. Tí bắt được rất nhiều con pokemon và đầu tư mua
được một số ít viên đá tiến hóa. Tuy nhiên, mỗi loại đá chỉ dùng được cho một
loại pokemon. Với một con pokemon chủng P[i], Tí cần dùng K[i] viên đá để tiến
hóa cho nó. Sau khi tiến hóa xong, Tí sẽ thu lại được thêm 2 viên đá nữa.

Không có việc gì làm nên Tí cho đống pokemon của mình tiến hóa hết một lượt. Các
bạn hãy tính xem Tí có thể tiến hóa được bao nhiêu con, và loại pokemon nào được
tiến hóa nhiều nhất?

Input

Dòng đầu tiên là N (N ≤ ≤ 70), số lượng loại pokemon mà Tí bắt được. Giả sử rằng
Tí có vô hạn các con pokemon trong mỗi loại.

2N dòng tiếp theo, mỗi dòng gồm một xâu P[i], là loại pokemon mà Tí có. Tiếp
theo là 2 số nguyên K[i] (10 ≤ K[i] ≤ 400) và M[i] (1 ≤ M[i] ≤ 10 000), lần lượt
là số lượng viên đá cần để tiến hóa cho một con pokemon loại P[i], và số lượng
viên đá loại i mà Tí có.

Output
Dòng đầu tiên in ra tổng số lượng các con pokemon được tiến hóa.

Dòng thứ hai in ra loại pokemon nào được tiến hóa nhiều nhất. Nếu có nhiều đáp
án, hãy in ra tên loại pokemon xuất hiện sớm hơn trong danh sách.

Test ví dụ:
Input:
5
Pidgey
12 36
Ivysaur
10 63
Charmander
35 96
Pikachu
12 32
Squirtle
15 10

Output:
15
Ivysaur
*/

#include <stdio.h>

typedef struct {
	char name[50];
	unsigned level;
} pokemon;

int main() {
	unsigned pokemons, i, max_level = 0;
	scanf("%u", &pokemons);
	pokemon p[pokemons];
	unsigned long upgraded = 0;
	char *pokemons_highest_level;
	for (i = 0; i < pokemons; i++) {
		p[i].level = 0;
		scanf("%49[^\n]", p[i].name);
		unsigned gem_required, gems;
		scanf("%u %u", &gem_required, &gems);
		while (gems >= gem_required) {
			p[i].level++;
			gems -= gem_required - 2;
		};
		if (p[i].level > max_level) {
			max_level = p[i].level;
			pokemons_highest_level = p[i].name;
		};
		upgraded += p[i].level;
	};
	printf("%lu\n%s\n", //
	       upgraded, pokemons_highest_level);
	return 0;
}
