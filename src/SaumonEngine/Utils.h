#pragma once
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
};


