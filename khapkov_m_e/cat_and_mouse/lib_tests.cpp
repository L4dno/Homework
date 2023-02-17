#include "geometry_vectors.h"
#include <iostream>
#include <cmath>

	void NormVec(Rdec2D& vec) {
		vec = vec / Norm(vec);
	}

	int TimeToCatch(const Rdec2D cat_pos, const Rdec2D mouse_pos, 
					const Rdec2D cat_speed, const Rdec2D mouse_speed,
					const double cat_range) {

		Rdec2D cat_dir = cat_pos;
		NormVec(cat_dir);
		Rdec2D mouse_dir = mouse_pos;
		NormVec(mouse_dir);

		int time = 0;

		//if (Norm(mouse_pos - cat_pos) < Norm(mouse_pos + mouse_speed -
		//	(cat_pos + cat_speed))) {
		//	return -1; //cant catch
		//}

		while (Norm(cat_pos - mouse_pos) > cat_range) {
			std::cout << cat_dir.x << " " << cat_dir.y << "\n";
			cat_dir = cat_dir + cat_speed;
			mouse_dir = mouse_dir + mouse_speed;
			time += 1;
		}

		return time;

	}

Rdec2D FindCatSpeed(const Rdec2D cat_pos, const Rdec2D mouse_pos, 
					const Rdec2D mouse_speed,
					const double cat_range) {

	Rdec2D l = mouse_speed;
	Rdec2D r = l;

	int meet_time = TimeToCatch(cat_pos, mouse_pos, r,
		mouse_speed, cat_range);
	Rdec2D mouse_cur_pos = { mouse_pos };

	//int sgsg = 0;
	while (meet_time == -1
		|| (mouse_cur_pos.y > 0)) {
		//++sgsg;
		r *= 2;
		meet_time = TimeToCatch(cat_pos, mouse_pos, r,
			mouse_speed, cat_range);
		mouse_cur_pos = mouse_pos + meet_time * mouse_speed;
		std::cout << meet_time << "\n";
		/*if (sgsg > 100)
			break;*/
	}

	Rdec2D m;
	for (int i = 0; i < 100; ++i) {
		std::cout << m.x << " "<<m.y << "\n";

		m = (l + r) / 2;
		meet_time = TimeToCatch(cat_pos, mouse_pos, m,
			mouse_speed, cat_range);
		mouse_cur_pos = mouse_pos + meet_time * mouse_speed;

		if (mouse_cur_pos.y >= 0) {
			l = m;
		}
		else {
			r = m;
		}

	}

	return l;

}


int main() {

	Rdec2D cat_pos, mouse_pos;

	std::cout << "Cat\n";
	std::cin >> cat_pos.x >> cat_pos.y;

	std::cout << "Mouse\n";
	std::cin >> mouse_pos.x >> mouse_pos.y;

	Rdec2D cat_speed, mouse_speed;

	//std::cout << "Cat speed\n";
	//std::cin >> mouse_speed.x >> mouse_speed.y;

	std::cout << "Mouse speed\n";
	std::cin >> cat_speed.x >> cat_speed.y;

	std::cout << "Cat paws length\n";

	double attack_range;
	std::cin >> attack_range;

	auto res = FindCatSpeed(cat_pos, mouse_pos,
		mouse_speed, attack_range);

	std::cout << Norm(res)/Norm(mouse_speed);

	return 0;
}