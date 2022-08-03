#include <iostream>

int	main(void)
{
	int	a = 0; // 0以外の方がわかりやすいかも
	float	after_a;
	int	raw_bits = a * 256; // コンストラクタで初期化
	std::cout << "raw_bits: " << raw_bits << std::endl;

	++raw_bits; // aではなくraw_bitsを+1しているだけ->1/256を足してるだけ
	std::cout << "raw_bits: " << raw_bits << std::endl;
	after_a = (float)raw_bits / 256;
	std::cout << after_a << std::endl; // 0.00390625 = 1/256

	raw_bits++;
	std::cout << "raw_bits: " << raw_bits << std::endl;
	after_a = (float)raw_bits / 256;
	std::cout << after_a << std::endl; // 0.0781 = (1+1)/256
}
