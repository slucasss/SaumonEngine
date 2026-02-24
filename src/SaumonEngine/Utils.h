#pragma once
#include "math.h"

struct Vector2i {
	int x;
	int y;

	Vector2i operator+(Vector2i right) {
		return Vector2i{ x + right.x, y + right.y };
	}

	Vector2i operator-(Vector2i right) {
		return Vector2i{ x - right.x, y - right.y };
	}

	Vector2i operator*(int right) {
		return Vector2i{ x * right, y * right };
	}
	void operator +=(int right) {
		x += right;
		y += right;
	}

	float GetLenght() {
		return sqrt(x * x + y * y);
	}

	Vector2i normalize() {
		float lenght = GetLenght();

		Vector2i normalized{ x / lenght, y / lenght };
		return normalized;
	}
};

struct Vector2f {
	float x;
	float y;

	Vector2f operator+(Vector2f right) {
		return Vector2f{ x + right.x, y + right.y };
	}

	Vector2f operator-(Vector2f right) {
		return Vector2f{ x - right.x, y - right.y };
	}

	Vector2f operator*(float right) {
		return Vector2f{ x * right, y * right };
	}
	
	void operator+=(float right) {
		x += right;
		y += right;
	}

	float GetLenght() {
		return sqrt(x * x + y * y);
	}

	Vector2f normalize() {
		float lenght = GetLenght();

		Vector2f normalized{ x / lenght, y / lenght };
		return normalized;
	}
};


