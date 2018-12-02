#pragma once

class PositionVector {
public:
	PositionVector();
	PositionVector(int X, int Y);

	int &X();
	int &Y();

	PositionVector operator+(const PositionVector V)const {
		
		return PositionVector(x + V.x, y + V.y);
	}
private:
	int x;
	int y;


};