class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<60> b(n);

        return b.count() == 1;
    }
};

//解説
//nを2進数に変換
//2の乗数であれば、1になっているのは一桁だけのはず
//1->00000001
//2->00000010
//4->00000100