/*
Tuyến đường ven biển của thành phố Highland có N chiếc đèn. Không may cơn bão vừa rồi đã làm hỏng B
chiếc đèn.

Để khắc phục sự cố và nhanh chóng khôi phục lại hoạt động du lịch, chính quyền thành phố đã quyết
định sửa tạm thời một số đèn đường bị hỏng sao cho có ít nhất một khu vực có K chiếc đèn liên tiếp
hoạt động.

Các bạn hãy xác định xem số đèn đường cần phải sữa chữa ít nhất là bao nhiêu?

Input
Dòng đầu tiên gồm 3 số nguyên dương N, K và B (1 ≤ B, K ≤ N ≤ 100 000).
B dòng tiếp theo, mỗi dòng chứa vị trí của một chiếc đèn bị hỏng.

Output
In ra số đèn đường cần sửa ít nhất sao cho có một khu vực có nhiều hơn hoặc bằng K chiếc đèn hoạt
động.

Ví dụ:
Input:
10 6 5
2
10
1
5
9

Output:
1
*/

#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	u64 num_lights;
	std::cin >> num_lights;
	std::vector<bool> light(num_lights, true);

	u64 continuous, broken;
	std::cin >> continuous >> broken;

	while (broken--) {

		u64 pos;
		std::cin >> pos;

		light[pos - 1] = false;
	}

	std::vector<u64> vec;
	for (const bool not_broken : light) {

		static u64 sum = 0;

		if (!not_broken) {
			++sum;
		}

		vec.push_back(sum);
	}

	u64 result = std::numeric_limits<u64>::max();
	for (u64 i = continuous; i < num_lights; ++i)
		result = std::min(result, vec[i] - vec[i - continuous]);

	std::cout << result << std::endl;

	return 0;
}
