#include <iostream>
using namespace std

class dominoBone {
public:
	int leftSide;
	int rightSide;
	void putOnTheBoard(dominoBone bone, dominoBone &rightBone, dominoBone &leftBone, int locationOnBoard) {
		if (locationOnBoard == 0) {
			if (bone.rightSide == rightBone.leftSide) {
				rightBone.leftSide = bone.leftSide;
				rightBone.rightSide = bone.rightSide;
			}
			else {
				rightBone.rightSide = bone.leftSide;
				rightBone.leftSide = bone.rightSide;
			}
		}
		else {
			if (bone.rightSide == leftBone.leftSide) {
				leftBone.leftSide = bone.leftSide;
				leftBone.rightSide = bone.rightSide;
			}
			else {
				leftBone.rightSide = bone.leftSide;
				leftBone.leftSide = bone.rightSide;
			}
		}
	}
};

int main()
{
	dominoBone left = { 3, 2 };
	dominoBone right = { 5, 3 };
	return 0;
}
